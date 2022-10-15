#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
///#define int long long

const int N=(int) 2e5+7;
int n, a[N], mn[N], mx[N];

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

       /// freopen ("input", "r", stdin);

        int t;
        cin>>t;
        while (t--)
        {
                cin>>n;
                for (int i=1; i<=n; i++)
                        cin>>a[i];
                ll sol=0;
                for (int l=1; l<=n; l++)
                {
                        for (int r=l; r<=n; r++)
                        {
                                bool ok=1;
                                mn[l-1]=(int) 1e9;
                                for (int i=l; i<=r; i++)
                                {
                                        mn[i]=min(mn[i-1], a[i]);
                                }
                                mx[r+1]=-(int) 1e9;
                                for (int i=r; i>=l; i--)
                                {
                                        mx[i]=max(mx[i+1], a[i]);
                                }
                                for (int i=l; i<=r; i++)
                                {
                                        if (mn[i-1]<=a[i] && a[i]<=mx[i+1])
                                        {
                                                ok=0;
                                        }
                                }
                                mx[l-1]=-(int) 1e9;
                                for (int i=l; i<=r; i++)
                                {
                                        mx[i]=max(mx[i-1], a[i]);
                                }
                                mn[r+1]=(int) 1e9;
                                for (int i=r; i>=l; i--)
                                {
                                        mn[i]=min(mn[i+1], a[i]);
                                }
                                for (int i=l; i<=r; i++)
                                {
                                        if (mx[i-1]>=a[i] && a[i]>=mn[i+1])
                                        {
                                                ok=0;
                                        }
                                }
                                if (!ok)
                                        break;
                                sol++;
                        }

                }
                cout<<sol<<"\n";
        }

        return 0;
}