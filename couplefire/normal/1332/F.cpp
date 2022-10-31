#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MOD = 998244353;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int n, dp[N][3];
vector<int> adj[N];

void dfs(int v, int p){
    dp[v][0] = dp[v][1] = dp[v][2] = 1;
    for(auto u : adj[v]){
        if(u == p) continue;
        dfs(u, v);
        grow(dp[v][0], add(mul(dp[u][0], 2), add(dp[u][1], mul(dp[u][2], 2))));
        grow(dp[v][1], add(dp[u][0], dp[u][2]));
        grow(dp[v][2], add(mul(dp[u][0], 2), dp[u][2]));
    }
    dec(dp[v][2], dp[v][1]);
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    cout << sub(add(dp[0][0], dp[0][2]), 1) << endl;
}