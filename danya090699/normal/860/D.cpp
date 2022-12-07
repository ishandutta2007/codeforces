//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz];
int an[sz][3], q=0, timer=0;
int tin[sz];
bool dfs(int v, int pr)
{
    tin[v]=timer, timer++;
    vector <int> sp;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(tin[ne]==-1)
        {
            if(dfs(ne, v)) sp.push_back(ne);
        }
        else
        {
            if(tin[ne]<tin[v] and ne!=pr) sp.push_back(ne);
        }
    }
    for(int a=1; a<sp.size(); a+=2)
    {
        an[q][0]=sp[a-1], an[q][1]=v, an[q][2]=sp[a], q++;
    }
    if(sp.size()%2==1 and pr!=-1)
    {
        an[q][0]=sp.back(), an[q][1]=v, an[q][2]=pr, q++;
        return false;
    }
    else return true;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=0; a<n; a++) tin[a]=-1;
    for(int a=0; a<n; a++)
    {
        if(tin[a]==-1) dfs(a, -1);
    }
    cout<<q<<"\n";
    for(int a=0; a<q; a++) printf("%d %d %d\n", an[a][0]+1, an[a][1]+1, an[a][2]+1);
}