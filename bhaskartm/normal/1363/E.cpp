#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>>adj;
int a[200005];
int b[200005];
int c[200005];
int sz[200005];
int ind[200005];
int num01[200005];
int num10[200005];
vector<int>eu;
int t[800020];
int t2[800020];
int marked[800020];

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t2[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update2(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t2[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update2(v*2, tl, tm, pos, new_val);
        else
            update2(v*2+1, tm+1, tr, pos, new_val);
        t2[v] = t2[v*2] + t2[v*2+1];
    }
}

void push(int v) {
    if (marked[v]) {
        t[v*2] = t[v*2+1] = t[v];
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}

void update(int v, int tl, int tr, int l, int r, int new_val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] = new_val;
        marked[v] = true;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) 
        return get(v*2, tl, tm, pos);
    else
        return get(v*2+1, tm+1, tr, pos);
}

void dfs(int v, int p){
	if(b[v]==0 && c[v]==1){
		num01[v]++;
	}
	if(b[v]==1 && c[v]==0){
		num10[v]++;
	}
	sz[v]=1;
	ind[v]=eu.size();
	eu.push_back(v);
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		dfs(u, v);
		sz[v]+=sz[u];
		num10[v]+=num10[u];
		num01[v]+=num01[u];
	}
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	adj.resize(n+1);
	for(int i=1; i<=n; i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	vector<pair<int, int>>v;
	for(int i=1; i<=n; i++){
		v.push_back({a[i], i});
	}
	sort(v.begin(), v.end());
	int ans=0;
	if(num01[1]!=num10[1]){
		cout<<-1;
		return 0;
	}
	for(int i=0; i<n; i++){
		int node=v[i].second;
		int cost=v[i].first;
		int val=get(1, 0, n, ind[node]);
		if(val==1){
			continue;
		}
		update(1, 0, n, ind[node], ind[node]+sz[node]-1, 1);
		int tot=min(num01[node], num10[node]);
		int ge=sum(1, 0, n, ind[node], ind[node]+sz[node]-1);
		int ch=tot-ge;
		ans=ans+2*ch*a[node];
		update2(1, 0, n, ind[node], ch);
	}
	cout<<ans<<endl;
	return 0;
}