#include <bits/stdc++.h>
#define int long long
#define iter set <el, comp>::iterator
using namespace std;
const int sz=1e5+10, inf=1e18;
struct el
{
    int l, r, k, b;
};
struct comp
{
    bool operator() (const el &a, const el &b) const
    {
        return a.k>b.k;
    }
};
struct comp2
{
    bool operator() (const el &a, const el &b) const
    {
        return a.r<b.r;
    }
};
set <el, comp> hull[sz];
set <el, comp2> hull2[sz];
int de(int a, int b){return a/b+(a%b>0);}
int intersect(int k, int b, int k2, int b2)
{
    if(k<k2)
    {
        swap(k, k2);
        swap(b, b2);
    }
    if(b<b2) return (b2-b)/(k-k2);
    else return -de(b-b2, k-k2);
}
void ins(int nu, el cu)
{
    cu.l=-inf, cu.r=inf;
    iter it=hull[nu].lower_bound(cu);
    vector <iter> ve;
    for(iter it2=it; it2!=hull[nu].end(); it2++)
    {
        el f=*it2;
        int x;
        if(f.k==cu.k)
        {
            if(f.b<cu.b) x=-inf*2;
            else x=inf*2;
        }
        else x=intersect(cu.k, cu.b, f.k, f.b);
        if(x<f.r)
        {
            if(x>=f.l)
            {
                hull[nu].erase(f);
                hull2[nu].erase(f);
                f.l=x+1;
                hull[nu].insert(f);
                hull2[nu].insert(f);
            }
            cu.r=x;
            break;
        }
        else ve.push_back(it2);
    }
    it=hull[nu].lower_bound(cu);
    while(it!=hull[nu].begin())
    {
        it--;
        el f=*it;
        int x=intersect(cu.k, cu.b, f.k, f.b);
        if(x>=f.l)
        {
            if(x<f.r)
            {
                hull[nu].erase(f);
                hull2[nu].erase(f);
                f.r=x;
                hull[nu].insert(f);
                hull2[nu].insert(f);
            }
            cu.l=x+1;
            break;
        }
        else ve.push_back(it);
    }
    for(int a=0; a<ve.size(); a++)
    {
        hull[nu].erase(ve[a]);
        hull2[nu].erase(*ve[a]);
    }
    if(cu.l<=cu.r)
    {
        hull[nu].insert(cu), hull2[nu].insert(cu);
    }
}
int que(int nu, int x)
{
    el f=*hull2[nu].lower_bound({0, x, 0, 0});
    return f.k*x+f.b;
}
int ara[sz], arb[sz], dp[sz], cnu[sz], cq=0;
vector <int> sv[sz];
void dfs(int v, int pr)
{
    vector <int> sp;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v);
            sp.push_back(cnu[ne]);
            if(hull[sp.back()].size()>hull[sp[0]].size()) swap(sp[0], sp.back());
        }
    }
    if(sp.size()==0)
    {
        dp[v]=0, cnu[v]=cq, cq++;
    }
    else
    {
        cnu[v]=sp[0];
        for(int a=1; a<sp.size(); a++)
        {
            int nu=sp[a];
            for(iter it=hull[nu].begin(); it!=hull[nu].end(); it++) ins(cnu[v], *it);
            hull[nu].clear(), hull2[nu].clear();
        }
        dp[v]=que(cnu[v], ara[v]);
    }
    ins(cnu[v], {0, 0, arb[v], dp[v]});
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++) scanf("%lld", &ara[a]);
    for(int a=0; a<n; a++) scanf("%lld", &arb[a]);
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, -1);
    for(int a=0; a<n; a++) printf("%lld ", dp[a]);
}