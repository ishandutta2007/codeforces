//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int n, k, m, q, cnu[21], cq, qq, lg, rg;
vector <int> sv[21];
bool sm[6][sz];
struct el
{
    int q=1, le, si=1;
    int l[5]={0, -1, -1, -1, -1}, r[5]={0, -1, -1, -1, -1};
};
el dot[sz*4], res;
void dfs(int v)
{
    cnu[v]=cq, qq++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(cnu[ne]==-1) dfs(ne);
    }
}
void tr(int nu)
{
    if(cnu[nu]==-1)
    {
        qq=0, dfs(nu), cq++, res.q-=qq-1;
    }
}
el recalc(el ls, el rs)
{
    if(ls.le==-1) return rs;
    else if(rs.le==-1) return ls;
    else
    {
        res.q=ls.q+rs.q, res.le=ls.le, res.si=ls.si+rs.si;
        for(int a=0; a<k; a++)
        {
            int x=ls.le+ls.si-1-a;
            for(int b=k-1-a; b>=0; b--)
            {
                int y=rs.le+b;
                if(sm[y-x][x] and ls.r[a]!=-1 and rs.l[b]!=-1)
                {
                    sv[ls.r[a]].push_back(rs.l[b]+10);
                    sv[rs.l[b]+10].push_back(ls.r[a]);
                }
            }
        }
        for(int a=0; a<=20; a++) cnu[a]=-1;
        cq=0;
        for(int a=0; a<k; a++)
        {
            int nu=ls.l[a];
            if(nu!=-1)
            {
                tr(nu);
                res.l[a]=cnu[nu];
            }
            else
            {
                nu=rs.l[a-ls.si];
                if(nu!=-1)
                {
                    tr(nu+10);
                    res.l[a]=cnu[nu+10];
                }
                else res.l[a]=-1;
            }
        }
        for(int a=0; a<k; a++)
        {
            int nu=rs.r[a];
            if(nu!=-1)
            {
                tr(nu+10);
                res.r[a]=cnu[nu+10];
            }
            else
            {
                nu=ls.r[a-rs.si];
                if(nu!=-1)
                {
                    tr(nu);
                    res.r[a]=cnu[nu];
                }
                else res.r[a]=-1;
            }
        }
        for(int a=0; a<k; a++)
        {
            int nu=ls.r[a];
            if(nu!=-1) tr(nu);
        }
        for(int a=0; a<k; a++)
        {
            int nu=rs.l[a];
            if(nu!=-1) tr(nu+10);
        }
        for(int a=0; a<=20; a++) sv[a].clear();
        return res;
    }
}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu].le=l;
    else
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        dot[nu]=recalc(dot[nu*2], dot[nu*2+1]);
    }
}
el que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu];
    else if(l>rg or r<lg)
    {
        res.le=-1;
        return res;
    }
    else
    {
        int mid=(l+r)/2;
        return recalc(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k>>m;
    for(int a=1; a<=k; a++) for(int b=0; b<n; b++) sm[a][b]=0;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        if(v>u) swap(u, v);
        sm[u-v][v]=1;
    }
    build(1, 0, n-1);
    cin>>q;
    for(int a=0; a<q; a++)
    {
        scanf("%d%d", &lg, &rg);
        lg--, rg--;
        if(lg<n)
        {
            rg=min(rg, n-1);
            cout<<que(1, 0, n-1).q<<"\n";
        }
    }
}