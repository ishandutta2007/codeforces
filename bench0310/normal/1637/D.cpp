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
        int sum=0;
        ll res=0;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            res+=((n-2)*a[i]*a[i]);
            sum+=a[i];
        }
        vector<int> b(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> b[i];
            res+=((n-2)*b[i]*b[i]);
            sum+=b[i];
        }
        vector<bool> dp(sum+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            vector<bool> ndp(sum+1,0);
            for(int j=0;j<=sum;j++)
            {
                if(dp[j])
                {
                    if(j+a[i]<=sum) ndp[j+a[i]]=1;
                    if(j+b[i]<=sum) ndp[j+b[i]]=1;
                }
            }
            dp=ndp;
        }
        ll mn=(1ll<<60);
        for(ll i=0;i<=sum;i++) if(dp[i]) mn=min(mn,i*i+(sum-i)*(sum-i));
        cout << res+mn << "\n";
    }
    return 0;
}