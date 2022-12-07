#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    const int n2=n;
    string s[n2];
    for(int a=0; a<n; a++) cin>>s[a];
    bool sw=0;
    if(n<m) swap(n, m), sw=1;

    if(m==1) cout<<0;
    else if(m==2 or m==3)
    {
        int fi[n];
        for(int a=0; a<n; a++)
        {
            fi[a]=0;
            for(int b=0; b<m; b++)
            {
                int x;
                if(sw==0) x=s[a][b]-'0';
                else x=s[b][a]-'0';
                if(x) fi[a]+=(1<<b);
            }
        }
        //cout<<fi[0]<<" "<<fi[1]<<" "<<fi[2]<<"\n";
        int go[1<<m][1<<m];
        for(int fr=0; fr<(1<<m); fr++)
        {
            for(int to=0; to<(1<<m); to++)
            {
                go[fr][to]=1;
                for(int i=0; i+1<m; i++)
                {
                    int q=0;
                    if(fr&(1<<i)) q^=1;
                    if(fr&(1<<(i+1))) q^=1;
                    if(to&(1<<i)) q^=1;
                    if(to&(1<<(i+1))) q^=1;
                    if(q==0) go[fr][to]=0;
                }
                //cout<<fr<<" "<<to<<" "<<go[fr][to]<<"\n";
            }
        }
        int dp[n][1<<m];
        for(int a=0; a<n; a++) for(int mask=0; mask<(1<<m); mask++) dp[a][mask]=inf;
        for(int mask=0; mask<(1<<m); mask++) dp[0][mask]=__builtin_popcount(mask^fi[0]);
        for(int a=0; a+1<n; a++)
        {
            for(int mask=0; mask<(1<<m); mask++)
            {
                if(dp[a][mask]!=inf)
                {
                    for(int to=0; to<(1<<m); to++)
                    {
                        if(go[mask][to])
                        {
                            dp[a+1][to]=min(dp[a+1][to], dp[a][mask]+__builtin_popcount(to^fi[a+1]));
                        }
                    }
                }
            }
        }
        int an=inf;
        for(int mask=0; mask<(1<<m); mask++) an=min(an, dp[n-1][mask]);
        if(an==inf) cout<<-1;
        else cout<<an;
    }
    else cout<<-1;
}