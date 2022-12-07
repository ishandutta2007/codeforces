#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

const int maxn = 200005;
ll a[maxn], b[maxn], val[maxn];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        int now = 1;
        int ans = 1;
        ll cur = 0, lval = 0;
        for (int r = 1, l = 1; r < n; ++r) {
            b[r] = abs(a[r + 1] - a[r]);
            cur = __gcd(b[r], cur);
            // cout << cur << "\n";
            while (__gcd(cur, lval) == 1) {
                ++l;
                if (l > r) {
                    lval = cur = 0;
                    break;
                }
                if (l > now) {
                    now = r;
                    lval = cur = 0;
                    for (int j = now; j >= l; --j) {
                        lval = __gcd(lval, b[j]);
                        val[j] = lval;
                    }
                    // cout << lval << " " << cur << "\n";
                }
                lval = val[l];
            }
            // printf("%d %d %d\n", l, r, b[r]);
            ans = max(ans, r - l + 2);
        }
        cout << ans << "\n";
    }
    return 0;
}