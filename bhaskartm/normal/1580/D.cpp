#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

const int N=4005;
int n, m;
int mm;
int arr[N];

vector<vector<int>>adj;
int sz[N];


void rec(int l, int r, int ind){
	if(l>r){
		return;
	}
	int pos=-1;
	int mini=1e18;
	for(int i=l; i<=r; i++){
		if(arr[i]<mini){
			mini=arr[i];
			pos=i;
		}
	}
	adj[ind].pb(pos);
	rec(l, pos-1, pos);
	rec(pos+1, r, pos);
}

int dp[N][N];
bool che[N][N];


int fu(int v, int m){
	if(m>sz[v]){
		return -1e18;
	}
	if(m==0){
		return 0;
	}
	if(che[v][m]){
		return dp[v][m];
	}
	che[v][m]=1;
	int szz=adj[v].size();
	if(szz==0){
		dp[v][m]=0;
		return dp[v][m];
	}
	if(szz==1){
		int w=arr[adj[v][0]]-arr[v];
		dp[v][m]=max(fu(adj[v][0], m)+w*m*(mm-m), w*(m-1)*(mm-m+1)+fu(adj[v][0], m-1));
		return dp[v][m];
	}
	int cl=adj[v][0];
	int cr=adj[v][1];
	int nl=max(0LL, m-sz[cr]);
	int nr=min(sz[cl], m);
	int w1=arr[cl]+arr[cr]-2*arr[v];
	int wl=arr[cl]-arr[v];
	int wr=arr[cr]-arr[v];
	for(int i=nl; i<=nr; i++){
		dp[v][m]=max(dp[v][m], fu(cl, i)+fu(cr, m-i)+wl*i*(mm-i)+wr*(m-i)*(mm-m+i));
	}
	nl=max(0LL, m-1-sz[cr]);
	nr=min(sz[cl], m-1);
	for(int i=nl; i<=nr; i++){
		dp[v][m]=max(dp[v][m], fu(cl, i)+fu(cr, m-i-1)+wl*i*(mm-i)+wr*(m-i-1)*(mm-m+i+1));
	}
	return dp[v][m];
}

void dfs(int v, int p){
	sz[v]=1;
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
	
	cin>>n>>m;
	mm=m;
	int ind=-1;
	int mini=1e18;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(arr[i]<mini){
			mini=arr[i];
			ind=i;
		}
	}
	adj.resize(n);
	int ind2=ind;
	rec(0, ind-1, ind);
	rec(ind+1, n-1, ind);
	
	dfs(ind2, -1);

	
	cout<<fu(ind2, m)<<endl;
	
	
	
	return 0;
}