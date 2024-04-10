#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;
const int mod = int(1e9) + 7;

int n;
ll x, y, cnt;
map<ll, vector<pair<int, int> > > c;
map<pair<int, int>, int> qq, p;

pair<int, int> get_rat(int x, int y) {
    if (x < 0) {
        x /= -1, y /= -1;
    }
    int gc = __gcd(abs(x), abs(y));
    x /= gc;
    y /= gc;
    return mp(x, y);
}

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int k = 0;
    forn (i, n) {
        ll t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            k++;
            auto& q = c[ll(x * x) + ll(y * y)];
            p[get_rat(x, y)]++;
            for (auto v : q) {
                if (v.se != y) {
                    qq[get_rat(v.se - y, x - v.fi)]++;
                }
            }
            q.push_back(mp(x, y));
        }
        if (t == 2) {
            k--;
            auto& q = c[ll(x * x) + ll(y * y)];
            p[get_rat(x, y)]--;
            for (auto v : q) {
                if (v.se != y) {
                    qq[get_rat(v.se - y, x - v.fi)]--;
                }
            }
            forn (i, sz(q)) {
                if (q[i].fi == x && q[i].se == y)
                    swap(q[i], q[sz(q) - 1]);
            }
            q.pop_back();
        }
        if (t == 3) {
            int ans = k - p[get_rat(x, y)] - 2 * qq[get_rat(x, y)];
            cout << ans << "\n";
        }
    }
    return 0;
}