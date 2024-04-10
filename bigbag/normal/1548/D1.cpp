/**
 *  created: 01/08/2021, 19:19:53
**/

#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2") // WINDOWS ONLY


#include <bits/stdc++.h>

using namespace std;

const int max_n = 6066, inf = 1000111222;

int n = 6000, x[max_n], y[max_n];
bitset<max_n> b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (1) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x[i], &y[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            const int dx = abs(x[j] - x[i]), dy = abs(y[j] - y[i]);
            b[i][j] = b[j][i] = (dx % 4 == 0 && dy % 4 == 0);//__gcd(dx, dy) % 4 == 0;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (b[i][j]) {
                ans += (b[i] ^ b[j]).count();
                ans -= b[i][j] ^ b[j][j];
                ans -= b[i][i] ^ b[j][i];
            } else {
                ans += n - (b[i] | b[j]).count();
                ans -= (b[i][j] ^ b[j][j]) == 0;
                ans -= (b[i][i] ^ b[j][i]) == 0;
            }
        }
    }
    ans = -ans;
    //cout << ans << endl;
    assert(ans % 3 == 0);
    ans /= 3;
    ans += 1LL * n * (n - 1) * (n - 2) / 6;
    cout << ans << endl;
    return 0;
}