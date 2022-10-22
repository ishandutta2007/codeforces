#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, x, y, d;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> t;
    while(t--)
    {
        cin >> n >> x >> y >> d;
        int ans=1e18;
        if(x%d==y%d)
            ans=min(ans, abs(x-y)/d);
        if(y%d==1)
            ans=min(ans, (x+d-2)/d+(y-1)/d);
        if(y%d==n%d)
            ans=min(ans, (n-x+d-1)/d+(n-y)/d);
        if(ans==1e18)
            cout << -1;
        else cout << ans;
        cout << "\n";
    }
}