/*****************
*                *
*  savkinsd2089  *
*                *
*****************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int mx = 500000;
    int n, a[mx], MIN = 2*1e9, MAX = -2*1e9, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        MIN = min(MIN, a[i]);
        MAX = max(MAX, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if ((a[i] > MIN) && (a[i] < MAX)) ans++;
     }
     cout << ans;
    return 0;
}