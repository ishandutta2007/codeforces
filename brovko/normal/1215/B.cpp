#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int k0=1;
    int k1=0;
    int k=0;
    int ans=0;

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i]<0)
            k=k^1;
        if(k==1)
        {
            k1++;
            ans+=k0;
        }
        else
        {
            k0++;
            ans+=k1;
        }
    }

    cout << ans << ' ' << n*(n+1)/2-ans;
}