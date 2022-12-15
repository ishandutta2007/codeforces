#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define pb push_back
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()

const int N = 2e5 + 5;

int d[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    vector<int> v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 1, a; i <= m; i++)
        cin >> a, v.pb(a);
    sort(ALL(v));
    int it = 0;
    vector<pll> ev;
    for (int i = 1; i <= n; i++) {
        ll p = (i - 1) * 100;
        while (it < SZ(v) && v[it] < p)
            it++;
        ll mn = 1e15;
        if (it != SZ(v))
            mn = min(mn, v[it] - p);
        if (it != 0)
            mn = min(mn, p - v[it - 1]);
        ev.pb({p - mn, d[i]});
        ev.pb({p + mn, -d[i]});
    }
    sort(ALL(ev));
    ll tt = 0, ans = 0;
    for (int i = 0; i < SZ(ev); ) {
        int j = i;
        while (j < SZ(ev) && ev[j].X == ev[i].X)
            tt += ev[j].Y, j++;
        ans = max(ans, tt);
        i = j;
    }
    cout << ans << endl;
}