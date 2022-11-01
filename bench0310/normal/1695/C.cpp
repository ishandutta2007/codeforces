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
        vector mn(n+1,vector(m+1,int(1<<30)));
        vector mx(n+1,vector(m+1,int(-(1<<30))));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int a;
                cin >> a;
                if(i==1&&j==1) mn[1][1]=mx[1][1]=a;
                else
                {
                    mn[i][j]=min(mn[i-1][j],mn[i][j-1])+a;
                    mx[i][j]=max(mx[i-1][j],mx[i][j-1])+a;
                }
            }
        }
        if(((n+m-1)%2)==0&&mn[n][m]<=0&&0<=mx[n][m]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}