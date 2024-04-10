#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=2e5+5;
int arr[N];
vector<vector<int>>adj;
int sz[N];
int ind[N];
int pa[N];
int cnt[N];
vector<int>v2;
void dfs(int v, int p){
	sz[v]=1;
	pa[v]=p;
	v2.pb(v);
	ind[v]=v2.size();
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		dfs(u, v);
		sz[v]+=sz[u];
	}
}



int t[4*N+5];
int lazy[4*N+5];


void push(int v, int tl, int tr) {
	int tm=(tl+tr)/2;
    t[v*2] += lazy[v]*(tm-tl+1);
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v]*(tr-tm);
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend*(tr-tl+1);
        lazy[v] += addend;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 1e9;
    if (l <= tl && tr <= r)
        return t[v];
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	
	set<int>se;
	
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		se.insert(arr[i]);
	}
	map<int, int>ma;
	int pt=0;
	for(auto u:se){
		ma[u]=pt;
		pt++;
	}
	for(int i=1; i<=n; i++){
		arr[i]=ma[arr[i]];
		cnt[arr[i]]++;
	}
	adj.resize(n+1);
	
	
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	vector<vector<int>>vec;
	vec.resize(N+5);
	dfs(1, 0);
	for(int i=1; i<=n; i++){
		vec[arr[i]].pb(ind[i]);
	}
	
	for(int i=0; i<=N; i++){
		sort(vec[i].begin(), vec[i].end());
	}
	
	for(int i=1; i<=n; i++){
		for(auto u:adj[i]){
			if(u==pa[i]){
				int ind1=lower_bound(vec[arr[i]].begin(), vec[arr[i]].end(), ind[i])-vec[arr[i]].begin();
				int ind2=upper_bound(vec[arr[i]].begin(), vec[arr[i]].end(), ind[i]+sz[i]-1)-vec[arr[i]].begin();
				ind2--;
				int num=ind2-ind1+1;
				
				if(num==cnt[arr[i]]){
					continue;
				}
				else{
					
					update(1, 0, N, ind[i], ind[i]+sz[i]-1, 1);
				}
			}
			else{
				int ind1=lower_bound(vec[arr[i]].begin(), vec[arr[i]].end(), ind[u])-vec[arr[i]].begin();
				int ind2=upper_bound(vec[arr[i]].begin(), vec[arr[i]].end(), ind[u]+sz[u]-1)-vec[arr[i]].begin();
				ind2--;
				int num=ind2-ind1+1;
				if(num==0){
					continue;
				}
				else{
					
					update(1, 0, N, ind[1], ind[1]+sz[1]-1, 1);
					update(1, 0, N, ind[u], ind[u]+sz[u]-1, -1);
				}
			}
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		if(query(1, 0, N, ind[i], ind[i])==0){
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}