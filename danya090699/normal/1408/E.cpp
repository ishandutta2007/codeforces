#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int pr[sz], si[sz];
int get_pr(int v)
{
    if(pr[v]!=v) pr[v]=get_pr(pr[v]);
    return pr[v];
}
void mer(int u, int v)
{
    if(si[u]<si[v]) swap(u, v);
    pr[v]=u;
    si[u]+=si[v];
}
struct el
{
    int u, v, w;
};
bool comp(el a, el b){return a.w>b.w;}
main()
{
    //freopen("input.txt", "r", stdin);
    int m, n;
    cin>>m>>n;
    int wm[m], wn[n];
    for(int a=0; a<m; a++) scanf("%d", &wm[a]);
    for(int a=0; a<n; a++) scanf("%d", &wn[a]);
    vector <el> re;
    long long an=0;
    for(int a=0; a<m; a++)
    {
        int q;
        scanf("%d", &q);
        for(int b=0; b<q; b++)
        {
            int v;
            scanf("%d", &v);
            v--;
            re.push_back({v, a+n, wm[a]+wn[v]});
            an+=wm[a]+wn[v];
        }
    }
    for(int a=0; a<n+m; a++) pr[a]=a, si[a]=1;
    sort(re.begin(), re.end(), comp);
    for(int a=0; a<re.size(); a++)
    {
        int u=get_pr(re[a].u), v=get_pr(re[a].v), w=re[a].w;
        if(u!=v) mer(u, v), an-=w;
    }
    cout<<an;
}