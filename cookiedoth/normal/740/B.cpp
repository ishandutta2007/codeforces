/**********
*         *
*  HELLO  *
*         *
**********/

#include <bits/stdc++.h>

using namespace std;

long long n, m, ans, a[1000], l, r, k;

int main()
{
    cin >> n >> m;
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (long long i = 0; i < m; ++i) {
        cin >> l >> r;
        k = 0;
        l -= 1;
        r -= 1;
        for (long long j = l; j <= r; ++j) k += a[j];
        if (k > 0) ans += k;
    }
    cout << ans;
    return 0;
}