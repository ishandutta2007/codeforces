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
        int n,x;
        cin >> n >> x;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int c=((x+a[i]-1)/a[i]);
            if(i+c-1<=n) dp[i+c-1]=max(dp[i+c-1],dp[i-1]+1);
            dp[i]=max(dp[i],dp[i-1]);
        }
        cout << dp[n] << "\n";
    }
    return 0;
}