#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 505;
int a[N][N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int r, c;
    cin >> r >> c;
    if (r == 1 && c == 1) {
        cout << 0 << "\n";
        return 0;
    }
    if (c > 1) {
        for (int i=1; i<=r; ++i) {
            for (int j=1; j<=c; ++j) {
                a[i][j] = (j+r)*i;
            }
        }
        for (int i=1; i<=r; ++i) {
            int g = 0;
            for (int j=1; j<=c; ++j) {
                g = __gcd(a[i][j], g);
            }
            assert(g == i);
        }
        for (int j=1; j<=c; ++j) {
            int g = 0;
            for (int i=1; i<=r; ++i) {
                g = __gcd(a[i][j], g);
            }
            assert(g == j+r);
        }
    } else {
        for (int i=1; i<=r; ++i) {
            a[i][1] = i+1;
        }
    }
    for (int i=1; i<=r; ++i) {
        for (int j=1; j<=c; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}