#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        map<int,int> a,b;
        vector x(n+1,vector(m+1,int(0)));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> x[i][j];
                a[i+j]+=x[i][j];
                b[i-j]+=x[i][j];
            }
        }
        int res=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                res=max(res,a[i+j]+b[i-j]-x[i][j]);
            }
        }
        cout << res << "\n";
    }
    return 0;
}