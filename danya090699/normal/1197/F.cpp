#include <bits/stdc++.h>
using namespace std;
const int sz=64, mod=998244353;
int ma[30][sz][sz], ma2[sz][3];
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <pair <int, int> > sp[n];
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        sp[a].push_back({x, -1});
    }
    int m;
    cin>>m;
    for(int a=0; a<m; a++)
    {
        int x, y, c;
        cin>>x>>y>>c;
        x--, y--, c--;
        sp[x].push_back({y, c});
    }
    int f[3][3];
    for(int a=0; a<3; a++) for(int b=0; b<3; b++) cin>>f[a][b];
    for(int a=0; a<sz; a++)
    {
        int gr[3], x=a;
        for(int b=0; b<3; b++) gr[b]=x%4, x/=4;
        for(int b=0; b<3; b++)
        {
            bool us[4];
            for(int c=0; c<4; c++) us[c]=0;
            for(int c=0; c<3; c++) if(f[b][c]) us[gr[c]]=1;
            int mex;
            for(int c=3; c>=0; c--) if(us[c]==0) mex=c;
            int mask=mex+4*gr[0]+16*gr[1];
            ma[0][a][mask]++;
            ma2[a][b]=mask;
        }
    }
    for(int i=1; i<30; i++)
    {
        for(int a=0; a<sz; a++)
        {
            for(int b=0; b<sz; b++)
            {
                for(int c=0; c<sz; c++) ma[i][a][b]=(ma[i][a][b]+1ll*ma[i-1][a][c]*ma[i-1][c][b])%mod;
            }
        }
    }
    int dp3[8], dp4[8];
    for(int a=0; a<8; a++) dp3[a]=0, dp4[a]=0;
    dp3[0]=1;
    for(int a=0; a<n; a++)
    {
        sort(sp[a].begin(), sp[a].end());
        int dp[sz], dp2[sz], pr=0;
        for(int b=0; b<sz; b++) dp[b]=0, dp2[b]=0;
        dp[sz-1]=1;
        for(int b=0; b<sp[a].size(); b++)
        {
            int p=sp[a][b].first, C=sp[a][b].second, l=p-pr;
            int i=0;
            while(l)
            {
                if(l&1)
                {
                    for(int c=0; c<sz; c++)
                    {
                        for(int d=0; d<sz; d++) dp2[d]=(dp2[d]+1ll*dp[c]*ma[i][c][d])%mod;
                    }
                    for(int c=0; c<sz; c++) dp[c]=dp2[c], dp2[c]=0;
                }
                l>>=1, i++;
            }
            if(C!=-1)
            {
                for(int c=0; c<sz; c++)
                {
                    int ne=ma2[c][C];
                    dp2[ne]=(dp2[ne]+dp[c])%mod;
                }
                for(int c=0; c<sz; c++)
                {
                    dp[c]=dp2[c], dp2[c]=0;
                }
            }
            else
            {
                for(int c=0; c<sz; c++)
                {
                    int gr=c%4;
                    for(int d=0; d<8; d++) dp4[d^gr]=(dp4[d^gr]+1ll*dp3[d]*dp[c])%mod;
                }
                for(int c=0; c<8; c++) dp3[c]=dp4[c], dp4[c]=0;
            }
            pr=p+1;
        }
    }
    cout<<dp3[0];
}