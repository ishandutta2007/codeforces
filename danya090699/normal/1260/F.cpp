#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, mod=1e9+7;
int SUM(int a, int b)
{
    return (a+b<mod) ? a+b : a+b-mod;
}
int DIF(int a, int b)
{
    return (a-b>=0) ? a-b : a-b+mod;
}
int MUL(int a, int b)
{
    return (1ll*a*b)%mod;
}
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=MUL(re, x);
        y>>=1;
        x=MUL(x, x);
    }
    return re;
}
int dot[sz*4], add[sz*4];
int getv(int nu, int l, int r)
{
    return SUM(dot[nu], MUL(add[nu], r-l+1));
}
void push(int nu)
{
    add[nu*2]=SUM(add[nu*2], add[nu]);
    add[nu*2+1]=SUM(add[nu*2+1], add[nu]);
    add[nu]=0;
}
void recalc(int nu, int l, int r)
{
    int mid=(l+r)>>1;
    dot[nu]=SUM(getv(nu*2, l, mid), getv(nu*2+1, mid+1, r));
}
int lg, rg, va;
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) add[nu]=SUM(add[nu], va);
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu, l, r);
    }
}
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return getv(nu, l, r);
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        int re=que(nu*2, l, mid);
        re=SUM(re, que(nu*2+1, mid+1, r));
        recalc(nu, l, r);
        return re;
    }
}
int n, pr[sz], h[sz], si[sz], hld[sz], tin[sz], timer=0;
vector <int> sv[sz];
vector <pair <int, int> > sp[sz];
void dfs(int v)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            pr[ne]=v, h[ne]=h[v]+1, dfs(ne), si[v]+=si[ne];
            if(si[ne]>si[sv[v][0]]) swap(sv[v][0], sv[v][a]);
        }
        else
        {
            sv[v].erase(sv[v].begin()+a), a--;
        }
    }
}
void dfs2(int v)
{
    tin[v]=timer++;
    if(sv[v].size())
    {
        hld[sv[v][0]]=hld[v], dfs2(sv[v][0]);
        for(int a=1; a<sv[v].size(); a++)
        {
            hld[sv[v][a]]=sv[v][a], dfs2(sv[v][a]);
        }
    }
}

int mul=0, sum=0, prob[sz];

int go(int v, int add, int x)
{
    int re=0;
    while(1)
    {
        lg=tin[hld[v]], rg=tin[v], va=x;

        if(add) cha(1, 0, n-1);
        else re=SUM(re, que(1, 0, n-1));

        v=hld[v];
        if(v==0) break;
        v=pr[v];
    }
    return re;
}
void ins(int v, int ty)
{
    int va=prob[v]*ty;
    if(va<0) va+=mod;

    sum=SUM(sum, va);
    mul=SUM(mul, MUL(va, h[v]));

    go(v, 1, va);
}
int cou(int v)
{
    int re=SUM(mul, MUL(sum, h[v]));

    re=SUM(re, MUL(go(v, 0, 0), mod-2));

    return MUL(re, prob[v]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int cu=0, an=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        r++;
        sp[l].push_back({a, 1});
        sp[r].push_back({a, -1});
        prob[a]=po(r-l, mod-2);
    }
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    h[0]=1, dfs(0), dfs2(0);
    for(int a=0; a<sz; a++)
    {
        for(int b=0; b<sp[a].size(); b++)
        {
            int v=sp[a][b].first, ty=sp[a][b].second;
            if(ty==1)
            {
                cu=SUM(cu, cou(v));
                ins(v, 1);
            }
            else
            {
                ins(v, -1);
                cu=DIF(cu, cou(v));
            }
        }
        an=SUM(an, cu);
    }
    for(int a=0; a<n; a++) an=MUL(an, po(prob[a], mod-2));

    cout<<an;
}