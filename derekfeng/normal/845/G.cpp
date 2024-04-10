#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
int p[30];
void add(int x){
	for(int i=29;i>=0;i--)if((1ll<<i)&x){
		if(!p[i]){
			p[i]=x;
			break;
		}
		x^=p[i];
	}
}
int n,m;
vector<pii>g[100004];
int d[100004];
bool ins[100004],vis[100004];
void dfs(int x,int p){
	vis[x]=ins[x]=1;
	for(auto y:g[x])if(y.fi!=p){
		if(ins[y.fi])add(d[x]^d[y.fi]^y.se);
		else if(!vis[y.fi])d[y.fi]=d[x]^y.se,dfs(y.fi,x);
	}
	ins[x]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v,D;scanf("%d%d%d",&u,&v,&D);
		g[u].push_back(mkp(v,D)),g[v].push_back(mkp(u,D));
	}
	dfs(1,0);
	int ans=d[n];
	for(int i=29;i>=0;i--)if((ans^p[i])<ans)ans^=p[i];
	printf("%d",ans);
}