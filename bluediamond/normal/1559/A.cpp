#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool all[100];

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        int t;
        cin>>t;
        while (t--)
        {
                for (int i=0; i<=30; i++)
                        all[i]=1;
                int n;
                cin>>n;
                for (int i=1; i<=n; i++)
                {
                        int x;
                        cin>>x;
                        for (int j=0;j<=30; j++)
                                if ((x&(1<<j))==0)
                                        all[j]=0;
                }
                int sol=0;
                for (int i=0; i<=30; i++)
                {
                        sol+=all[i]*(1<<i);
                }
                cout<<sol<<"\n";
        }


        return 0;
}