#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;

int n, m, a[21][21];

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        int t;
        cin>>t;
        while (t--)
        {
                cin>>n>>m;
                for (int i=1; i<=n; i++)
                        for (int j=1; j<=m; j++)
                                a[i][j]=0;

                a[1][1]=a[1][m]=a[n][1]=a[n][m]=1;

                for (int i=1; i<=n; i++)
                        for (int j=1; j<=m; j++)
                                if (a[i][j]==0)
                                {
                                        int dmin=min({i-1, j-1, n-i, m-j});
                                        if (dmin)
                                                continue;
                                        bool ok=1;
                                        for (int di=-1; di<=+1; di++)
                                                for (int dj=-1; dj<=+1; dj++)
                                                {
                                                        int in=i+di, jn=j+dj;
                                                        if (1<=in && 1<=jn && in<=n && jn<=m)
                                                                ok&=(a[in][jn]==0);
                                                }
                                        if (ok)
                                                a[i][j]=1;
                                }
                for (int i=1; i<=n; i++)
                {
                        for (int j=1; j<=m; j++)
                                cout<<a[i][j];
                        cout<<"\n";
                }
        }

}