#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 2*c+2*min(a, b);
    if (a > b) ans++;
    int tet = 0;
    if (b > 0){
        tet++;
        b--;
        tet += 2*c+2*min(a, b);
        if (a > b) tet++;
    }
    ans = max(ans, tet);
    cout << ans;
}