#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T)
    {
        T--;
        string s, t;
        cin>>s>>t;
        bool ok=0;
        for(int a=0; a<=t.size(); a++)
        {
            int dp[s.size()+1][a+1];
            for(int b=0; b<=s.size(); b++) for(int c=0; c<=a; c++) dp[b][c]=-1;
            dp[0][0]=0;
            for(int b=0; b<s.size(); b++)
            {
                for(int c=0; c<=a; c++)
                {
                    if(dp[b][c]!=-1)
                    {
                        if(c<a and s[b]==t[c]) dp[b+1][c+1]=max(dp[b+1][c+1], dp[b][c]);
                        int add=0;
                        if(dp[b][c]<t.size()-a and s[b]==t[a+dp[b][c]]) add=1;
                        dp[b+1][c]=max(dp[b+1][c], dp[b][c]+add);
                    }
                }
            }
            if(dp[s.size()][a]==t.size()-a) ok=1;
        }
        cout<<(ok ? "YES\n" : "NO\n");
    }
}