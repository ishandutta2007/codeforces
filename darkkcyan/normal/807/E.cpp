#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ve vector
#define vi ve<int>
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = - 1; ++i < (n);)
#define rep1(i,n) for (int i = 0; ++i <= (n); )

namespace sol {

#define maxn 50
int n;
llong a[maxn] = {0};
ve<llong> c;
vi b, ans;

int main() {
    cin >> n;
    rep(i, n) {
        llong t; cin >> t;
        if (__builtin_popcountll(t) != 1) {
            c.push_back(t);
            continue;
        }
        int p = 0;
        while (t > 1) ++p, t >>= 1;
        a[p]++;
    }
    rep1(i, maxn - 1)
        if (a[i] > a[i - 1]) {
            rep(f, a[i] - a[i - 1]) c.push_back(1LL << (llong)i);
            a[i] = a[i - 1];
        }
    sort(c.begin(), c.end());
    llong cnt = sz(c);
    for (int i = maxn - 1; i > 0; i--) {
        rep(f, a[i - 1] - a[i]) {
            if (sz(c)) {
                if (c.back() > (1LL << (llong)i)) {
                    cout << -1;
                    return 0;
                }
                c.pop_back();
            }
            b.push_back(i);
        }
    }
    for (int i = sz(b); i--;) {
        if (cnt <= sz(b)) ans.push_back(sz(b));
        else break;
        cnt += b[i];
        b.pop_back();
    }
    if (sz(ans) == 0) cout << -1;
    else while(sz(ans)) cout << ans.back() << ' ', ans.pop_back();

    return 0;
} }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //int t; cin >> t;
    //while (t--)
    sol::main();
    return 0;
}