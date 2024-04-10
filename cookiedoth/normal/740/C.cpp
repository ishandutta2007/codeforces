/**********
*         *
*  HELLO  *
*         *
**********/

#include <bits/stdc++.h>

using namespace std;

int n, m, l, r, mn;

int main()
{
    cin >> n >> m;
    mn = 1e9;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        mn = min(r - l + 1, mn);
    }
    cout << mn << endl;
    for (int i = 0; i < n; ++i) {
        cout << (i % mn) << " ";
    }
    return 0;
}