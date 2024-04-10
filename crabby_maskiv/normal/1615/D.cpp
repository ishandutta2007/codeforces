#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=4e5+5;
int n,m;
int fa[N];
int rt(int u){
	if(fa[u]==u) return u;
	return fa[u]=rt(fa[u]);
}
inline void merge(int u,int v){
	fa[rt(u)]=rt(v); 
}
int d[N];
int uu[N],vv[N],ww[N],par[N];
vector<int> g[N];
void dfs(int u){
	for(auto v:g[u]){
		if(par[u]==v) continue;
		par[v]=u;
		dfs(v);
		d[v]^=d[u];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		for(i=1;i<=n*2;i++) fa[i]=i;
		for(i=1;i<=n;i++){
			d[i]=uu[i]=vv[i]=ww[i]=par[i]=0;
			g[i].clear();
		}
		for(i=1;i<n;i++){
			int x,y,w;cin>>x>>y>>w;
			uu[i]=x;vv[i]=y;ww[i]=w;
			g[x].push_back(y);
			g[y].push_back(x);
			if(w==-1) continue;
			if(__builtin_popcount(w)&1){
				merge(x,y+n);
				merge(x+n,y);
			}
			else{
				merge(x,y);
				merge(x+n,y+n);
			}
		}
		for(i=1;i<=m;i++){
			int x,y,w;cin>>x>>y>>w;
			if(w){
				merge(x,y+n);
				merge(x+n,y);
			}
			else{
				merge(x,y);
				merge(x+n,y+n);
			}
		}
		int f=1;
		for(i=1;i<=n;i++){
			if(rt(i)==rt(i+n)) f=0;
		}
		cout<<(f?"YES":"NO")<<endl;
		if(f){
			for(i=1;i<=n;i++){
				if(rt(i)<=n) d[i]=0;
				else d[i]=1;
			}
			dfs(1);
			for(i=1;i<n;i++){
				cout<<uu[i]<<" "<<vv[i]<<" ";
				if(vv[i]==par[uu[i]]) swap(uu[i],vv[i]);
				if(ww[i]==-1) cout<<d[vv[i]]<<endl;
				else cout<<ww[i]<<endl;
			}
		}
	}
	return 0;
}