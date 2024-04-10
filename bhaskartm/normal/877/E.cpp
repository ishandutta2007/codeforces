#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define int long long int
int arr[200005];
vector<vector<int>>adj;
vector<int>eu;
int ind[200005];
int sz[200005];
pair<int, int>t[800020];
int lazy[800020];

void push(int v) {
	if(lazy[v]==1){
    t[v*2]={t[2*v].s, t[2*v].f};
    lazy[v*2]=1-lazy[2*v];
    t[v*2+1]={t[2*v+1].s, t[2*v+1].f};
    lazy[v*2+1]=1-lazy[2*v+1];
    lazy[v] = 0;
	}
}


void update(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] ={t[v].s, t[v].f};
        lazy[v]=1-lazy[v];
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm));
        update(v*2+1, tm+1, tr, max(l, tm+1), r);
        t[v] = {t[2*v].f+t[2*v+1].f, t[2*v].s+t[2*v+1].s};
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return {0, 0};
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    auto t1=query(v*2, tl, tm, l, min(r, tm));
    auto t2=query(v*2+1, tm+1, tr, max(l, tm+1), r);
    return {t1.f+t2.f, t1.s+t2.s};
}

void build( int v, int tl, int tr) {
    if (tl == tr) {
        if(eu[tl]==1){
        	t[v]={1, 0};
        }
        else{
        	t[v]={0 ,1};
        }
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build( v*2+1, tm+1, tr);
        t[v] = {t[2*v].f+t[2*v+1].f, t[2*v].s+t[2*v+1].s};
    }
}

void dfs(int v, int p){
	sz[v]=1;
	ind[v]=eu.size();
	eu.pb(v);
	for(auto u:adj[v]){
		if(u!=p){
			dfs(u, v);
			sz[v]+=sz[u];
		}
	}
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	adj.resize(n+1);
	for(int i=2; i<=n; i++){
		int x;
		cin>>x;
		adj[x].pb(i);
		adj[i].pb(x);
	}
	dfs(1 ,0);
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		eu[ind[i]]=arr[i];
	}
	build(1, 0, n-1);
	int q;
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		if(s=="pow"){
			int v;
			cin>>v;
			update(1, 0, n-1, ind[v], ind[v]+sz[v]-1);
		}
		else{
			int v;
			cin>>v;
			cout<<(query(1, 0, n-1, ind[v], ind[v]+sz[v]-1).f)<<endl;
		}
	}
	return 0;
}