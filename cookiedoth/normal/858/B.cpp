#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

const int mx = 200;
int n, q, k[mx], f[mx], ans = -2;

int main()
{
    cin >> n >> q;
    n--;
    for (int i = 0; i < q; ++i) {
        cin >> k[i] >> f[i];
        k[i]--;
        f[i]--;
    }
    for (int p = 1; p < mx * mx; ++p) {
        bool kek = 1;
        for (int i = 0; i < q; ++i) {
            if (k[i] / p != f[i])
                kek = 0;
        }
        if (kek) {
            if (ans == -2) {
                ans = n / p + 1;
            }
            if (ans >= 0 && (n / p + 1 != ans))
                ans = -1;
        }
    }
    cout << ans << endl;
    return 0;
}