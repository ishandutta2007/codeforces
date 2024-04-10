#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
#define R register int
#define N 500001
struct Edge{
	int End,Len;
};
vector<Edge>G[N];
vector<int>C[N];
stack<int>S[N];
int sz[N],f[N],tot[N];
inline void DFS(int x,int F){
	sz[x]=1;
	for(Edge T:G[x]){
		int y=T.End,c=T.Len;
		if(y!=F){
			f[y]=S[c].top();
			C[c].push_back(y);
			S[c].push(y);
			DFS(y,x);
			sz[x]+=sz[y];
			S[c].pop();
		}
	}
}
int main(){
	int n,x,y,z;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		S[i].push(1);
		tot[i]=n;
	}
	for(R i=1;i!=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		G[x].push_back({y,z});
		G[y].push_back({x,z});
	}
	DFS(1,0);
	for(R i=1;i<=n;i++){
		for(int T:C[i]){
			if(f[T]==1){
				tot[i]-=sz[T];
			}else{
				sz[f[T]]-=sz[T];
			}
		}
	}
	long long ans=0;
	for(R i=1;i<=n;i++){
		for(int T:C[i]){
			ans+=(long long)sz[T]*(f[T]==1?tot[i]:sz[f[T]]);
		}
	}
	printf("%lld",ans);
	return 0;
}