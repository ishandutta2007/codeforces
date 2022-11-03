#include <cstdio>
#include <cmath>

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int max_n = 5e3 + 100;

int n, m;
int b[max_n], a[max_n];
vector<int> l, r, t, d;

int main() {
   // freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        a[i] = 1e9;
    l.resize(m);
    r.resize(m);
    t.resize(m);
    d.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> t[i] >> l[i] >> r[i] >> d[i];
        --l[i]; --r[i];
        if (t[i] == 1) {
            for (int j = l[i]; j <= r[i]; ++j)
                b[j] += d[i];
        } else {
            for (int j = l[i]; j <= r[i]; ++j)
                a[j] = min(a[j], d[i] - b[j]);
        }
    }
    for (int i = 0; i < n; ++i)
        b[i] = a[i];
    for (int i = 0; i < m; ++i) {
        if (t[i] == 1) {
            for (int j = l[i]; j <= r[i]; ++j)
                b[j] += d[i];
        } else {
            int m = b[l[i]];
            for (int j = l[i] + 1; j <= r[i]; ++j)
                m = max(m, b[j]);
            if (m != d[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}