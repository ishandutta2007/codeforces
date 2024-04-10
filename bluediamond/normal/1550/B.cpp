#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
///#define int long long

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        int t;
        cin>>t;
        while (t--)
        {
                int n, a, b, sol=0;
                string s;
                cin>>n>>a>>b>>s;
                if (b>=0)
                {
                        /// vreau cat mai multe taieri
                        sol=n;
                }
                else
                {
                        /// vreau cat mai putine taieri
                        sol=1;
                        for (int i=1;i<n;i++)
                                sol+=(s[i]!=s[i-1]);
                        if (sol>1)
                                sol/=2,sol++;
                }
                sol*=b;
                sol+=a*n;
                cout<<sol<<"\n";
        }

        return 0;
}