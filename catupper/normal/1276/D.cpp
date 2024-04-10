#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

vector<int> edge[220000];
int u[220000];
int v[220000];
int n;
Int dp[220000][5];
//0: use parent
//1: use me
//2: Parent is not used but I am.
//3: I'm not used but parent is.
//4: Both absent.

Int dfs(Int x, Int last = -1){
    int laste = INF;
    for(auto e: edge[x]){
        int to = u[e] + v[e] - x;
        if(to == last){
            laste = e;
            continue;
        }
        dfs(to, x);
    }
    Int dp0n, dp0u, dp1, dp2, dp3n, dp3u, dp4;
    Int not_used = 1;
    Int used = 0;
    for(auto e: edge[x]){
        int to = u[e] + v[e] - x;
        if(e < laste){
            used *= dp[to][3] + dp[to][4];used %= MOD;
            used += not_used * dp[to][0]; used %= MOD;
            not_used *= dp[to][1] + dp[to][2];not_used %= MOD;
        }
        if(e == laste){
            dp0n = not_used;
            dp0u = 0;
            dp1 = not_used;
            dp2 = used;
            dp3n = not_used;
            dp3u = 0;
            dp4 = used;
        }
        if(e > laste){
            dp0u *= dp[to][3] + dp[to][4]; dp0u %=MOD;
            dp0u += dp0n * dp[to][0];dp0u %=MOD;
            dp0n *= dp[to][1] + dp[to][2];dp0n %=MOD;
            dp3u *= dp[to][3] + dp[to][4];dp3u %= MOD;
            dp3u += dp3n * dp[to][0];dp3u %= MOD;
            dp3n *= dp[to][1] + dp[to][2];dp3n %= MOD;
            dp1 *= dp[to][3] + dp[to][4];dp1 %= MOD;
            dp2 *= dp[to][3] + dp[to][4];dp2 %= MOD;
            dp4 *= dp[to][3] + dp[to][4];dp4 %= MOD;
        }
    }
    dp[x][0] = (dp0u + dp0n) % MOD;
    dp[x][1] = dp1;
    dp[x][2] = dp2;
    dp[x][3] = (dp3u + dp3n) % MOD;
    dp[x][4] = dp4;
//    cout << x << " "  << dp[x][0] << " " << dp[x][1] << " " << dp[x][2] << " " << dp[x][3] << endl;
    return (used + not_used) % MOD;
}

int main(){
    cin >> n;
    for(int i = 0;i < n-1;i++){
        cin >> u[i] >> v[i];
        edge[u[i]].push_back(i);
        edge[v[i]].push_back(i);
    }

    cout << dfs(1) << endl;
    return 0;
}