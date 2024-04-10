#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

const int N=320;
int val;
bool comp(pair<pair<pair<int, int>, pair<int, int>>, int>a, pair<pair<pair<int, int>, pair<int, int>>, int>b){
	int ga=a.f.f.f/N;
	int gb=b.f.f.f/N;
	if(ga==gb){
		return (ga & 1) ? a.f.f.s <b.f.f.s : a.f.f.s > b.f.f.s;
	}
	else{
		return a.f.f.f<b.f.f.f;
	}
    
}


int n, l;
vector<vector<int>> adj;
int arr[200005];
int ty[100005];
int num[100005];
int cnt[100005][2];
bool tak[100005];
int timer;
vector<int> tin, tout;
vector<vector<int>> up;


void dfs(int v, int p){
    tin[v] = ++timer;
    arr[timer]=v;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }
    tout[v] = ++timer;
    arr[timer]=v;
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
    dfs(root, root);
}





main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	adj.resize(n+1);
	for(int i=1; i<=n; i++){
		cin>>ty[i];
	}
	set<int>se;
	for(int i=1; i<=n; i++){
		cin>>num[i];
		se.insert(num[i]);
	}
	int pt=0;
	map<int, int>ma;
	for(auto u:se){
		ma[u]=pt;
		pt++;
	}
	for(int i=1; i<=n; i++){
		num[i]=ma[num[i]];
	}
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	preprocess(1);
	int q;
	cin>>q;
	int ans[q];
	vector<pair<pair<pair<int, int>, pair<int, int>>, int>>qu;
	for(int i=0; i<q; i++){
		int u, v;
		cin>>u>>v;
		if(u==v){
			ans[i]=0;
			continue;
		}
		if(tin[u]>tin[v]){
			swap(u, v);
		}
		int lc=lca(u, v);
		if(u==lc){
			qu.pb({{{tin[u], tin[v]}, {0, 0}}, i});
		}
		else{
			qu.pb({{{tout[u], tin[v]}, {1, lc}}, i});
		}
	}
	sort(qu.begin(), qu.end(), comp);
	int cur_l=1;
	int cur_r=0;
	for(int i=0; i<qu.size(); i++){
		int ind=qu[i].s;
		int l=qu[i].f.f.f;
		int r=qu[i].f.f.s;
		while (cur_l > l) {
            cur_l--;
            int ver=arr[cur_l];
            if(ty[ver]==1){
            	if(tak[ver]==0){
            		tak[ver]=1;
            		val+=cnt[num[ver]][0];
            		cnt[num[ver]][1]++;
            	}
            	else{
            		tak[ver]=0;
            		val-=cnt[num[ver]][0];
            		cnt[num[ver]][1]--;
            	}
            }
            else{
            	if(tak[ver]==0){
            		tak[ver]=1;
            		val+=cnt[num[ver]][1];
            		cnt[num[ver]][0]++;
            	}
            	else{
            		tak[ver]=0;
            		val-=cnt[num[ver]][1];
            		cnt[num[ver]][0]--;
            	}
            }
        }
        while (cur_r < r) {
            cur_r++;
            int ver=arr[cur_r];
            if(ty[ver]==1){
            	if(tak[ver]==0){
            		tak[ver]=1;
            		val+=cnt[num[ver]][0];
            		cnt[num[ver]][1]++;
            	}
            	else{
            		tak[ver]=0;
            		val-=cnt[num[ver]][0];
            		cnt[num[ver]][1]--;
            	}
            }
            else{
            	if(tak[ver]==0){
            		tak[ver]=1;
            		val+=cnt[num[ver]][1];
            		cnt[num[ver]][0]++;
            	}
            	else{
            		tak[ver]=0;
            		val-=cnt[num[ver]][1];
            		cnt[num[ver]][0]--;
            	}
            }
        }
        while (cur_l < l) {
            int ver=arr[cur_l];
            if(ty[ver]==1){
            	if(tak[ver]==0){
            		tak[ver]=1;
            		val+=cnt[num[ver]][0];
            		cnt[num[ver]][1]++;
            	}
            	else{
            		tak[ver]=0;
            		val-=cnt[num[ver]][0];
            		cnt[num[ver]][1]--;
            	}
            }
            else{
            	if(tak[ver]==0){
            		tak[ver]=1;
            		val+=cnt[num[ver]][1];
            		cnt[num[ver]][0]++;
            	}
            	else{
            		tak[ver]=0;
            		val-=cnt[num[ver]][1];
            		cnt[num[ver]][0]--;
            	}
            }
            cur_l++;
        }
        while (cur_r > r) {
            int ver=arr[cur_r];
            if(ty[ver]==1){
            	if(tak[ver]==0){
            		tak[ver]=1;
            		val+=cnt[num[ver]][0];
            		cnt[num[ver]][1]++;
            	}
            	else{
            		tak[ver]=0;
            		val-=cnt[num[ver]][0];
            		cnt[num[ver]][1]--;
            	}
            }
            else{
            	if(tak[ver]==0){
            		tak[ver]=1;
            		val+=cnt[num[ver]][1];
            		cnt[num[ver]][0]++;
            	}
            	else{
            		tak[ver]=0;
            		val-=cnt[num[ver]][1];
            		cnt[num[ver]][0]--;
            	}
            }
            cur_r--;
        }
        int rem=0;
        if(qu[i].f.s.f==1){
        	int ver=qu[i].f.s.s;
        	if(ty[ver]==0){
        		rem=cnt[num[ver]][1];
        	}
        	else{
        		rem=cnt[num[ver]][0];
        	}
        }
        ans[ind]=val+rem;
	}
	for(int i=0; i<q; i++){
		cout<<ans[i]<<endl;
	}
	
	return 0;
}