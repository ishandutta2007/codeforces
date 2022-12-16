#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <random>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const ll mod = 998244353;
const int NMAX = 200200;

ll inv(ll b) {
    ll p = mod-2;
    ll out = 1;
    b %= mod;
    while(p) {
        if(p&1) out = out*b%mod;
        b = (b*b)%mod;
        p>>=1;
    }
    return out;
}

int n;
vector<int> ch[NMAX];
ll dp[NMAX][3];

void dfs(int u) {
    dp[u][2] = 1;
    if(ch[u].size() == 0) {
        return;
    }
    dp[u][0] = 1;
    for(auto& v : ch[u]) {
        dfs(v);
        dp[u][0] = dp[u][0]*(dp[v][0]+dp[v][2])%mod;
        dp[u][1] = (dp[u][1] + inv(dp[v][0]+dp[v][2])*(dp[v][1]+dp[v][2]))%mod;
        dp[u][2] = dp[u][2]*(dp[v][0]+dp[v][1]+2*dp[v][2])%mod;
    }
    dp[u][1] = dp[u][1]*dp[u][0]%mod;
    dp[u][2] = (dp[u][2]+2*mod-dp[u][1]-dp[u][0])%mod;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=2; i<=n; ++i) {
        int p;
        cin >> p;
        ch[p].push_back(i);
    }
    dfs(1);
    cout << (dp[1][0]+dp[1][2])%mod << endl;
    return 0;
}