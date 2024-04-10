#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10;
int n, x, dp[sz][sz], dp2[sz][sz], fr[sz], to[sz], pr[sz], sk[sz], inf=1e9+20;
vector <int> sv[sz];
void dfs(int v)
{
    int q=sv[v].size();
    for(int a=0; a<q; a++) dfs(sv[v][a]);
    for(int a=0; a<sz; a++)
    {
        fr[a]=inf, to[a]=inf;
    }
    fr[0]=0, fr[1]=pr[v];
    for(int a=0; a<q; a++)
    {
        int ne=sv[v][a];
        for(int b=0; b<sz; b++)
        {
            if(fr[b]!=inf)
            {
                to[b]=min(to[b], fr[b]);
                for(int c=1; c<sz; c++)
                {
                    if(dp[ne][c]==inf) break;
                    else to[b+c]=min(to[b+c], fr[b]+dp[ne][c]);
                }
            }
        }
        for(int b=0; b<sz; b++)
        {
            fr[b]=to[b], to[b]=inf;
        }
    }
    for(int a=0; a<sz; a++) dp[v][a]=fr[a];
    for(int a=0; a<sz; a++)
    {
        fr[a]=inf, to[a]=inf;
    }
    fr[1]=pr[v]-sk[v];
    for(int a=0; a<q; a++)
    {
        int ne=sv[v][a];
        for(int b=0; b<sz; b++)
        {
            if(fr[b]!=inf)
            {
                to[b]=min(to[b], fr[b]);
                for(int c=1; c<sz; c++)
                {
                    if(dp[ne][c]==inf) break;
                    else to[b+c]=min(to[b+c], fr[b]+dp[ne][c]);
                }
                for(int c=1; c<sz; c++)
                {
                    if(dp2[ne][c]==inf) break;
                    else to[b+c]=min(to[b+c], fr[b]+dp2[ne][c]);
                }
            }
        }
        for(int b=0; b<sz; b++)
        {
            fr[b]=to[b], to[b]=inf;
        }
    }
    for(int a=0; a<sz; a++) dp2[v][a]=fr[a];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>x;
    for(int a=0; a<n; a++)
    {
        cin>>pr[a]>>sk[a];
        if(a>0)
        {
            int pre;
            cin>>pre;
            pre--, sv[pre].push_back(a);
        }
    }
    dfs(0);
    for(int a=n; a>=0; a--)
    {
        if(dp[0][a]<=x or dp2[0][a]<=x)
        {
            cout<<a;
            break;
        }
    }
}