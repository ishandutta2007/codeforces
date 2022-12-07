#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10;
vector <int> sv[sz];
vector <vector <int> > sp[2];
int c[sz];
void dfs(int v, int x)
{
    c[v]=x, sp[x].back().push_back(v);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(c[ne]==-1) dfs(ne, x^1);
        else if(c[ne]==x)
        {
            cout<<"NO";
            exit(0);
        }
    }
}
bitset <sz> dp[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, n1, n2, n3;
    cin>>n>>m>>n1>>n2>>n3;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=0; a<n; a++) c[a]=-1;
    for(int a=0; a<n; a++)
    {
        if(c[a]==-1)
        {
            sp[0].resize(sp[0].size()+1);
            sp[1].resize(sp[1].size()+1);
            dfs(a, 0);
        }
    }
    dp[0][0]=1;
    for(int a=0; a<sp[0].size(); a++)
    {
        for(int b=0; b<=n; b++)
        {
            if(dp[a][b])
            {
                dp[a+1][b+sp[0][a].size()]=1;
                dp[a+1][b+sp[1][a].size()]=1;
            }
        }
    }
    if(dp[sp[0].size()][n2])
    {
        cout<<"YES\n";
        char an[n];
        for(int a=sp[0].size(); a; a--)
        {
            int i=(sp[0][a-1].size()<=n2 and dp[a-1][n2-sp[0][a-1].size()]) ? 0 : 1;
            n2-=sp[i][a-1].size();
            for(int b=0; b<2; b++)
            {
                for(int c=0; c<sp[b][a-1].size(); c++)
                {
                    int v=sp[b][a-1][c];
                    if(b==i) an[v]='2';
                    else
                    {
                        if(n1) an[v]='1', n1--;
                        else an[v]='3';
                    }
                }
            }
        }
        for(int a=0; a<n; a++) cout<<an[a];
    }
    else cout<<"NO";
}