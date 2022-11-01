#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define I inline
#define N 200001
int a[N],b[N],c[N],f[N],ct[2][N];
vector<int>G[N];
long long ans;
inline int Min(int x,int y){
	return x<y?x:y;
}
inline void DFS(int x,int F){
	f[x]=Min(f[F],a[x]);
	if(b[x]!=c[x]){
		ct[b[x]][x]=1;
	}
	for(vector<int>::iterator T=G[x].begin();T!=G[x].end();T++){
		if(*T!=F){
			DFS(*T,x);
			ct[0][x]+=ct[0][*T];
			ct[1][x]+=ct[1][*T];
		}
	}
	if(f[x]==a[x]){
		int tem=Min(ct[0][x],ct[1][x]);
		ans+=(long long)a[x]*tem;
		ct[0][x]-=tem;
		ct[1][x]-=tem;
	}
}
int main(){
	int n,x,y;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d%d%d",a+i,b+i,c+i);
	}
	f[0]=2e9;
	for(R i=1;i!=n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS(1,0);
	if((ct[0][1]|ct[1][1])!=0){
		printf("-1");
	}else{
		printf("%lld",ans<<1);
	}
	return 0;
}