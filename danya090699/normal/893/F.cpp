#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, inf=2e9;
int tin[sz], si[sz], h[sz], ar[sz], va[sz], lg, rg, cuh, timer=0;
vector <int> sv[sz], pref[sz*4], mi[sz*4];
void dfs(int v, int pr, int he)
{
    tin[v]=timer, timer++, ar[tin[v]]=v, h[v]=he, si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v, he+1), si[v]+=si[ne];
        }
    }
}
bool comp(int a, int b){return h[a]<h[b];}
void build(int nu, int l, int r)
{
    if(l==r) pref[nu].push_back(ar[l]);
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        pref[nu].resize(r-l+1);
        merge(pref[nu*2].begin(), pref[nu*2].end(), pref[nu*2+1].begin(), pref[nu*2+1].end(), pref[nu].begin(), comp);
    }
    mi[nu].resize(r-l+1);
    mi[nu][0]=va[pref[nu][0]];
    for(int a=1; a<mi[nu].size(); a++) mi[nu][a]=min(mi[nu][a-1], va[pref[nu][a]]);
}
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        int ll=-1, rr=pref[nu].size();
        while(rr-ll>1)
        {
            int mid=(ll+rr)>>1;
            if(h[pref[nu][mid]]<=cuh) ll=mid;
            else rr=mid;
        }
        if(ll==-1) return inf;
        else return mi[nu][ll];
    }
    else if(l>rg or r<lg) return inf;
    else
    {
        int mid=(l+r)>>1;
        return min(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, r, m, last=0;
    cin>>n>>r;
    r--;
    for(int a=0; a<n; a++) scanf("%d", &va[a]);
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v), sv[v].push_back(u);
    }
    dfs(r, -1, 0);
    build(1, 0, n-1);
    cin>>m;
    for(int a=0; a<m; a++)
    {
        int p, q;
        scanf("%d%d", &p, &q);
        int v=(last+p)%n, k=(last+q)%n;
        lg=tin[v], rg=tin[v]+si[v]-1, cuh=h[v]+k;
        last=que(1, 0, n-1);
        printf("%d\n", last);
    }
}