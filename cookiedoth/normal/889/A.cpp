#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

const int mx = 300000;
int n, a[mx], deg[mx];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        deg[a[i]]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (deg[i] > 0)
            ans += (deg[i] - 1);
    }
    ans += deg[0];
    cout << ans << endl;
    return 0;
}