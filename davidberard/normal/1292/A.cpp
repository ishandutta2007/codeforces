#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 100100;

int a[4][N];

ll bad_pairs;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i=1; i<=q; ++i) {
        int r ,c;
        cin >> r >> c;
        if (a[r][c]) {
            a[r][c] = 0;
            for (int j=-1; j<=1; j+=2) {
                for (int k=-1; k<=1; ++k) {
                    if ((j || k) && a[r+j][c+k]) {
                        --bad_pairs;
                    }
                }
            }
        } else {
            a[r][c] = 1;
            for (int j=-1; j<=1; j+=2) {
                for (int k=-1; k<=1; ++k) {
                    if ((j || k) && a[r+j][c+k]) {
                        ++bad_pairs;
                    }
                }
            }
        }
        cout << (bad_pairs ? "No" : "Yes") << "\n";
    }

    return 0;
}