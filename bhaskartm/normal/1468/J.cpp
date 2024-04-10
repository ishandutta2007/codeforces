#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=2e5+5;



int parent[200005];
int size[200005];
vector<vector<pair<int, int>>>adj;
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
bool pre[N];





int n, l;


int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector<vector<int>> maxi;
int d[N];

void dfs(int v, int p, int we, int h)
{
	d[v]=h;
	
    tin[v] = ++timer;
    up[v][0] = p;
    maxi[v][0]=we;
    for (int i = 1; i <= l; ++i){
        up[v][i] = up[up[v][i-1]][i-1];
        maxi[v][i]=max(maxi[v][i-1], maxi[up[v][i-1]][i-1]);
    }
    for (auto u : adj[v]) {
        if (u.f != p)
            dfs(u.f, v, u.s, h+1);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    l = ceil(log2(n+1));
    up.assign(n+1, vector<int>(l + 1));
    maxi.assign(n+1, vector<int>(l + 1));
    dfs(root, root, 0, 0);
}


int func(int v, int p){
	if(v==p){
		return 0;
	}
	int ans=0;
	int node=v;
	if(p==1){
		
		return maxi[v][l];
	}
	
	for(int i=l; i>=0; i--){
		if(d[up[node][i]]<d[p]){
			continue;
		}
		
		else{
			
			ans=max(ans, maxi[node][i]);
			node=up[node][i];
		}
	}
	return ans;
}





main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int m, k;
		cin>>n>>m>>k;
		vector<pair<pair<int, int>, pair<int, int>>>ed;
		maxi.clear();
		up.clear();
		tin.clear();
		tout.clear();
		timer=0;
		adj.clear();
		for(int i=0; i<=m; i++){
			pre[i]=0;
		}
		for(int i=0; i<m; i++){
			int x, y, w;
			cin>>x>>y>>w;
			int ww=w;
			if(w<=k){
				w=0;
			}
			else{
				w=w-k;
			}
			ed.pb({{w,ww}, {x, y}});
		}
		sort(ed.begin(), ed.end());
		for(int i=1; i<=n; i++){
			make_set(i);
		}
		adj.resize(n+1);
		int ans=0;
		for(int i=0; i<ed.size(); i++){
			if(find_set(ed[i].s.f)==find_set(ed[i].s.s)){
				continue;
			}
			else{
				pre[i]=1;
				union_sets(ed[i].s.f, ed[i].s.s);
				adj[ed[i].s.f].pb({ed[i].s.s, ed[i].f.f});
				adj[ed[i].s.s].pb({ed[i].s.f, ed[i].f.f});
				ans+=ed[i].f.f;
			}
		}
		preprocess(1);
		int mini=1e18;
		for(int i=0; i<ed.size(); i++){
			if(pre[i]){
				int w=ed[i].f.s;
				if(w>=k){
					mini=min(mini, ans);
				}
				else{
					mini=min(mini, ans+k-w);
				}
			}
			else{
				int u=ed[i].s.f;
				int v=ed[i].s.s;
				int lc=lca(u, v);
				int ww=max(func(u, lc), func(v, lc));
				mini=min(mini, ans-ww+abs(k-ed[i].f.s));
			}
		}
		cout<<mini<<endl;
	}
	return 0;
}