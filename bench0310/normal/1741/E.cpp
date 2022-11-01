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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            if(dp[i-1]==1&&i+a[i]<=n) dp[i+a[i]]=1;
            if(i-a[i]-1>=0&&dp[i-a[i]-1]==1) dp[i]=1;
        }
        if(dp[n]==1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}