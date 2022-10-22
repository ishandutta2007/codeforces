#include <bits/stdc++.h>
#define int long long

using namespace std;
int t, n, m, a[400005], p[400005], s[400005], Maxp[400005], k, ans, Max, MAX;

int32_t main()
{
    cin >> t;
    for(int tt=0;tt<t;tt++)
    {
        ans=0;
        k=1;
        Max=0;
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];
        cin >> m;
        for(int i=0;i<m;i++)
        {
            cin >> p[i] >> s[i];
            Maxp[s[i]]=max(Maxp[s[i]], p[i]);
        }
        
        for(int i=n-1;i>=0;i--)
            Maxp[i]=max(Maxp[i], Maxp[i+1]);
        MAX=0;
        for(int i=0;i<n;i++)
            MAX=max(MAX, a[i]);
        if(MAX>Maxp[0])
            cout << "-1\n";
        else
        {
            for(int i=0;i<n;i++)
        {
            Max=max(Max, a[i]);
             if(Maxp[k]<Max)
             {
                 ans++;
                 k=2;
                 Max=a[i];
             }
             else
             {
                 k++;
             }
        }
            cout << ans+1 << "\n";
        }
        for(int i=0;i<=n;i++)
            Maxp[i]=0;
    }
    return 0;
}