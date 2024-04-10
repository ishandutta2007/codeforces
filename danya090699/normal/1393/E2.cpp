#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7, sz=1e6+10;
int dp[sz];
int SUM(int x, int y)
{
    return (x+y<mod) ? x+y : x+y-mod;
}
int DIF(int x, int y)
{
    return (x-y>=0) ? x-y : x-y+mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    string pr;
    cin>>pr;
    for(int a=0; a<=pr.size(); a++) dp[a]=1;
    for(int a=1; a<n; a++)
    {
        string s;
        cin>>s;
        string fr=pr, to=s;
        int m=max(pr.size(), s.size())+1, suf[3][m+1], pref[m], pref2[m], add[m], add2[m];

        for(int b=0; b<m; b++) add[b]=0, add2[b]=0;

        while(fr.size()<m+1) fr.push_back('.');
        while(to.size()<m+1) to.push_back('.');

        suf[0][m]=(fr[m]==to[m]);
        for(int b=m-1; b>=0; b--)
        {
            if(fr[b]!=to[b]) suf[0][b]=0;
            else suf[0][b]=1+suf[0][b+1];
        }

        suf[1][m-1]=(fr[m]==to[m-1]);
        suf[2][m-1]=(fr[m-1]==to[m]);
        for(int b=m-2; b>=0; b--)
        {
            if(fr[b+1]!=to[b]) suf[1][b]=0;
            else suf[1][b]=1+suf[1][b+1];

            if(fr[b]!=to[b+1]) suf[2][b]=0;
            else suf[2][b]=1+suf[2][b+1];
        }

        for(int b=0; b<m; b++)
        {
            if(suf[0][0]<b)
            {
                if(fr[suf[0][0]]<to[suf[0][0]]) add[b]=SUM(add[b], dp[b]);
            }
            else
            {
                add2[b]=SUM(add2[b], dp[b]);
                if(b+suf[1][b]+1<m)
                {
                    add2[b+suf[1][b]+1]=DIF(add2[b+suf[1][b]+1], dp[b]);
                    if(fr[b+suf[1][b]+1]<to[b+suf[1][b]])
                    {
                        add[b+suf[1][b]+1]=SUM(add[b+suf[1][b]+1], dp[b]);
                    }
                }
            }

            pref[b]=dp[b];
            if(b) pref[b]=SUM(pref[b], pref[b-1]);

            if(suf[0][b+1]+b==m or fr[b+1+suf[0][b+1]]<to[b+1+suf[0][b+1]]) pref2[b]=dp[b];
            else pref2[b]=0;

            if(b) pref2[b]=SUM(pref2[b], pref2[b-1]);


        }
        for(int b=0; b<m; b++)
        {
            if(b)
            {
                add[b]=SUM(add[b], add[b-1]);
                add2[b]=SUM(add2[b], add2[b-1]);
            }
            if(b<=s.size())
            {
                dp[b]=add[b];
                if(suf[0][b+1]+b==m or fr[b+1+suf[0][b+1]]<to[b+1+suf[0][b+1]])
                {
                    dp[b]=SUM(dp[b], add2[b]);
                }

                if(suf[0][0]<b)
                {
                    if(fr[suf[0][0]]<to[suf[0][0]]) dp[b]=SUM(dp[b], DIF(pref[m-1], pref[b]));
                }
                else
                {
                    if(b+suf[2][b]+1<m)
                    {
                        dp[b]=SUM(dp[b], DIF(pref2[b+suf[2][b]], pref2[b]));

                        if(fr[b+suf[2][b]]<to[b+suf[2][b]+1])
                        {
                            dp[b]=SUM(dp[b], DIF(pref[m-1], pref[b+suf[2][b]]));
                        }
                    }
                    else dp[b]=SUM(dp[b], DIF(pref2[m-1], pref2[b]));
                }
            }
            else dp[b]=0;
        }
        pr=s;
    }
    int an=0;
    for(int a=0; a<=pr.size(); a++) an=SUM(an, dp[a]);
    cout<<an;
}