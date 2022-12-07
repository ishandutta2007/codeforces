#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz], tout;
int n, an[sz], dp[sz], os[sz], pr[sz];
void dfs(int v)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v]) pr[ne]=v, dfs(ne);
    }
    tout.push_back(v);
}
int cou(int k)
{
    if(an[k]==-1)
    {
        for(int a=0; a<n; a++)
        {
            int v=tout[a], ma=0, ma2=0;
            dp[v]=0;
            for(int b=0; b<sv[v].size(); b++)
            {
                int ne=sv[v][b];
                if(ne!=pr[v])
                {
                    dp[v]+=dp[ne];
                    if(os[ne]>ma)
                    {
                        ma2=ma, ma=os[ne];
                    }
                    else if(os[ne]>ma2) ma2=os[ne];
                }
            }
            if(ma+ma2+1>=k) dp[v]++, os[v]=0;
            else os[v]=ma+1;
        }
        an[k]=dp[0];
    }
    return an[k];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0);
    for(int a=1; a<=n; a++) an[a]=-1;
    int yk=n, an[n+1];
    while(yk>0)
    {
        int cu=cou(yk);
        int l=0, r=yk;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            int re=cou(mid);
            if(re==cu) r=mid;
            else l=mid;
        }
        for(int a=l+1; a<=yk; a++) an[a]=cu;
        yk=l;
    }
    for(int a=1; a<=n; a++) printf("%d\n", an[a]);
}