//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int n;
double an=0;
void dfs(int v, int pr, int le, double ve)
{
    int q=sv[v].size();
    if(pr!=-1) q--;
    if(q==0)
    {
        an+=ve*le;
    }
    else
    {
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a];
            if(ne!=pr) dfs(ne, v, le+1, ve/q);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, -1, 0, 1);
    cout<<fixed<<setprecision(10)<<an;
}