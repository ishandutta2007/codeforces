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
        vector dp(n,vector(n,int(-1))); //lose,draw,win
        for(int i=0;i+1<n;i++) dp[i][i+1]=(2-(s[i]==s[i+1]));
        auto mv=[&](int d,char a,char b)->int
        {
            if(d!=1) return d;
            if(a<b) return 2;
            if(a==b) return 1;
            if(a>b) return 0;
            return -1;
        };
        auto go=[&](int l,int r,char a)->int
        {
            return min(mv(dp[l+1][r],a,s[l]),mv(dp[l][r-1],a,s[r]));
        };
        for(int len=4;len<=n;len+=2)
        {
            for(int l=0;l+len-1<n;l++)
            {
                int r=l+len-1;
                dp[l][r]=max(go(l+1,r,s[l]),go(l,r-1,s[r]));
            }
        }
        if(dp[0][n-1]==2) cout << "Alice\n";
        if(dp[0][n-1]==1) cout << "Draw\n";
        if(dp[0][n-1]==0) cout << "Bob\n";
    }
    return 0;
}