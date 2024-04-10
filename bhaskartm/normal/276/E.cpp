#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second
vector<vector<int>>adj;
int sz[100005];
int d[100005];
int dind[100005];
int bfsind[100005];
int dfsind[100005];
vector<int>eu;
int t[400020];
int t2[400020];
int maxi=0;

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

void update2(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t2[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update2(v*2, tl, tm, l, min(r, tm), add);
        update2(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}


int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}

int get2(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t2[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t2[v] + get2(v*2, tl, tm, pos);
    else
        return t2[v] + get2(v*2+1, tm+1, tr, pos);
}

void dfs(int v, int p, int h){
	d[v]=h;
	maxi=max(maxi, h);
	sz[v]=1;
	dfsind[v]=eu.size();
	eu.pb(v);
	for(auto u:adj[v]){
		if(u!=p){
			dfs(u, v, h+1);
			sz[v]+=sz[u];
		}
	}
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin>>n>>q;
	adj.resize(n+1);
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0, 0);
	vector<pair<int, int>>vec;
	for(int i=1; i<=n; i++){
		vec.pb({d[i], i});
	}
	sort(vec.begin(), vec.end());
	for(int i=0; i<100004; i++){
		dind[i]=-1;
	}
	for(int i=0; i<vec.size(); i++){
		dind[vec[i].f]=i;
		bfsind[vec[i].s]=i;
	}
	for(int i=0; i<q; i++){
		int type;
		cin>>type;
		if(type==0){
			int v, x, depth;
			cin>>v>>x>>depth;
			if(d[v]>depth){
				update(1, 0, n, dfsind[v]-depth, min(dfsind[v]+depth, dfsind[v]+sz[v]-1), x);
				continue;
			}
			else{
				int h=depth-d[v];
				update(1, 0, n, dfsind[v]-d[v]+1+h, min(dfsind[v]+depth, dfsind[v]+sz[v]-1), x);
				update2(1, 0, n, 0, dind[min(maxi, h)], x);
			}
		}
		else{
			int v;
			cin>>v;
			int val1=get(1, 0, n, dfsind[v]);
			int val2=get2(1, 0, n, bfsind[v]);
			
			cout<<val1+val2<<endl;
		}
	}
	
	return 0;
}