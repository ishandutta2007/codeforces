#include <bits/stdc++.h>
using namespace std;
const int sz=1e3+10, sz2=1e5+10;
vector <int> sv[sz];
int w[sz][sz], q=0, an[sz2][3];
int dfs2(int v, int pr, int x)
{
    w[v][pr]-=x, w[pr][v]-=x;
    for(int a=0; a<sv[v].size(); a++)
    {
        if(sv[v][a]!=pr) return dfs2(sv[v][a], v, x);
    }
    return v;
}
void dfs(int v, int pr)
{
    for(int a=0; a+3<=sv[v].size(); a++)
    {
        int v1=sv[v][a], v2=sv[v][a+1], v3=sv[v][a+2];
        int w1=w[v][v1], w2=w[v][v2], w3=w[v][v3];
        int su=(w1+w2+w3)/2;
        an[q][0]=dfs2(v1, v, su-w3), an[q][1]=dfs2(v2, v, su-w3), an[q][2]=su-w3, q++;
        an[q][0]=dfs2(v2, v, su-w1), an[q][1]=dfs2(v3, v, su-w1), an[q][2]=su-w1, q++;
        an[q][0]=dfs2(v1, v, su-w2), an[q][1]=dfs2(v3, v, su-w2), an[q][2]=su-w2, q++;
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs(ne, v);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    if(n==2)
    {
        int u, v, w;
        cin>>u>>v>>w;
        cout<<"YES\n1\n"<<u<<" "<<v<<" "<<w;
        return 0;
    }
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
        cin>>w[u][v];
        w[v][u]=w[u][v];
    }
    for(int a=0; a<n; a++)
    {
        if(sv[a].size()==2)
        {
            cout<<"NO";
            return 0;
        }
    }
    for(int a=0; a<n; a++)
    {
        if(sv[a].size()>1)
        {
            dfs(a, a);
            break;
        }
    }
    cout<<"YES\n"<<q<<"\n";
    for(int a=0; a<q; a++)
    {
        cout<<an[a][0]+1<<" "<<an[a][1]+1<<" "<<an[a][2]<<"\n";
    }
}