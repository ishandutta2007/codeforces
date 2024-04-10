#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=205;
int d[N];




int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p, int dep)
{
    tin[v] = ++timer;
    up[v][0] = p;
    d[v]=dep;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v, dep+1);
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
	tin.clear();
	tout.clear();
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.clear();
    up.assign(n, vector<int>(l + 1));
    dfs(root, root, 0);
}
const int MOD=1e9+7;

int dp[N][N];//win, lose


int add(int x, int y)
{
	return (x + y) % MOD;
}
 
int sub(int x, int y)
{
	return add(x, MOD - y);
}
 
int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}
 
int binpow(int x, int y)
{
	int z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}
 
int inv(int x)
{
	return binpow(x, MOD - 2);
}
 
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	adj.resize(n);
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i=1; i<N; i++){
		dp[0][i]=1;
		dp[i][0]=0;
	}
	int cons=inv(2);
	for(int i=1; i<N; i++){
		for(int j=1; j<N; j++){
			dp[i][j]=((dp[i][j-1]+dp[i-1][j])*cons)%MOD;
		}
	}
	int ans=0;
	for(int i=0; i<n; i++){
		preprocess(i);
		for(int j=0; j<n; j++){
			for(int k=j+1; k<n; k++){
				int lc=lca(j, k);
				int ds=d[j]-d[lc];
				int db=d[k]-d[lc];
				ans=(ans+dp[db][ds])%MOD;
			}
		}
	}
	ans=(ans*inv(n))%MOD;
	cout<<ans<<endl;
	
	
	return 0;
}