/************
*           *
*   HELLO   *
*           *
************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, a[1000], ans = 0, i;
    cin >> n >> k;
    for (i = 0; i<n; i++) {
        cin >> a[i];
    }
    for (i = 1; i<n; i++) {
        if ((a[i] + a[i-1]) < k) {
            ans += (k - a[i] - a[i-1]);
            a[i] = k - a[i-1];
        }
    }
    cout << ans << endl;
    for (i = 0; i<n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}