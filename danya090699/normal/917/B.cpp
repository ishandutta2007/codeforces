#include <bits/stdc++.h>
using namespace std;
const int sz=110;
int dp[sz][sz][26];
vector <pair <int, int> > sv[sz];
int lazy(int v1, int v2, int sy)
{
    if(dp[v1][v2][sy]==-1)
    {
        dp[v1][v2][sy]=0;
        for(int a=0; a<sv[v1].size(); a++)
        {
            int ne=sv[v1][a].first, nsy=sv[v1][a].second;
            if(nsy>=sy)
            {
                if(lazy(v2, ne, nsy)==0) dp[v1][v2][sy]=1;
            }
        }
    }
    return dp[v1][v2][sy];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<n; a++) for(int b=0; b<n; b++) for(int c=0; c<26; c++) dp[a][b][c]=-1;
    for(int a=0; a<m; a++)
    {
        int u, v;
        char sy;
        cin>>u>>v>>sy;
        u--, v--;
        sv[u].push_back(make_pair(v, sy-'a'));
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            if(lazy(a, b, 0)) cout<<"A";
            else cout<<"B";
        }
        cout<<"\n";
    }
}