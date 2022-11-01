#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=5005;
ll dp[N][N/2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,x,y;
        cin >> n >> x >> y;
        string a,b;
        cin >> a >> b;
        int c=0;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(b[i]=='1') a[i]^=('0'^'1');
            if(a[i]=='1')
            {
                c++;
                v.push_back(i);
            }
        }
        if((c%2)==0)
        {
            if(x>=y)
            {
                if(c==2&&v[0]+1==v[1]) cout << min(x,2*y) << "\n";
                else cout << ll(c/2)*y << "\n";
            }
            else
            {
                const ll inf=(1ll<<60);
                for(int i=0;i<=c;i++) for(int j=0;j<=c/2;j++) dp[i][j]=inf;
                dp[0][0]=dp[1][0]=0;
                for(int i=2;i<=c;i++)
                {
                    for(int j=c/2;j>=1;j--) dp[i][j]=min(dp[i][j],dp[i-2][j-1]+ll(v[i-1]-v[i-2])*x);
                    for(int j=0;j<=c/2;j++) dp[i][j]=min(dp[i][j],dp[i-1][j]);
                }
                ll res=inf;
                for(int i=0;i<=c/2;i++) res=min(res,dp[c][i]+ll(c-2*i)/2*y);
                cout << res << "\n";
            }
        }
        else cout << "-1\n";
    }
    return 0;
}