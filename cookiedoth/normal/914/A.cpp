#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const int mx = 300000;
int n, a[mx];

int main()
{
    int ans = -2000000;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        bool ok = 1;
        for (int j = 0; j < 2000; ++j) {
            if (j * j == a[i])
                ok = 0;
        }
        if (ok)
            ans = max(ans, a[i]);
    }
    cout << ans << endl;
    return 0;
}