#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ans = -1;
    for (int i=1; i <= n; i++) ans += (n%i==0);
    cout << ans << endl;
    return 0;
}