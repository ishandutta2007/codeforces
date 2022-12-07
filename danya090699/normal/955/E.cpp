#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, inf=1e9;
int ar[sz], dot[2][sz*4], add[2][sz*4], lg, rg, va;
void recalc(int i, int nu)
{
    dot[i][nu]=min(dot[i][nu*2]+add[i][nu*2], dot[i][nu*2+1]+add[i][nu*2+1]);
}
void push(int i, int nu)
{
    add[i][nu*2]+=add[i][nu];
    add[i][nu*2+1]+=add[i][nu];
    add[i][nu]=0;
}
void build(int nu, int l, int r)
{
    if(l==r)
    {

        dot[0][nu]=ar[l]-1;
        dot[1][nu]=ar[l]+l;
    }
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(0, nu), recalc(1, nu);
    }
}
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        add[0][nu]+=va, add[1][nu]+=va;
    }
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(0, nu), push(1, nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(0, nu), recalc(1, nu);
    }
}
int que(int nu, int l, int r)
{
    if(l==r) return l;
    else
    {
        int mid=(l+r)>>1;
        push(0, nu);
        int re;
        if(dot[0][nu*2]+add[0][nu*2]<0) re=que(nu*2, l, mid);
        else re=que(nu*2+1, mid+1, r);
        recalc(0, nu);
        return re;
    }
}
int que2(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[1][nu]+add[1][nu];
    else if(l>rg or r<lg) return inf;
    else
    {
        int mid=(l+r)>>1;
        push(1, nu);
        int re=min(que2(nu*2, l, mid), que2(nu*2+1, mid+1, r));
        recalc(1, nu);
        return re;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=inf;
    cin>>n;
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    build(1, 0, n-1);
    for(int a=0; a<n; a++)
    {
        if(dot[0][1]+add[0][1]<0)
        {

            int p=que(1, 0, n-1);
            lg=0, rg=p-1;
            int t=que2(1, 0, n-1);
            lg=p, rg=n-1;
            t=max(t, que2(1, 0, n-1));
            an=min(an, t);
        }
        if(a!=n-1)
        {
            lg=0, rg=a, va=1;
            cha(1, 0, n-1);
            lg=a+1, rg=n-1, va=-1;
            cha(1, 0, n-1);
        }
    }
    if(an==inf) cout<<-1;
    else cout<<an;
}