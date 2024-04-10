#include <bits/stdc++.h>
   
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
   
using namespace std;
   
typedef long long ll;
typedef pair<int, int> pii;

ll n, m, k;
ll x, s;
ll ans;
vector<pair<ll, ll> > a, b;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n >> m >> k;
    cin >> x >> s;
    a.resize(m);
    b.resize(k);
    ans = x * n;
    forn (i, m) {
        cin >> a[i].se;
    }
    forn (i, m) {
        cin >> a[i].fi;
        if (a[i].fi <= s)
            ans = min(ans, n * a[i].se);
    }
    sort(a.begin(), a.end());
    forn (i, k) {
        cin >> b[i].fi;
        b[i].fi = min(b[i].fi, n);
    }
    forn (i, k)
        cin >> b[i].se;
    int j = 0;
    ll mi = x;
    for (int i = k - 1; i >= 0; i--) {
        while (j < sz(a) && a[j].fi + b[i].se <= s) {
            mi = min(mi, a[j].se);
            j++;
        }
        if (b[i].se <= s) ans = min(ans, (n - b[i].fi) * mi);
    }
    cout << ans;
    return 0;
}