#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10;
vector <int> sv[sz], sp[sz];
int c[sz], si[sz], an[sz];
void dfs(int v)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne), si[v]+=si[ne];
    }
}
void dfs2(int v)
{
    if(c[v]<sp[v].size())
    {
        an[v]=sp[v][c[v]];
        sp[v].erase(sp[v].begin()+c[v]);
    }
    else
    {
        cout<<"NO";
        exit(0);
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        for(int b=0; b<si[ne]; b++)
        {
            sp[ne].push_back(sp[v].back());
            sp[v].pop_back();
        }
        reverse(sp[ne].begin(), sp[ne].end());
        dfs2(ne);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, rt;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int pr;
        cin>>pr>>c[a];
        pr--;
        if(pr==-1) rt=a;
        else sv[pr].push_back(a);
    }
    dfs(rt);
    for(int a=1; a<=n; a++) sp[rt].push_back(a);
    dfs2(rt);
    cout<<"YES\n";
    for(int a=0; a<n; a++) cout<<an[a]<<" ";
}