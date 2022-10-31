#include <bits/stdc++.h>
using namespace std;

const int N = 310;
const int MOD = 998244353;
const int INV2 = (MOD+1)/2;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int n, r, ans;
vector<int> adj[N];
int dp[N][2*N], tmp[2*N], dep[N];

void dfs(int v, int p){
    dep[v] = 0;
    dp[v][0] = dp[v][n] = INV2;
    for(auto u : adj[v]){
        if(u == p) continue;
        dfs(u, v);
        memset(tmp, 0, sizeof tmp);
        for(int i = 0; i<=dep[v]; i++){
            for(int j = 0; j<=dep[u]; j++){
                inc(tmp[min(i, j+1)], mul(dp[v][i], dp[u][j]));
                if(i+j+1 <= r) inc(tmp[i], mul(dp[v][i], dp[u][j+n])), inc(tmp[j+1], mul(dp[v][i+n], dp[u][j]));
                else inc(tmp[i+n], mul(dp[v][i+n], dp[u][j])), inc(tmp[j+1+n], mul(dp[v][i], dp[u][j+n]));
                inc(tmp[max(i, j+1)+n], mul(dp[v][i+n], dp[u][j+n]));
            }
        }
        swap(tmp, dp[v]);
        dep[v] = max(dep[v], dep[u]+1);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans = n;
    for(r = 0; r<=n; r++){
        memset(dp, 0, sizeof dp);
        dfs(0, -1);
        for(int d = 0; d<n; d++) dec(ans, dp[0][d]);
    }
    cout << ans << endl;
}