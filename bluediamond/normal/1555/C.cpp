#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll


const int N=(int) 1e5+7;
const int INF=(int) 1e18;
int n, a[2][N], pre[2][N], p[N], s[N];

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        //freopen ("input", "r", stdin);

        int t;
        cin>>t;
        while (t--)
        {
                cin>>n;
                for (int i=0; i<2; i++)
                        for (int j=1; j<=n; j++)
                        {
                                cin>>a[i][j];
                                pre[i][j]=pre[i][j-1]+a[i][j];
                        }
                p[0]=-INF;

                for (int i=1; i<=n; i++)
                        p[i]=max(p[i-1], -pre[1][i-1]);

                s[n+1]=-INF;
                for (int i=n; i>=1; i--)
                        s[i]=max(s[i+1], pre[0][i]);

                int sol=INF;
                for (int i=1; i<=n; i++)
                {
                        /// aici coboara Alice
                        int mx1=-INF, mx2=-INF;
                        mx1=p[i-1];
                        mx1+=pre[1][i-1];
                        mx2=s[i+1];
                        mx2-=pre[0][i];
                        int mx=max(mx1, mx2);
                        mx=max(mx, 0LL);
                        sol=min(sol, mx);
                }
                cout<<sol<<"\n";
        }

}