#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int y, b, r;
    cin >> y >> b >> r;
    int ans = 0;
    for (int i=0; i < 1000; i++){
        if (y >= i && b >= i+1 && r >= i+2) ans = 3*i+3;
    }
    cout << ans;
    return 0;
}