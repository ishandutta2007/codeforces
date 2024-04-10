#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int q[2]={0, 0};
int d[sz];
void dfs(int v, int pr, int le)
{
    d[v]=le, q[le]++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs(ne, v, le^1);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, -1, 0);
    long long an=0;
    for(int a=0; a<n; a++)
    {
        int x=d[a];
        an+=q[(x^1)]-sv[a].size();
    }
    cout<<an/2;
}