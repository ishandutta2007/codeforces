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

int n;
int a[1005];
ll ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int l = 0; l < n; l += 2) {
        ll s = 0;
        ll lmin = 0;
        for (int r = l + 1; r <= n; ++r) {
            if ((r - l) & 1) {
                ll L = a[l], R = a[r], cur = s;
                L -= -lmin, cur += -lmin;

                if (cur <= R) {
                    // printf("l=%d,r=%d,L=%I64d,R=%I64d,cur=%I64d\n", l, r, L, R, cur);
                    R -= cur;
                    ans += min(L, R) + (min(L, R) != min(a[l], a[r]));
                    // printf("ans=%I64d\n", ans);
                }

                s -= a[r];
                lmin = min(lmin, s);
                if (a[l] + lmin < 0) break;
            } else {
                s += a[r];
            }
        }
    }
    cout << ans << "\n";
    return 0;
}