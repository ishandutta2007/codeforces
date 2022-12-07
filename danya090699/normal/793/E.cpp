#include <bits/stdc++.h>
using namespace std;
const int sz=5020;
int n, *pr, *we, lq=0;
vector <int> *sv;
bitset <sz> dp[sz];
bool *us;
void dfs(int v)
{
    we[v]=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne);
        we[v]+=we[ne];
    }
    if(we[v]==0)
    {
        we[v]=1, lq++;
    }
}
bool solve(int v1, int v2)
{
    for(int a=0; a<n; a++) us[a]=0;
    int cu=v1;
    while(cu!=-1)
    {
        us[cu]=1;
        cu=pr[cu];
    }
    cu=v2;
    while(cu!=-1)
    {
        us[cu]=1;
        cu=pr[cu];
    }
    vector <int> sub;
    for(int a=0; a<n; a++)
    {
        if(us[a])
        {
            for(int b=0; b<sv[a].size(); b++)
            {
                int ne=sv[a][b];
                if(us[ne]==0) sub.push_back(we[ne]);
            }
        }
    }
    int m=sub.size();
    for(int a=0; a<=m; a++) for(int b=0; b<=lq; b++) dp[a][b]=0;
    dp[0][0]=1;
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<lq; b++)
        {
            if(dp[a][b])
            {
                dp[a+1][b]=1;
                dp[a+1][b+sub[a]]=1;
            }
        }
    }
    return dp[m][(lq-2)/2];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int v1, v2, v3, v4;
    cin>>n>>v1>>v2>>v3>>v4;
    v1--, v2--, v3--, v4--;
    pr=new int[n], we=new int[n], us=new bool[n], sv=new vector <int>[n];
    pr[0]=-1;
    for(int a=1; a<n; a++)
    {
        int v;
        cin>>v;
        v--;
        pr[a]=v;
        sv[v].push_back(a);
    }
    dfs(0);
    if(lq%2==1) cout<<"NO";
    else
    {
        if(solve(v1, v2) and solve(v3, v4)) cout<<"YES";
        else cout<<"NO";
    }
}