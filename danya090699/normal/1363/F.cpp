#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s, t;
        cin>>n>>s>>t;
        vector <int> st[26];
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        int mi=0, dp[n+1][n+1], ok=1;
        for(int a=0; a<=n; a++) for(int b=0; b<=n; b++) dp[a][b]=-1;
        dp[0][0]=0;
        for(int a=0; a<n; a++) st[s[a]-'a'].push_back(a);
        for(int a=0; a<26; a++) reverse(st[a].begin(), st[a].end());
        for(int a=0; a<n; a++)
        {
            int yk=0;
            for(int b=0; b<=n; b++)
            {
                if(dp[a][b]!=-1)
                {
                    yk=max(yk, max(b, mi));
                    while(yk<n and s[yk]!=t[a]) yk++;
                    if(yk!=n) dp[a+1][yk+1]=max(dp[a+1][yk+1], dp[a][b]+1);
                    dp[a+1][b]=max(dp[a+1][b], dp[a][b]);
                }
            }
            if(st[t[a]-'a'].size())
            {
                mi=max(mi, st[t[a]-'a'].back()+1);
                st[t[a]-'a'].pop_back();
            }
            else
            {
                ok=0;
                break;
            }
        }
        if(ok)
        {
            int an=n;
            for(int a=0; a<=n; a++) an=min(an, n-dp[n][a]);
            cout<<an<<"\n";
        }
        else cout<<"-1\n";
    }
}