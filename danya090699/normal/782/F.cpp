#include <bits/stdc++.h>
using namespace std;
const int sz=510;
struct ma
{
    bitset <sz> m[sz];
};
ma fr[60][2], to[60][2], dp[61];
int n, m, cu=0, ty=0;
bool um(ma &mfr, ma &mto, ma &re)
{
    bool fo=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            re.m[a][b]=(mfr.m[a]&mto.m[b]).any();
            if(re.m[a][b]) fo=1;
        }
    }
    return fo;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            fr[0][0].m[a][b]=0, fr[0][1].m[a][b]=0;
            to[0][0].m[a][b]=0, to[0][1].m[a][b]=0;
        }
    }
    for(int a=0; a<m; a++)
    {
        int u, v, ty;
        scanf("%d%d%d", &u, &v, &ty);
        u--, v--;
        fr[0][ty].m[u][v]=1;
        to[0][ty].m[v][u]=1;
    }
    for(int a=1; a<60; a++)
    {
        um(fr[a-1][0], to[a-1][1], fr[a][0]);
        um(fr[a-1][1], to[a-1][0], fr[a][1]);
        for(int b=0; b<n; b++)
        {
            for(int c=0; c<n; c++)
            {
                to[a][0].m[c][b]=fr[a][0].m[b][c];
                to[a][1].m[c][b]=fr[a][1].m[b][c];
            }
        }
    }
    long long ans=0, inf=1e18;
    for(int a=0; a<n; a++) for(int b=0; b<n; b++) dp[0].m[a][b]=(a==b);
    for(int a=59; a>=0; a--)
    {
        bool fo=um(dp[cu], to[a][ty], dp[cu+1]);
        if(fo)
        {
            ty^=1, cu++, ans+=(1ll<<a);
        }
    }
    if(ans>inf) cout<<-1;
    else cout<<ans;
}