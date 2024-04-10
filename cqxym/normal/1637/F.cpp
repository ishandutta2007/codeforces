#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
#define I inline
#define N 200001
int hei[N],val[N];
vector<int>G[N],H[N];
I void DFS(int x,int F){
	for(int T:G[x]){
		if(T!=F){
			DFS(T,x);
			H[x].push_back(T);
			if(val[T]>val[x]){
				val[x]=val[T];
			}
			if(hei[T]>val[x]){
				val[x]=hei[T];
			}
		}
	}
}
int main(){
	int n,x,y,root=0;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",hei+i);
		if(hei[i]>hei[root]){
			root=i;
		}
	}
	for(R i=1;i!=n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS(root,0);
	long long ans=0;
	for(R i=1;i<=n;i++){
		if(i==root){
			int fm=0,sm=0;
			for(int T:G[i]){
				x=val[T];
				if(hei[T]>x){
					x=hei[T];
				}
				if(x>fm){
					sm=fm;
					fm=x;
				}else if(x>sm){
					sm=x;
				}
			}
			ans+=(hei[i]<<1)-fm-sm;
		}else if(G[i].size()==1){
			ans+=hei[i];
		}else if(hei[i]>val[i]){
			ans+=hei[i]-val[i];
		}
	}
	printf("%lld",ans);
	return 0;
}