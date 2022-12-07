#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
int pr[sz], q[sz], va[sz];
vector <int> sv[sz];
int get_pr(int v)
{
    if(pr[v]!=v) pr[v]=get_pr(pr[v]);
    return pr[v];
}
void merge(int u, int v)
{
    u=get_pr(u), v=get_pr(v);
    if(q[v]>q[u]) swap(u, v);
    q[u]+=q[v];
    pr[v]=u;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    pair <int, int> sp[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &va[a]);
        sp[a]=make_pair(va[a], a);
    }
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    long long an=0;
    sort(sp, sp+n);
    for(int a=0; a<n; a++)
    {
        pr[a]=a, q[a]=1;
    }
    for(int a=0; a<n; a++)
    {
        int v=sp[a].second, su=1;
        an+=va[v];
        for(int b=0; b<sv[v].size(); b++)
        {
            int u=sv[v][b];
            if(sp[a]>make_pair(va[u], u))
            {
                u=get_pr(u);
                an+=1ll*va[v]*q[u]*su;
                su+=q[u];
                merge(v, u);
            }
        }
    }
    for(int a=0; a<n; a++)
    {
        pr[a]=a, q[a]=1;
    }
    for(int a=n-1; a>=0; a--)
    {
        int v=sp[a].second, su=1;
        an-=va[v];
        for(int b=0; b<sv[v].size(); b++)
        {
            int u=sv[v][b];
            if(sp[a]<make_pair(va[u], u))
            {
                u=get_pr(u);
                an-=1ll*va[v]*q[u]*su;
                su+=q[u];
                merge(v, u);
            }
        }
    }
    cout<<an;
}