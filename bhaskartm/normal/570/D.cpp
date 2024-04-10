#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
vector<vector<int>>t;
vector<vector<int>>depth;
vector<vector<int>>adj;
const int N=500001;
int val[N];
int sz[N];
int d[N];
int ind[N];
int bi[N];
int maxi=0;

int du=0;

void dfs1(int v, int p, int h){
	
	d[v]=h;
	maxi=max(maxi, h);
	sz[v]=1;
	ind[v]=du;
	bi[du]=v;
	du++;
	for(auto u:adj[v]){
		if(u!=p){
			dfs1(u, v, h+1);
			sz[v]+=sz[u];
		}
	}
}

void dfs2(int v, int p){
	depth[d[v]].pb(ind[v]);
	for(auto u:adj[v]){
		if(u!=p){
			dfs2(u, v);
		}
	}
}


void build(int v, int tl, int tr, int dep) {
    if (tl == tr) {
        t[dep][v] = val[bi[depth[dep][tl]]];
        
    } else {
        int tm = (tl + tr) / 2;
        build( v*2, tl, tm, dep);
        build( v*2+1, tm+1, tr, dep);
        t[dep][v] = (t[dep][v*2]^t[dep][v*2+1]);
        
    }
}

int xori(int v, int tl, int tr, int l, int r, int dep) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[dep][v];
    }
    int tm = (tl + tr) / 2;
    return ((xori(v*2, tl, tm, l, min(r, tm), dep))^(xori(v*2+1, tm+1, tr, max(l, tm+1), r, dep)));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	adj.resize(n+1);
	string s;
	
	for(int i=2; i<=n; i++){
		int x;
		cin>>x;
		adj[i].pb(x);
		adj[x].pb(i);
	}
	cin>>s;
	for(int i=0; i<n; i++){
		val[i+1]=(1<<(int(s[i]-'a')));
	}
	
	dfs1(1, 0, 1);
	
	depth.resize(maxi+1);
	
	
	dfs2(1, 0);
	
	t.resize(maxi+1);
	for(int i=1; i<=maxi; i++){
		t[i].resize(4*(depth[i].size()-1)+2);
	}
	
	for(int i=1; i<=maxi; i++){
		build(1, 0, depth[i].size()-1, i);
	}
	
	while(m--){
		int v, h;
		cin>>v>>h;
		if(d[v]>=h || h>maxi || depth[h][depth[h].size()-1]<ind[v] || depth[h][0]>ind[v]+sz[v]-1){
			cout<<"Yes"<<endl;
			continue;
		}
		
		
		int lower=lower_bound(depth[h].begin(), depth[h].end(), ind[v])-depth[h].begin();
		auto it=lower_bound(depth[h].begin(), depth[h].end(), ind[v]+sz[v]);
		it--;
		int upper=it-depth[h].begin();
		if(lower==upper){
			cout<<"Yes"<<endl;
			continue;
		}
		int value=xori(1, 0, depth[h].size()-1, lower, upper, h);
		
		if(__builtin_popcount(value)<=1){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}