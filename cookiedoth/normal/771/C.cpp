/**********
*         *
*  HELLO  *
*         *
**********/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <stdio.h>
#define ll long long
#define mp make_pair
#define MOD 1000000007

using namespace std;

const ll mx = 300000;
ll n, k, dp[mx][5], dp2[mx][5], p[mx], ans, sz[mx];
vector<ll> g[mx], ch[mx];

void dfs(ll v, ll pv) {
    p[v] = pv;
    if (pv != -1)
        ch[pv].push_back(v);
    for (ll i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != pv)
            dfs(g[v][i], v);
    }
}

void count_dp1(ll v) {
    sz[v] = 0;
    for (int i = 0; i < k; ++i) {
        dp[v][i] = 0;
    }
    for (int i = 0; i < ch[v].size(); ++i) {
        int v1 = ch[v][i];
        count_dp1(v1);
        for (int j = 0; j < k; ++j) {
            dp[v][j] += dp[v1][j];
        }
        sz[v] += sz[v1];
    }
    ll temp[5];
    for (int i = 0; i < k; ++i) {
        temp[(i+1)%k] = dp[v][i];
    }
    temp[0]++;
    for (int i = 0; i < k; ++i) {
        dp[v][i] = temp[i];
    }
    sz[v]++;
}

void count_dp2(ll v) {
    for (int j = 0; j < ch[v].size(); ++j) {
        int v1 = ch[v][j];
        ll temp[5];
        for (int i = 0; i < 5; ++i) {
            temp[i] = 0;
        }
        for (int i = 0; i < k; ++i) {
            temp[(i+1)%k] = dp[v][i];
        }
        for (int i = 0; i < k; ++i) {
            temp[(i+2)%k] -= dp[v1][i];
        }
        for (int i = 0; i < k; ++i) {
            temp[(i+1)%k] += dp2[v][i];
        }
        for (int i = 0; i < k; ++i) {
            dp2[v1][i] = temp[i];
        }
    }
    for (int j = 0; j < ch[v].size(); ++j) {
        int v1 = ch[v][j];
        count_dp2(v1);
    }
}

void dfs3(ll v) {
    if (v != 0) {
        if (k != 1)
            ans += (dp[v][0] * (n - sz[v]) + dp2[v][1] * (sz[v])); //! dp2[v][1%k]
        else
            ans += (dp[v][0] * (n - sz[v]) + dp2[v][0] * (sz[v]));
    }
    for (int i = 0; i < ch[v].size(); ++i) {
        dfs3(ch[v][i]);
    }
}

int main()
{
    ans = 0;
    ll u, v;
    cin >> n >> k;
    for (ll i = 0; i < (n-1); ++i) {
        cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }
    dfs(0, -1);
    count_dp1(0);
    for (int i = 0; i < 5; ++i) {
        dp2[0][i] = 0;
    }
    count_dp2(0);
    dfs3(0);
    cout << ans / 2;
    return 0;
}