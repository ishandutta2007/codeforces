#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=(int) 1e5+7;
int n, k, a[N];

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

      ///  freopen ("input", "r", stdin);

        int t, bulan=1000;
        cin>>t;
        while (t--)
        {
                cin>>n>>k;
                for (int i=1; i<=n; i++)
                        cin>>a[i];
                ll sol=-(ll) 1e18;
                int piv=max(1, n-bulan);
                for (int i=piv; i<=n; i++)
                {
                        for (int j=i+1; j<=n; j++)
                        {
                                sol=max(sol, (ll)i*j-k*(a[i]|a[j]));
                        }
                }
                cout<<sol<<"\n";
        }

}