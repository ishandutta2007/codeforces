/**
 *  created: 28/11/2021, 16:35:38
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 22, inf = 1000111222;

int t, n;
long long a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        long long k = 1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            while (a[i] % 2 == 0) {
                a[i] /= 2;
                k *= 2;
            }
        }
        sort(a, a + n);
        a[n - 1] *= k;
        cout << accumulate(a, a + n, 0LL) << "\n";
    }
    return 0;
}