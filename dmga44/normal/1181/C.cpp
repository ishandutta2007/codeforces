#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1005

char a[MAXN][MAXN];
int b[MAXN][MAXN],c[MAXN][MAXN],d[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> a[i][j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            b[i][j]=b[i][j-1];
            if(a[i][j]!=a[i][j-1])
                b[i][j]=j-1;
        }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            d[i][j]=b[i][j];
            if(a[i][j]==a[i-1][j])
                d[i][j]=max(d[i][j],d[i-1][j]);
        }
    for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++)
            if(a[i][j]==a[i+1][j])
                b[i][j]=max(b[i][j],b[i+1][j]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            c[i][j]=c[i-1][j];
            if(a[i][j]!=a[i-1][j])
                c[i][j]=i-1;
        }

    ll res=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int p1=c[i][j];
            int l1=i-p1;
            int d1=d[i][j];
            if(p1)
            {
                int p2=c[p1][j];
                int l2=p1-p2;
                int d2=d[p1][j];
                if(p2 && l1==l2)
                {
                    int p3=c[p2][j];
                    if(p3>p2-l1)
                        continue;
                    else
                        p3=p2-l1;
                    p3++;
                    int d3=b[p3][j];
                    res+=(j-(max(d1,max(d2,d3))));
                }
            }
        }
    db(res)

    return 0;
}