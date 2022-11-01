#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define x first
#define y second
#define point pair <int, int>
#define re return
#define se second
#define fi first
#define mp(a, b) make_pair(a, b)
#define mp1(a, b, c, d) make_pair(mp(a, b), mp(c, d))
using namespace std;
typedef long long ll;
const ll mod = (1e9) + 7;

ll n, ans = -1e18, c[300000], k[300000];
vector<int> e[300000];
string s;

void dfs(int nu, int pr) {
    ll ma1 = -1e9 - 1, ma2 = -1e9 - 1;
    //cout << ma1 << " " << ma2 << "\n";
    for (int v : e[nu]) {
        if (v != pr) {
            dfs(v, nu);
            ll kk = max(c[v], k[v]);
            if (ma1 < kk) {
                ma2 = ma1;
                ma1 = kk;
            }
            else
                ma2 = max(ma2, kk);
            c[nu] += c[v];
        }
    }
    k[nu] = max(c[nu], ma1);
    if (ma1 >= ll(-1e9) && ma2 >= ll(-1e9))
        ans = max(ans, ma1 + ma2);
}

int main() {
    iostream::sync_with_stdio(0);
    //freopen("a.in", "r", stdin);
    cin >> n;
    forn (i, n) {
        cin >> c[i];
    }
    forn (i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(0, -1);
    if (ans == ll(-1e18))
        cout << "Impossible";
    else
        cout << ans;
}