#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef double db;
#define fi first
#define se second
int n,w[200004],N;
int sz[200004];
vector<pii>g[200004];
bool used[200004];
db d[200004],S;
int ans1;
db res,ans2=-1;
void dfs(int x,int fa){
	sz[x]=1;
	for(auto y:g[x])if(y.fi!=fa&&!used[y.fi])
		dfs(y.fi,x),sz[x]+=sz[y.fi];
}
int findroot(int x,int fa){
	int cnt=N-sz[x];
	for(auto y:g[x])if(y.fi!=fa&&!used[y.fi]){
		int tmp=findroot(y.fi,x);
		if(tmp!=-1)return tmp;
		cnt=max(cnt,sz[y.fi]);
	}
	if(cnt<=N/2)return x;
	return -1;
}
void getdao(int x,int fa,db z,int id){
	d[id]+=pow(z,0.5)*w[x];
	res+=pow(z,1.5)*w[x];
	for(auto y:g[x])if(y.fi!=fa)getdao(y.fi,x,z+y.se,id);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1;i<n;i++){
		int u,v,a;scanf("%d%d%d",&u,&v,&a);
		g[u].push_back({v,a}),g[v].push_back({u,a});
	}
	int x=1;
	for(;;){
		dfs(x,0),N=sz[x],x=findroot(x,0);
		S=res=0;
		for(auto y:g[x]){
			d[y.fi]=0;
			getdao(y.fi,x,y.se,y.fi);
			S+=d[y.fi];
		}
		if(ans2<0||ans2>res)ans1=x,ans2=res;
		bool nxt=0;
		used[x]=1;
		for(auto y:g[x])if(!used[y.fi]){
			db v=S-2*d[y.fi];
			if(v<0){
				x=y.fi,nxt=1;
				break;
			}
		}
		if(!nxt)break;
	}
	printf("%d %.8lf",ans1,ans2);
}