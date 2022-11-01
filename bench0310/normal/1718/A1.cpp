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
        map<int,int> m;
        m[0]=0;
        int x=0;
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            x^=a;
            dp[i]=dp[i-1]+1;
            if(m.contains(x)) dp[i]=min(dp[i],dp[m[x]]+i-m[x]-1);
            m[x]=i;
        }
        cout << dp[n] << "\n";
    }
    return 0;
}