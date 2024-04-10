#include <bits/stdc++.h>
#define int short int
using namespace std;
const int inf=1e4;
int dp[1<<14], dp2[1<<14][14][14], pr[1<<14][3], pr2[1<<14][14][14], sm[14][14];
void way(int mask, int f, int t)
{
    while(mask>(1<<f))
    {
        int nt=pr2[mask][f][t];
        cout<<nt+1<<" "<<t+1<<"\n";
        mask-=(1<<t), t=nt;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sm[u][v]=1, sm[v][u]=1;
    }
    for(int a=0; a<n; a++) dp2[1<<a][a][a]=1;
    for(int q=1; q<n; q++)
    {
        for(int mask=0; mask<(1<<n); mask++)
        {
            if(__builtin_popcount(mask)==q)
            {
                for(int a=0; a<n; a++)
                {
                    for(int b=0; b<n; b++)
                    {
                        if(dp2[mask][a][b])
                        {
                            for(int c=0; c<n; c++)
                            {
                                if((mask&(1<<c))==0 and sm[b][c])
                                {
                                    dp2[mask+(1<<c)][a][c]=1;
                                    pr2[mask+(1<<c)][a][c]=b;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(int a=0; a<(1<<n); a++) dp[a]=inf;
    dp[1]=0;
    for(int q=1; q<n; q++)
    {
        for(int mask=0; mask<(1<<n); mask++)
        {
            if(__builtin_popcount(mask)==q)
            {
                if(dp[mask]!=inf)
                {
                    for(int mask2=(1<<n)-1-mask; mask2; mask2=(mask2-1)&((1<<n)-1-mask))
                    {
                        int va=dp[mask]+__builtin_popcount(mask2)+1;
                        for(int a=0; a<n; a++)
                        {
                            if(mask&(1<<a))
                            {
                                for(int b=0; b<n; b++)
                                {
                                    if((mask&(1<<b) and dp2[mask2|(1<<a)|(1<<b)][a][b]) or
                                    (mask2&(1<<b) and dp2[mask2|(1<<a)][a][b] and sm[a][b] and __builtin_popcount(mask2)>1))
                                    {
                                        if(dp[mask|mask2]>va)
                                        {
                                            dp[mask|mask2]=va;
                                            pr[mask|mask2][0]=mask2;
                                            pr[mask|mask2][1]=a;
                                            pr[mask|mask2][2]=b;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int mask=(1<<n)-1;
    cout<<dp[mask]<<"\n";
    while(mask!=1)
    {
        int mask2=pr[mask][0], a=pr[mask][1], b=pr[mask][2];
        if(mask2&(1<<b))
        {
            cout<<a+1<<" "<<b+1<<"\n";
            way(mask2^(1<<a), a, b);
        }
        else way(mask2^(1<<a)^(1<<b), a, b);
        mask^=mask2;
    }
}