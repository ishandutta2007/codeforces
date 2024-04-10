#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int nn = 1 << 20;

long long n, l, t;

int a[nn];

void solve() {
    //scanf("%d%d%d", &n, &l, &t);
    cin >> n >> l >> t;
    for (int i = 0; i < n; ++i) scanf("%d", a + i);

    double r = 0;

    for (int i = 0; i < n; ++i) {
        double c = 0.0;
        {
            // +
            int end = a[i] + (t * 2) % l;
            long long k = (t * 2) / l;
            c += 0.5 * (n - 1) * k;

            if (l <= end) {
                c += 0.5 * (n - 1 - i);
                end -= l;
                int pos = upper_bound(a, a + n, end) - a;
                c += 0.5 * pos;
            } else {
                int pos = upper_bound(a, a + n, end) - a;
                c += 0.5 * (pos - 1 - i);
            }
        }
        // cerr << i << ' ' << c << endl;
        {
            // -
            int end = a[i] - (t * 2) % l;
            long long k = (t * 2) / l;
            c += 0.5 * (n - 1) * k;
            if (end >= 0) {
                int pos = lower_bound(a, a + n, end) - a;
                c += 0.5 * (i - pos);
            } else {
                c += 0.5 * (i);
                end += l;
                int pos = lower_bound(a, a + n, end) - a;
                c += 0.5* (n - pos);
            }
        }
        //cerr << i << ' ' << c << endl;
        r += 0.5 * c;
    }

    printf("%.4lf\n", r / 2.0);
}

int main() {
    solve();
    return 0;
}