#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 999;
const int MOD = 998244353;

int n, m;
vector <int> g[N];
int p2[N];
int cnt[2];
int col[N];
bool bad;

void dfs(int v, int c){
	col[v] = c;
	++cnt[c];
	for(auto to : g[v]){
		if(col[to] == -1) dfs(to, 1 - c);
		if((col[v] ^ col[to]) == 0)
			bad = true;
	}
}

int main() {
    p2[0] = 1;
    for(int i = 1; i < N; ++i)
    	p2[i] = (2 * p2[i - 1]) % MOD;
    	
    int tc;
    scanf("%d", &tc);
    while(tc--){
    	scanf("%d%d", &n, &m);
    	for(int i = 0; i < n; ++i)
    	    g[i].clear();
    	
    	for(int i = 0; i < m; ++i){
    		int u, v;
    		scanf("%d %d", &u, &v);
    		--u, --v;
    		g[u].push_back(v);
    		g[v].push_back(u);
    	}
    	
    	int res = 1;
    	for(int i = 0; i < n; ++i) col[i] = -1;
    	for(int i = 0; i < n; ++i){
    	    if(col[i] != -1) continue;
            bad = false;
            cnt[0] = cnt[1] = 0;
            dfs(i, 0);
    	    if(bad){
    		    puts("0");
    		    break;
    	    }
    	    int cur = (p2[cnt[0]] + p2[cnt[1]]) % MOD;
    	    res = (res * 1LL * cur) % MOD;
    	}
    	
    	if(!bad) printf("%d\n", res);
    }
    
    return 0;
}