#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int mod=1000000007;
    auto add=[&](int a,int b)->int{return (a+b)%mod;};
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> dp(n+1,0);
        dp[0]=1;
        int res=0;
        for(int i=1;i<=k;i++)
        {
//            cout << "in " << i << endl;
//            for(int j=0;j<=n;j++) cout << dp[j] << " ";
//            cout << endl;
            vector<int> ndp(n+1,0);
            int sum=0;
            if(i&1) //right
            {
                for(int j=0;j<=n;j++)
                {
                    ndp[j]=sum;
                    sum=add(sum,dp[j]);
                }
            }
            else //left
            {
                for(int j=n;j>=1;j--)
                {
                    ndp[j]=sum;
                    sum=add(sum,dp[j]);
                }
            }
            res=add(res,sum);
            dp=ndp;
        }
        cout << res << "\n";
    }
    return 0;
}