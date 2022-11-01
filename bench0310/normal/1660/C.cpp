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
        string s;
        cin >> s;
        int n=s.size();
        s="$"+s;
        vector<int> dp(n+1,0);
        vector<int> p(26,-1);
        for(int i=1;i<=n;i++)
        {
            int c=(s[i]-'a');
            dp[i]=dp[i-1];
            if(p[c]!=-1) dp[i]=max(dp[i],dp[p[c]-1]+2);
            p[c]=i;
        }
        cout << n-dp[n] << "\n";
    }
    return 0;
}