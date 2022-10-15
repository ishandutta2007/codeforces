#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

int t;

int getmax(int n, int limit)
{
        /// max (i^n) for 0<=i<=limit
        int sol=0, curi=0;
        for (int bit=30; bit>=0; bit--)
        {
                if (!(n&(1<<bit)))
                {
                        if (curi+(1<<bit)<=limit)
                        {
                                sol+=(1<<bit);
                                curi+=(1<<bit);
                        }
                }
                else
                {
                        sol+=(1<<bit);
                }
        }
        return sol;
}

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

      ///  freopen ("input", "r", stdin);

        cin>>t;
        while (t--)
        {
                int n, m, mex=0, l=0, r=(int) 2e9, sol=0;
                cin>>n>>m;
                while (l<=r)
                {
                        int mid=(l+r)/2;
                        if (getmax(n, mid)<=m)
                        {
                                sol=mid+1;
                                l=mid+1;
                        }
                        else
                        {
                                r=mid-1;
                        }
                }
                cout<<sol<<"\n";

        }
}