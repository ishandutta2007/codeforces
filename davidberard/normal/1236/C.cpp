#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 303;

int f[N][N];
int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    int dir = 0;
    for (int i=0; i<n; ++i) {
        if (!dir) {
            for (int j=0; j<n; ++j) {
                f[j][i] = i*n+j+1;
            }
        } else {
            for (int j=0; j<n; ++j) {
                f[n-j-1][i] = i*n+j+1;
            }
        }
        dir ^= 1;
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout << f[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}