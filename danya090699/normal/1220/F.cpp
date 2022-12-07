#include <bits/stdc++.h>
using namespace std;
const int sz=4e5+10, inf=1e9;
int n, ar[sz];
pair <int, int> dot2[sz*4];
void build2(int nu, int l, int r)
{
    if(l==r) dot2[nu]={ar[l], l};
    else
    {
        int mid=(l+r)>>1;
        build2(nu*2, l, mid);
        build2(nu*2+1, mid+1, r);
        dot2[nu]=min(dot2[nu*2], dot2[nu*2+1]);
    }
}
int lg, rg, val;
pair <int, int> que2(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot2[nu];
    else if(l>rg or r<lg) return {inf, -1};
    else
    {
        int mid=(l+r)>>1;
        return min(que2(nu*2, l, mid), que2(nu*2+1, mid+1, r));
    }
}
vector <int> sv[sz];
void rec(int v, int l, int r)
{
    lg=l, rg=r;
    int p=que2(1, 0, n*2-2).second;
    if(v!=-1) sv[v].push_back(p);
    if(p>l) rec(p, l, p-1);
    if(p<r) rec(p, p+1, r);
}

int tin[sz], si[sz], timer=0;
void dfs(int v)
{
    tin[v]=timer++, si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne), si[v]+=si[ne];
    }
}
int dot[sz*4], add[sz*4];
void push(int nu)
{
    add[nu*2]+=add[nu];
    add[nu*2+1]+=add[nu];
    add[nu]=0;
}
void recalc(int nu)
{
    dot[nu]=max(dot[nu*2]+add[nu*2], dot[nu*2+1]+add[nu*2+1]);
}
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) add[nu]+=val;
    else if(!(l>rg or r<lg))
    {
        push(nu);
        int mid=(l+r)>>1;
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
void f(int v, int add)
{
    lg=tin[v], rg=lg+si[v]-1, val=add;
    cha(1, 0, n*2-2);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int p;
    cin>>n;
    int per[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &per[a]);
        if(per[a]==1) p=a;
    }
    for(int a=0; a<n*2-1; a++)
    {
        int i=a-(n-1-p);
        if(i<0) i+=n;
        i%=n;
        ar[a]=per[i];
    }
    build2(1, 0, n*2-2);
    rec(-1, 0, n*2-2);
    dfs(n-1);
    for(int a=0; a<n; a++) f(a, 1);
    int an=inf, d;
    for(int a=0; a<n; a++)
    {
        if(dot[1]+add[1]<an)
        {
            an=dot[1]+add[1];
            d=a-(n-1-p);
            if(d<0) d+=n;
            d%=n;
        }
        f(a, -1);
        if(a+n<2*n-1) f(a+n, 1);
    }
    cout<<an<<" "<<d;
}