#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string shift(string s)
{
    return (s.substr(1,(int)s.size()-1)+s[0]);
}

int diff(string a,string b)
{
    int d=0;
    for(int i=0;i<(int)a.size();i++) d+=(a[i]!=b[i]);
    return d;
}

int solve(string s)
{
    int n=s.size();
    s="$"+s;
    vector<int> dp(n+1,n);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(i>=2) dp[i]=min(dp[i],dp[i-2]+diff(s.substr(i-1,2),"RL"));
        if(i>=3) dp[i]=min(dp[i],dp[i-3]+min(diff(s.substr(i-2,3),"RLL"),diff(s.substr(i-2,3),"RRL")));
        if(i>=4) dp[i]=min(dp[i],dp[i-4]+diff(s.substr(i-3,4),"RRLL"));
    }
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int res=solve(s);
        for(int i=0;i<4;i++)
        {
            s=shift(s);
            res=min(res,solve(s));
        }
        cout << res << "\n";
    }
    return 0;
}