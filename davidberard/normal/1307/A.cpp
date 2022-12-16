#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int a[110];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        int n, d;
        cin >> n >> d;
        memset(a, 0, sizeof a);
        for (int i=1; i<=n; ++i) {
            cin >> a[i];
        }
        for (int i=1; i<=d; ++i) {
            int j = 0;
            for (int k=2; k<=n; ++k) {
                if (a[k]) {
                    j = k;
                    break;
                }
            }
            --a[j];
            ++a[j-1];
        }
        cout << a[1] << "\n";

    }
    return 0;
}