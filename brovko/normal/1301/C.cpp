#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, n, m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        int ans=n*(n+1)/2;
        int k0=n-m;
        int mod=k0%(m+1);
        int div=k0/(m+1);
        int x=m+1-mod;
        ans-=div*(div+1)/2*x+(div+1)*(div+2)/2*mod;
        cout << ans << endl;
    }
}