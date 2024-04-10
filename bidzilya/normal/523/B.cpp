#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(15);

    int n, T;
    double c;
    cin >> n >> T >> c;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long sa = 0;
    for (int i = 0; i < T; ++i) {
        sa += a[i];
    }
    double mean = 0.0;
    for (int i = 0; i < T; ++i) {
        mean = (mean + 1.0 * a[i] / T) / c;
    }
    int m;
    cin >> m;
    int last = T - 1;
    for (int i = 0; i < m; ++i) {
        int p;
        cin >> p;
        --p;
        while (last != p) {
            ++last;
            mean = (mean + 1.0 * a[last] / T) / c;
            sa -= a[last - T];
            sa += a[last];
        }
        double real = 1.0 * sa / T;
        cout << real << " " << mean << " " << fabs(mean - real) / real << '\n';
    }

    cout.flush();

    return 0;
}