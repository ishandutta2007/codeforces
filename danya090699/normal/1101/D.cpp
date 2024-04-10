#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz], sp[sz];
bool ok[sz], us[sz];
int dp[sz], be=0;
void dfs(int v, int pr)
{
    us[v]=1;
    be=max(be, 1);
    dp[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ok[ne] and ne!=pr)
        {
            dfs(ne, v);
            be=max(be, dp[v]+dp[ne]);
            dp[v]=max(dp[v], dp[ne]+1);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        for(int b=2; b*b<=x; b++)
        {
            if(x%b==0)
            {
                sp[b].push_back(a);
                while(x%b==0) x/=b;
            }
        }
        if(x>1) sp[x].push_back(a);
    }
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=2; a<sz; a++)
    {
        if(sp[a].size())
        {
            //cout<<a<<" ";
            for(int b=0; b<sp[a].size(); b++) ok[sp[a][b]]=1;
            for(int b=0; b<sp[a].size(); b++)
            {
                int v=sp[a][b];
                if(us[v]==0) dfs(v, v);
            }
            for(int b=0; b<sp[a].size(); b++)
            {
                ok[sp[a][b]]=0, us[sp[a][b]]=0;
            }
        }
    }
    cout<<be;
}