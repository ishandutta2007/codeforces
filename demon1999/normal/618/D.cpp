#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <queue>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re  return
#define fi first
#define se second
#define l1 l11
#define l2 l22
typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pii;
using namespace std;
const ll mod = 1000000007;
ll n, x, y, a, b;
pair<int, int> dp[300000];
vector<int> edge[300000];

void dfs(int nu, int pr) {
    ll k = 0;
    dp[nu].fi = 0;
    dp[nu].se = 0;
    for (auto v : edge[nu]) {
        if (v != pr) {
            dfs(v, nu);
            dp[nu].fi += dp[v].fi;
            k += dp[v].se;
        }
    }
    if (k >= 2) {
        dp[nu].fi += k - 1;
        re;
    }
    dp[nu].se = 1;
    re;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("point.in", "r", stdin);
    cin >> n >> x >> y;
    ll ans;
    forn (i, n - 1) {
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    ll cnt = 0, k = 0;
    forn (i, n) {
        if (sz(edge[i]) == n - 1) {
            cnt = x;
        }
    }
    dfs(0, - 1);
    if (x < y) {
        ll k = dp[0].fi + dp[0].se - 1;
        cout << ll(k) * y + ll(n - k - 1) * x;
        re 0;
    }
    if (cnt == 0) ans = y * ll(n - 1);
    else ans = y * (n - 2LL) + x;
    cout << ans;
    return 0;
}