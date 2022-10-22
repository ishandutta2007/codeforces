#include <bits/stdc++.h>
#define int long long
#define y1 uwiegewiug

using namespace std;

int n, t, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    for(int i=0;i<n;i++)
        cin >> a[i];

    int Min=1e18;
    for(int i=0;i<n;i++)
        Min=min(Min, a[i]);
    int ans=0;

    while(t>=Min)
    {
        int s=0;
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(s+a[i]<=t)
            {
                s+=a[i];
                k++;
            }
        }
        ans+=t/s*k;
        t%=s;
    }

    cout << ans;
}