#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

int t, n, m, k, a[4005], b[4005];

int32_t main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        k=min(k, m-1);
        for(int i=0;i<n;i++)
            cin >> a[i];
        int r=n-m;
        for(int i=0;i<m;i++)
        {
            b[i]=max(a[i], a[r]);
            r++;
        }
        int Max=0;
        for(int i=0;i<=min(k, m-1);i++)
        {
            int Min=1e18;
            for(int j=i;j<min(i+m-k, m);j++)
                Min=min(Min, b[j]);
            Max=max(Max, Min);
        }
        cout << Max << endl;
    }
}