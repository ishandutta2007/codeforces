#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define V vector
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "LINE(" << __LINE__ << ") ->" << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;
const ll oo = 1e18;

int t[N], h[N];
ll dp[N][3];
/*
0: in
1: no
2: out
*/
vi G[N];

void dfs(int u, int p = 0) {
    dp[u][0] = dp[u][1] = dp[u][2] = oo;
    int cnt = 0;
    vi in, out, both;
    for(int v:G[u]) if(v != p) {
        dfs(v, u);
        cnt++;
        if(h[v] < h[u]) in.PB(v);
        else if(h[v] > h[u]) out.PB(v);
        else both.PB(v);
    }
    ll ans = 0;
    int deg = 0;
    for(int v:in) {
        ll cost = oo;
        for(int i = 0; i < 3; i++)
            cost = min(cost, (i == 0 ? 0 : t[v]) + dp[v][i] + t[u]);
        ans += cost;
        deg--;
    }
    for(int v:out) {
        ll cost = oo;
        for(int i = 0; i < 3; i++)
            cost = min(cost, (i == 2 ? 0 : t[v]) + dp[v][i]);
        ans += cost;
        deg++;
    }
    V<ll> aux;
    for(int v:both) {
        ll cost1 = oo;
        for(int i = 0; i < 3; i++)
            cost1 = min(cost1, (i == 0 ? 0 : t[v]) + dp[v][i] + t[u]);
        ll cost2 = oo;
        for(int i = 0; i < 3; i++)
            cost2 = min(cost2, (i == 2 ? 0 : t[v]) + dp[v][i]);
        deg--;
        ans += cost1;
        aux.PB(cost2 - cost1);
    }
    if(u == 2) debug(ans);
    sort(ALL(aux));
    for(int i = 0; i <= int(aux.size()); i++) {
        ll tt = ans + (ll) max(deg, 0) * t[u];
        if(deg < 0) dp[u][0] = min(dp[u][0], tt);
        else if(deg > 0) dp[u][2] = min(dp[u][2], tt);
        else dp[u][1] = min(dp[u][1], tt);
        deg += 2;
        if(i < int(aux.size())) ans += aux[i];
    }
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> t[i];
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].PB(v);
        G[v].PB(u);
    }
    dfs(1);
    ll ans = oo;
    for(int i = 0; i < 3; i++)
        ans = min(ans, dp[1][i]);
    cout << ans << '\n';


}