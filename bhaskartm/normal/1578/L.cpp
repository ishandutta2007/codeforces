#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define f first
#define s second
#define pb push_back
#define endl '\n'

const int N=2e5+5;

int n, l;
vector<vector<int>> adj;
vector<vector<int>> comp;


int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector<int>dep;


void dfs(int v, int p, int d)
{
    tin[v] = ++timer;
    up[v][0] = p;
    dep[v]=d;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v, d+1);
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

int dist(int u, int v){
	int lc=lca(u, v);
	return dep[u]+dep[v]-2*dep[lc];
}

void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    dep.resize(n+1);
    
    timer = 0;
    l = ceil(log2(n));
    up.assign(n+1, vector<int>(l + 1));
    dfs(root, root, 0);
}
 
int src[N];
int spe[N];


pair<int, int>dis[N];
bool pro[N];



 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	adj.resize(n+1);
	comp.resize(n+1);
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	preprocess(1);
	
	int q;
	cin>>q;
	
	
	while(q--){
		int k, m;
		cin>>k>>m;
		vector<pair<int, int>>inf;
		for(int i=0; i<k; i++){
			int v, sp;
			cin>>v>>sp;
			inf.pb({v, sp});
			src[i+1]=v;
			spe[i+1]=sp;
		}
		vector<int>tar;
		for(int i=0; i<m; i++){
			int v;
			cin>>v;
			tar.pb(v);
		}
		vector<pair<int, int>>vecs;
		for(auto u:tar){
			vecs.pb({tin[u], u});
		}
		for(auto u:inf){
			vecs.pb({tin[u.f], u.f});
		}
		sort(vecs.begin(), vecs.end());
		set<int>se;
		for(auto u:vecs){
			se.insert(u.s);
		}
		int sz=vecs.size();
		for(int i=0; i<sz-1; i++){
			int lc=lca(vecs[i].s, vecs[i+1].s);
			se.insert(lc);
		}
		vector<pair<int, int>>ne;
		for(auto u:se){
			ne.pb({tin[u], u});
			dis[u]={1e9, 0};
			pro[u]=0;
		}
		sort(ne.begin(), ne.end());
		stack<int>st;
		
		for(int i=0; i<ne.size(); i++){
			int v=ne[i].s;
			while(!st.empty() && !is_ancestor(st.top(), v)){
				st.pop();
			}
			if(!st.empty()){
				comp[st.top()].pb(v);
				comp[v].pb(st.top());
			}
			st.push(v);
		}
		priority_queue<pair<pair<int, int>, int>>pq;
		for(int i=0; i<inf.size(); i++){
			dis[inf[i].f]={0, i+1};
			pq.push({{0, -i-1}, inf[i].f});
		}
		while(!pq.empty()){
			auto u=pq.top();
			pq.pop();
			if(pro[u.s]){
				continue;
			}
			pro[u.s]=1;
			int d1=-u.f.f;
			int ind=-u.f.s;
			int v=u.s;
			for(auto uu:comp[v]){
				int d2=dist(src[ind], uu);
				int d22=d2/spe[ind];
				if(d2%spe[ind]!=0LL){
					d22++;
				}
				if(d22<dis[uu].f || (d22==dis[uu].f && ind<dis[uu].s)){
					dis[uu]={d22, ind};
					pq.push({{-d22, -ind}, uu});
				}
			}
		}
		for(auto u:tar){
			cout<<dis[u].s<<" ";
		}
		cout<<endl;
		for(auto u:se){
			comp[u].clear();
		}
	}
	
	return 0;
}