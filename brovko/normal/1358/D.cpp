#include <bits/stdc++.h>
#define int long long
#define y1 uwiegewiug

using namespace std;

int n, x, a[400005], pk[400005], ps[400005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        a[n+i]=a[i];
    }

    n*=2;
    for(int i=0;i<n;i++)
    {
        pk[i+1]=pk[i]+a[i];
        ps[i+1]=ps[i]+a[i]*(a[i]+1)/2;
    }

    int Max=0;
    int L=0;
    for(int i=0;i<n;i++)
        if(pk[i+1]>=x)
    {
        while(pk[i+1]-pk[L]>x)
            L++;
        int ans=ps[i+1]-ps[L];
        int c=x-(pk[i+1]-pk[L]);
        if(c)
            ans+=(2*a[L-1]-c+1)*c/2;
        Max=max(Max, ans);
    }
    cout << Max;
}