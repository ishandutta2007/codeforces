#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int N = 3e5 + 87, M = 998244353;

int pw[N], vis[N], ct[2];
vector<int> G[N];

bool dfs(int u,int c) {
    if (vis[u] != -1)
        return vis[u] == c;
    vis[u] = c;
    ct[c]++;
    for(int v : G[u]) 
        if(!dfs(v,(c+1)%2))
            return false;
    return true;
}

int main()
{
    IO_OP
    
    pw[0] = 1;
    for (int i = 1; i < N; i++)
        pw[i] = pw[i-1] * 2 % M;
    int t;
    cin >> t;
    while (t--) {
    	bool nosol = false;
    	int n, m;
	    cin >> n >> m;
	    for (int i = 0; i < n; i++) {
	        G[i].clear();
	        vis[i] = -1;
	    }
	    for (int i = 0; i < m; i++) {
	        int u, v;
	        cin >> u >> v;
	        u--, v--;
	        G[u].push_back(v);
	        G[v].push_back(u);
	    }
	    ll ans = 1;
	    for (int i = 0; i < n; i++) {
	        if (vis[i] != -1) continue;
	        ct[0] = ct[1] = 0;
	        if (!dfs(i, 0)) {
	            cout << 0 << endl;
	            nosol = true;
	            break;
	        }
	        ans = ans * (pw[ct[0]] + pw[ct[1]]) % M;
	    }
	    if(!nosol)
	    	cout << ans << endl;
    }
}