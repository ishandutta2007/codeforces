#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
vector <int> sv[sz], sp;
bool us[sz];
void dfs(int v)
{
    us[v]=1;
    sp.push_back(v);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int q, pr;
        scanf("%d", &q);
        for(int b=0; b<q; b++)
        {
            int v;
            scanf("%d", &v);
            v--;
            if(b)
            {
                sv[v].push_back(pr);
                sv[pr].push_back(v);
            }
            pr=v;
        }
    }
    int an[n];
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            dfs(a);
            for(int b=0; b<sp.size(); b++)
            {
                an[sp[b]]=sp.size();
            }
            sp.clear();
        }
    }
    for(int a=0; a<n; a++) printf("%d ", an[a]);
}