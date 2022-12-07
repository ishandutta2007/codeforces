#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int to[sz];
char us[sz];
bool dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(to[ne]==-1 or (!us[to[ne]] and dfs(to[ne])))
        {
            to[ne]=v;
            return true;
        }
    }
    return false;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, n1=0, n2=0, q=0;
    cin>>n>>m;
    char fi[n][m+1];
    int nu1[n-1][m], nu2[n][m-1];
    for(int a=0; a<n; a++)
    {
        scanf("%s", fi[a]);
        for(int b=0; b<m; b++) q+=(fi[a][b]=='#');
        for(int b=0; b<m-1; b++)
        {
            if(fi[a][b]=='#' and fi[a][b+1]=='#') nu2[a][b]=n2++;
            else nu2[a][b]=-1;
        }
    }
    for(int a=0; a<n-1; a++)
    {
        for(int b=0; b<m; b++)
        {
            if(fi[a][b]=='#' and fi[a+1][b]=='#')
            {
                nu1[a][b]=n1++;
                if(b)
                {
                    if(nu2[a][b-1]!=-1) sv[nu1[a][b]].push_back(nu2[a][b-1]);
                    if(nu2[a+1][b-1]!=-1) sv[nu1[a][b]].push_back(nu2[a+1][b-1]);
                }
                if(b+1<m)
                {
                    if(nu2[a][b]!=-1) sv[nu1[a][b]].push_back(nu2[a][b]);
                    if(nu2[a+1][b]!=-1) sv[nu1[a][b]].push_back(nu2[a+1][b]);
                }
            }
            else nu1[a][b]=-1;
        }
    }
    int an=0;
    for(int a=0; a<n2; a++) to[a]=-1;
    for(int a=0; a<n1; a++)
    {
        memset(us, 0, n1);
        an+=dfs(a);
    }
    cout<<q-(n1+n2-an);
}