#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int pr[sz], dp[sz], h[sz], di=0, x, y;
void dfs(int v)
{
    dp[v]=v;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            pr[ne]=v, h[ne]=h[v]+1, dfs(ne);
            if((h[dp[v]]-h[v])+(h[dp[ne]]-h[v])>di)
            {
                di=(h[dp[v]]-h[v])+(h[dp[ne]]-h[v]), x=dp[v], y=dp[ne];
            }
            if(h[dp[ne]]>h[dp[v]]) dp[v]=dp[ne];
        }
    }
}
bool error;
vector <int> sp;
void dfs2(int v, int pr, int h)
{
    if(h>=sp.size()) sp.push_back(sv[v].size());
    else if(sp[h]!=sv[v].size()) error=1;

    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs2(ne, v, h+1);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;

    if(n==1)
    {
        cout<<1;
        return 0;
    }

    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0);
    if(h[x]<h[y]) swap(x, y);
    int ce=x, ok=1;
    for(int a=0; a<di/2; a++) ce=pr[ce];


    map <vector <int>, pair <int, int> > se;

    for(int a=0; a<sv[ce].size(); a++)
    {
        error=0, sp.clear();
        dfs2(sv[ce][a], ce, 0);

        //cout<<sp[0]<<" "<<sp[1]<<"\n"<<error<<"\n";

        if(error==0)
        {
            if(se.find(sp)==se.end()) se[sp]={1, sv[ce][a]};
            else se[sp].first++;
        }
        else ok=0;
    }

    //cout<<ce;

    if(ok==0) se.clear();

    if(se.size()==1) cout<<ce+1;
    else if(se.size()==2)
    {
        int an=-1;
        for(auto it=se.begin(); it!=se.end(); it++)
        {
            vector <int> sp=(*it).first;
            if((*it).second.first==1)
            {
                int ok=1;
                for(int a=0; a<sp.size(); a++) if(sp[a]>2) ok=0;
                if(ok)
                {
                    int v=(*it).second.second, pr=ce;
                    while(sv[v].size()>1)
                    {
                        if(sv[v][0]==pr) pr=v, v=sv[v][1];
                        else pr=v, v=sv[v][0];
                    }
                    an=v;
                }
            }
        }
        if(an!=-1) cout<<an+1;
        else cout<<-1;
    }
    else cout<<-1;
}