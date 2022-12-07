#include <bits/stdc++.h>
#define int long long
using namespace std;
int inf=1e18, n, m, q, s, lg, rg, add, bnu, bva;
struct el
{
    int mi=inf, nu, add=inf;
};
el *dot;
vector <int> *dot2;
vector <int*> *sv, re;
bool *us;
void push(int nu)
{
    dot[nu*2].add=min(dot[nu*2].add, dot[nu].add);
    dot[nu*2+1].add=min(dot[nu*2+1].add, dot[nu].add);
    dot[nu].add=inf;
}
void recalc(int nu)
{
    int lv=min(dot[nu*2].mi, dot[nu*2].add), rv=min(dot[nu*2+1].mi, dot[nu*2+1].add), l, r;
    l=lv, r=rv;
    if(lv==-1) l=inf+1;
    if(rv==-1) r=inf+1;
    if(l<r)
    {
        dot[nu].mi=lv, dot[nu].nu=dot[nu*2].nu;
    }
    else
    {
        dot[nu].mi=rv, dot[nu].nu=dot[nu*2+1].nu;
    }
}
void build(int nu, int l, int r)
{
    if(l==r)
    {
        dot[nu].nu=l;
        if(l==s) dot[nu].add=0;
    }
    else
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) dot[nu].add=min(dot[nu].add, add);
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)/2;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
void cha2(int nu, int l, int r)
{
    if(l>=lg and r<=rg) dot2[nu].push_back(add);
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)/2;
        cha2(nu*2, l, mid);
        cha2(nu*2+1, mid+1, r);
    }
}
void check(int nu, int l, int r)
{
    while(dot2[nu].size()>0)
    {
        int cu=dot2[nu].back();
        if(us[cu]==0)
        {
            lg=re[cu][0], rg=re[cu][0], add=bva+re[cu][1];
            cha(1, 0, n-1);
            us[cu]=1;
        }
        dot2[nu].pop_back();
    }
    if(l!=r)
    {
        int mid=(l+r)/2;
        if(bnu<=mid) check(nu*2, l, mid);
        else check(nu*2+1, mid+1, r);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>q>>s;
    s--;
    dot=new el[n*4], dot2=new vector <int>[n*4], sv=new vector <int*>[n];
    build(1, 0, n-1);
    for(int a=0; a<q; a++)
    {
        int ty, v, l, r, w;
        cin>>ty;
        if(ty==1)
        {
            cin>>v>>l>>w;
            v--, l--;
            sv[v].push_back(new int[3]);
            sv[v].back()[0]=l, sv[v].back()[1]=l, sv[v].back()[2]=w;
        }
        else
        {
            cin>>v>>l>>r>>w;
            v--, l--, r--;
            if(ty==2)
            {
                sv[v].push_back(new int[3]);
                sv[v].back()[0]=l, sv[v].back()[1]=r, sv[v].back()[2]=w;
            }
            else
            {
                re.push_back(new int[2]);
                lg=l, rg=r, add=re.size()-1;
                re.back()[0]=v, re.back()[1]=w;
                cha2(1, 0, n-1);
            }
        }
    }
    m=re.size();
    us=new bool[m];
    for(int a=0; a<m; a++) us[a]=0;
    int di[n];
    for(int a=0; a<n; a++) di[a]=-1;
    for(int a=0; a<n; a++)
    {
        bnu=dot[1].nu, bva=min(dot[1].mi, dot[1].add);
        if(bva==inf) break;
        di[bnu]=bva;
        lg=bnu, rg=bnu, add=-1;
        cha(1, 0, n-1);
        for(int b=0; b<sv[bnu].size(); b++)
        {
            lg=sv[bnu][b][0], rg=sv[bnu][b][1], add=bva+sv[bnu][b][2];
            cha(1, 0, n-1);
        }
        check(1, 0, n-1);
    }
    for(int a=0; a<n; a++) cout<<di[a]<<" ";
}