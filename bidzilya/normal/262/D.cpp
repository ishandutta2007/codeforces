#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 50;
const int max_p = 50;

int n, p;
int a[max_n];
int sum = 0;
ll csum[max_n + 1][max_p + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    cin >> p;
    cout << fixed << setprecision(15);
    if (sum <= p) {
        cout << n << endl;
        return 0;
    }
    ld ans = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= p; ++k)
                csum[j][k] = 0;
        csum[0][0] = 1;
        for (int t = 0; t < n; ++t)
            if (t != i) {
                for (int c = n - 1; c >= 0; --c)
                    for (int k = 0; k + a[t] <= p; ++k)
                        csum[c + 1][k + a[t]] += csum[c][k];
            }
        for (int pos = 1; pos <= n; ++pos)
            for (int c = 0; c <= p; ++c)
                if (c + a[i] > p) {
                    ld cans = 1.0 * (pos - 1) * csum[pos - 1][c] / n;
                    for (int j = 1; j <= n - pos; ++j)
                        cans *= 1.0 * j / (pos - 1 + j);
                    ans += cans;
                }
    }
    cout << ans << endl;
    return 0;
}