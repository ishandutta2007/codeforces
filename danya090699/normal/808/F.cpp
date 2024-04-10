#include <bits/stdc++.h>
using namespace std;
const int sz=110, sz2=2e5+10, inf=1e9;
int s, t;
struct re
{
    int to, cap;
};
vector <int> sv[sz];
vector <re> edges;
void add_edge(int u, int v, int cap)
{
    sv[u].push_back(edges.size());
    edges.push_back({v, cap});
    sv[v].push_back(edges.size());
    edges.push_back({u, 0});// {v, u, cap} for bidirectional
}
bool us[sz];
int dfs(int v, int flow)
{
    us[v]=1;
    if(v==t) return flow;
    for(int a=0; a<sv[v].size(); a++)
    {
        int i=sv[v][a];
        int ne=edges[i].to;
        if(edges[i].cap>0 and us[ne]==0)
        {
            int re=dfs(ne, min(flow, edges[i].cap));
            if(re)
            {
                edges[i].cap-=re;
                edges[i^1].cap+=re;
                return re;
            }
        }
    }
    return 0;
}
struct el
{
    int p, c, l;
};
bool comp(el a, el b){return a.l<b.l;}
bitset <sz2> pri;
int main()
{
    for(int a=2; a<sz2; a++)
    {
        if(!pri[a])
        {
            for(int b=a+a; b<sz2; b+=a) pri[b]=1;
        }
    }
    pri.flip();
    //freopen("input.txt", "r", stdin);
    int n, k, va1=0, su1=0, su2=0, flow=0;
    cin>>n>>k;
    s=n+1, t=n+2;
    add_edge(s, n, 0);
    el ar[n];
    for(int a=0; a<n; a++) scanf("%d%d%d", &ar[a].p, &ar[a].c, &ar[a].l);
    sort(ar, ar+n, comp);
    for(int a=0; a<=n; a++)
    {
        while(1)
        {
            for(int a=0; a<n+3; a++) us[a]=0;
            int add=dfs(s, inf);
            flow+=add;
            if(!add) break;
        }
        if(su2+su1-flow>=k)
        {
            cout<<ar[a-1].l;
            break;
        }
        if(a<n)
        {
            if(ar[a].c==1)
            {
                if(va1<ar[a].p)
                {
                    edges[0].cap+=ar[a].p-va1, su1+=ar[a].p-va1, va1=ar[a].p;
                }
            }
            else
            {
                if(ar[a].c&1) add_edge(s, a, ar[a].p), su1+=ar[a].p;
                else add_edge(a, t, ar[a].p), su2+=ar[a].p;

                for(int b=0; b<a; b++)
                {
                    if(ar[b].c!=1 and pri[ar[a].c+ar[b].c])
                    {
                        if(ar[a].c&1) add_edge(a, b, inf);
                        else add_edge(b, a, inf);
                    }
                }

                if(pri[ar[a].c+1]) add_edge(n, a, inf);
            }
        }
        else cout<<-1;
    }
}