#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, pq=0, *pe, rq;
bool *us;
vector <int> *sv;
void dfs(int v)
{
    us[v]=1;
    rq+=sv[v].size()+pe[v];
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%lld%lld", &n, &m);
    pe=new int[n], us=new bool[n], sv=new vector <int>[n];
    for(int a=0; a<n; a++)
    {
        us[a]=0, pe[a]=0;
    }
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        if(u==v)
        {
            pe[v]+=2, pq++;
        }
        else
        {
            sv[u].push_back(v);
            sv[v].push_back(u);
        }
    }
    bool pos=1;
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            rq=0;
            dfs(a);
            if(rq!=m*2 and rq!=0) pos=0;
        }
    }
    if(pos)
    {
        int an=(m-pq)*pq;
        if(pq>1) an+=(pq*(pq-1))/2;
        for(int a=0; a<n; a++)
        {
            int x=sv[a].size();
            if(x>1) an+=(x*(x-1))/2;
        }
        cout<<an;
    }
    else cout<<0;
}