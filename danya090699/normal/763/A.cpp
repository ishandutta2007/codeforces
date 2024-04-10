//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int n, dow[sz], si[sz], co[sz], cq[sz], fo=0;
vector <int> sv[sz];
void dfs(int v, int pr)
{
    dow[v]=co[v], si[v]=1;
    int lef, cc, ok=1;
    if(pr==-1)
    {
        lef=0, cc=-2;
    }
    else
    {
        lef=cq[co[pr]], cc=co[pr];
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v);
            if(dow[v]!=dow[ne]) dow[v]=-1;
            if(dow[ne]==-1) ok=0;
            si[v]+=si[ne];
            if(dow[ne]==cc) lef-=si[ne];
        }
    }
    if(co[v]==cc) lef--;
    if(ok and lef==n-si[v] and fo==0)
    {
        cout<<"YES\n";
        cout<<v+1;
        fo=1;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<sz; a++) cq[a]=0;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=0; a<n; a++)
    {
        cin>>co[a];
        cq[co[a]]++;
    }
    dfs(0, -1);
    if(fo==0) cout<<"NO";
}