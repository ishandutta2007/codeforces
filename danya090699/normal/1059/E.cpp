#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e5+10, inf=2e18;
vector <int> sv[sz];
int up[sz][20], su[sz][20], dp[sz], go[sz], an=0;
int dfs(int v)
{
    int ma=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        ma=max(ma, dfs(ne));
    }
    if(ma==0)
    {
        an++;
        return go[v]-1;
    }
    else return ma-1;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, l, s, ok=1;
    cin>>n>>l>>s;
    for(int a=1; a<=n; a++)
    {
        scanf("%lld", &su[a][0]);
        if(su[a][0]>s) ok=0;
    }
    if(ok==0) cout<<-1;
    else
    {
    up[1][0]=0, up[0][0]=0, su[0][0]=inf;
    for(int a=2; a<=n; a++)
    {
        int pr;
        scanf("%lld", &pr);
        up[a][0]=pr, sv[pr].push_back(a);
    }
    for(int a=1; a<20; a++)
    {
        for(int b=0; b<=n; b++) up[b][a]=up[up[b][a-1]][a-1];
        for(int b=0; b<=n; b++) su[b][a]=min(su[b][a-1]+su[up[b][a-1]][a-1], inf);
    }
    for(int a=0; a<=n; a++)
    {
        int v=a, va=0, h=0;
        for(int i=19; i>=0; i--)
        {
            int ne=up[v][i], add=su[v][i];
            if(h+(1<<i)<=l and va+add<=s)
            {
                h+=(1<<i), va+=add, v=ne;
            }
        }
        go[a]=h;
    }
    dfs(1);
    cout<<an;
    }
}