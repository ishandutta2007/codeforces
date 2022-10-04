/**********
*         *
*  HELLO  *
*         *
**********/

#include <bits/stdc++.h>

using namespace std;

const long long mx = 300000;
const long long lg = 25;
long long k[mx], n, xx, a, j, d, xr, ans = 0, xxx;
bool m[lg], x[lg];

int main()
{
    for (long long i = 0; i < mx; ++i) {
        k[i] = 0;
    }
    for (long long i = 0; i < lg; ++i) {
        m[i] = 0;
        x[i] = 0;
    }
    cin >> n >> xx;
    xxx = xx;
    for (long long i = 0; i < lg; ++i) {
        x[i] = (xx % 2);
        xx =  (xx / 2);
    }
    for (long long i = 0; i < n; ++i) {
        cin >> a;
        k[a]++;
    }
    for (long long i = 0; i < mx; ++i) {
        if (k[i] > 0) {
            a = i;
            for (long long j = 0; j < lg; ++j) {
                m[j] = (a % 2);
                a = (a / 2);
            }
            for (long long j = 0; j < lg; ++j) {
                if (x[j] == 1) m[j] = !m[j];
            }
            d = 1;
            xr = 0;
            for (long long j = 0; j < lg; ++j) {
                if (m[j] == 1) xr += d;
                d *= 2;
            }
            if ((xr >= 0) && (xr < mx)) {
                if (xxx > 0) {
                    ans += k[i] * k[xr];
                }
                else {
                    ans += k[i] * (k[i] - 1);
                }
            }
        }
    }
    cout << ans / 2;
    return 0;
}