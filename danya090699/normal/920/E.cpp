#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
set <int> fr, sv[sz];
vector <int> an;
void dfs(int v)
{
    fr.erase(v), an.back()++;
    int x=0;
    while(fr.lower_bound(x)!=fr.end())
    {
        int ne=*fr.lower_bound(x);
        x=ne+1;
        if(sv[v].find(ne)==sv[v].end()) dfs(ne);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<n; a++) fr.insert(a);
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].insert(v), sv[v].insert(u);
    }
    for(int a=0; a<n; a++)
    {
        if(fr.find(a)!=fr.end())
        {
            an.push_back(0);
            dfs(a);
        }
    }
    sort(an.begin(), an.end());
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) printf("%d ", an[a]);
}