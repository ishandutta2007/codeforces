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
int a[21];
int p[21][21];
int f[1 << 14];
int g[14][1 << 14], h[14][1 << 14];
int ans;

int inverse(int x) { return x <= 1 ? 1 : (ll)(M - M / x) * inverse(M % x) % M; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            p[i][j] = (ll)a[i] * inverse(a[i] + a[j]) % M;
        }

    int S = (1 << n) - 1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) continue;
            g[i][mask] = h[i][mask] = 1;
            for (int j = 0; j < n; ++j) {
                if (!(mask >> j & 1)) continue;
                g[i][mask] = (ll)g[i][mask] * p[i][j] % M;
                h[i][mask] = (ll)h[i][mask] * p[j][i] % M;
            }
        }
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        int p = 1;

        for (int tmask = (mask - 1) & mask; tmask; tmask = (tmask - 1) & mask) {
            int q = f[tmask];
            int vmask = mask ^ tmask;
            for (int i = 0; i < n; ++i) {
                if (vmask >> i & 1) {
                    q = (ll)q * (h[i][tmask]) % M;
                }
            }
            p = (p - q + M) % M;
        }
        f[mask] = p;
        // printf("%d: %d\n", mask, f[mask]);

        {
            int q = 1;
            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1) {
                    q = (ll)q * g[i][S ^ mask] % M;
                }
            }

            p = (ll)p * q % M;
            // printf("%d: %d\n", mask, p);

            ans = (ans + (ll)__builtin_popcount(mask) * p) % M;
        }
    }

    cout << ans << "\n";

    return 0;
}