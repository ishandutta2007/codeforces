#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <int> dp[n];
    string s[n];
    for(int a=0; a<n; a++)
    {
        cin>>s[a];
        dp[a].resize(s[a].size()+1);
    }
    for(int a=0; a<dp[0].size(); a++) dp[0][a]=1;
    for(int a=0; a+1<n; a++)
    {
        string fr=s[a]+"..", to=s[a+1]+"..";
        while(fr.size()<to.size()) fr.push_back('.');
        while(to.size()<fr.size()) to.push_back('.');
        int m=fr.size(), pref[3][m];

        pref[0][m-1]=(fr[m-1]==to[m-1]);
        for(int b=m-2; b>=0; b--)
        {
            if(fr[b]!=to[b]) pref[0][b]=0;
            else pref[0][b]=pref[0][b+1]+1;
        }

        pref[1][m-2]=(fr[m-2]==to[m-1]);
        for(int b=m-3; b>=0; b--)
        {
            if(fr[b]!=to[b+1]) pref[1][b]=0;
            else pref[1][b]=pref[1][b+1]+1;
        }

        pref[2][m-2]=(fr[m-1]==to[m-2]);
        for(int b=m-3; b>=0; b--)
        {
            if(fr[b+1]!=to[b]) pref[2][b]=0;
            else pref[2][b]=pref[2][b+1]+1;
        }

        for(int b=0; b<dp[a].size(); b++)
        {
            for(int c=0; c<dp[a+1].size(); c++)
            {
                int l=min(b, c), r=max(b, c), add=dp[a][b];
                if(pref[0][0]>=l)
                {
                    int i=(b>c) ? 1 : 2;
                    if(pref[i][l]>=r-l)
                    {
                        if(pref[0][r+1]<fr.size()-(r+1) and fr[r+1+pref[0][r+1]]>to[r+1+pref[0][r+1]]) add=0;
                    }
                    else
                    {
                        if(b>c and fr[l+pref[1][l]]>to[l+1+pref[1][l]]) add=0;

                        if(b<c and fr[l+1+pref[2][l]]>to[l+pref[2][l]]) add=0;
                    }
                }
                else if(fr[pref[0][0]]>to[pref[0][0]]) add=0;

                dp[a+1][c]+=add;
                if(dp[a+1][c]>=mod) dp[a+1][c]-=mod;
            }
        }
    }
    int an=0;
    for(int a=0; a<dp[n-1].size(); a++) an=(an+dp[n-1][a])%mod;
    cout<<an;
}