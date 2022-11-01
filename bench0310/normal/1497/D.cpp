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
        int n;
        cin >> n;
        vector<int> c(n+1,0);
        for(int i=1;i<=n;i++) cin >> c[i];
        vector<int> s(n+1,0);
        for(int i=1;i<=n;i++) cin >> s[i];
        vector<ll> dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                if(c[i]==c[j]) continue;
                ll x=abs(s[i]-s[j]);
                ll tmp=dp[i];
                dp[i]=max(dp[i],dp[j]+x);
                dp[j]=max(dp[j],tmp+x);
            }
        }
        ll res=0;
        for(int i=1;i<=n;i++) res=max(res,dp[i]);
        cout << res << "\n";
    }
    return 0;
}