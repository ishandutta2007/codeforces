#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

      ///  freopen ("input", "r", stdin);

        int t;
        cin>>t;
        while (t--)
        {
                int n, ant;
                ll sol=0;
                cin>>n>>ant;
                for (int i=1; i<n; i++)
                {
                        int x;
                        cin>>x;
                        sol=max(sol, (ll)x*ant);
                        ant=x;
                }
                cout<<sol<<"\n";
        }

}