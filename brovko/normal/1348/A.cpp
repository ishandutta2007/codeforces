#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n;

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
        cin >> n;
        int ans=0;
        for(int i=0;i<n/2-1;i++)
            ans+=(1ll << i);
        for(int i=n/2-1;i<n-1;i++)
            ans-=(1ll << i);
        ans+=(1ll << n-1);
        cout << ans*2 << "\n";
    }
}