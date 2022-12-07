#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int ma[sz];
void dfs(int v)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        ma[ne]=max(ma[v], ma[ne]);
        dfs(ne);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin>>s>>t;
    int m=t.size();
    t+="#"+s;
    int n=t.size();
    int pf[n];
    pf[0]=0;
    sv[0].push_back(1);
    for(int a=1; a<n; a++)
    {
        int te=pf[a-1];
        while(te)
        {
            if(t[te]!=t[a]) te=pf[te-1];
            else break;
        }
        if(t[te]==t[a]) te++;
        pf[a]=te;
        if(a<m)
        {
            sv[te].push_back(a+1);
        }
    }
    int zf[n], l=0, r=-1;
    zf[0]=0;
    for(int a=1; a<=m; a++)
    {
        zf[a]=0;
        if(r>=a) zf[a]=min(zf[a-l], r-a+1);
        while(a+zf[a]<m)
        {
            if(t[zf[a]]==t[a+zf[a]]) zf[a]++;
            else break;
        }
        if(a+zf[a]-1>r) l=a, r=a+zf[a]-1;
        ma[a]=zf[a];
    }
    dfs(0);
    long long an=0;
    for(int a=m+1; a<n; a++)
    {
        int f=pf[a];
        if(f+m+1>a) f=pf[f-1];
        an+=m-ma[f];
    }
    cout<<an;
}