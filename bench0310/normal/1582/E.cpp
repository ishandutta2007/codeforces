#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100000;
const int S=446;
ll dp[N+2][S+1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<ll> sum(n+1,0);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        auto s=[&](int l,int r)->ll{return (sum[r]-sum[l-1]);};
        for(int i=1;i<=n+1;i++) for(int j=0;j<=S;j++) dp[i][j]=0;
        const ll inf=(1ll<<60);
        for(int i=1;i<=n+1;i++) dp[i][0]=inf;
        auto chmax=[&](ll &x,ll y){x=max(x,y);};
        int res=0;
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=S&&i+j<=n+1;j++)
            {
                if(s(i,i+j-1)<dp[i+j][j-1])
                {
                    chmax(dp[i][j],s(i,i+j-1));
                    res=max(res,j);
                }
            }
            for(int j=1;j<=S;j++) chmax(dp[i][j],dp[i+1][j]);
        }
        cout << res << "\n";
    }
    return 0;
}