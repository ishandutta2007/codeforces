#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int) 1e4+7;
int n, a[N];

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);


        int t;
        cin>>t;
        while (t--)
        {
                cin>>n;
                for (int i=1; i<=n; i++)
                {
                        cin>>a[i];
                }

                if (a[1]==1)
                {
                        cout<<n+1 <<" ";
                        for (int i=1; i<=n; i++)
                        {
                                cout<<i<<" ";
                        }
                        cout<<"\n";
                        continue;
                }
                int ind=-1;
                for (int i=1; i<n; i++)
                {
                        if (a[i]==0 && a[i+1]==1)
                        {
                                ind=i;
                                break;
                        }
                }
                if (ind==-1)
                {
                        if (a[n]==0)
                        {
                                for (int i=1; i<=n+1; i++)
                                {
                                        cout<<i<<" ";
                                }
                                cout<<"\n";
                                continue;
                        }
                        cout<<"-1\n";
                        continue;
                }
                for (int i=1; i<=ind; i++)
                {
                        cout<<i<< " ";
                }
                cout<<n+1<<" ";
                for (int i=ind+1; i<=n; i++)
                {
                        cout<<i<< " ";
                }
                cout<<"\n";

        }

        return 0;
}