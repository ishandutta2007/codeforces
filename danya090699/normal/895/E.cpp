#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int ar[sz], lg, rg;
double dot[sz*4], add[sz*4], add2[sz*4], v1, v2;
void push(int nu)
{
    add[nu*2]*=add[nu], add2[nu*2]*=add[nu], add[nu*2+1]*=add[nu], add2[nu*2+1]*=add[nu], add[nu]=1;
    add2[nu*2]+=add2[nu], add2[nu*2+1]+=add2[nu], add2[nu]=0;
}
void recalc(int nu, int l, int r)
{
    int mid=(l+r)>>1;
    dot[nu]=dot[nu*2]*add[nu*2]+(mid-l+1)*add2[nu*2];
    dot[nu]+=dot[nu*2+1]*add[nu*2+1]+(r-mid)*add2[nu*2+1];
}
void build(int nu, int l, int r)
{
    add[nu]=1, add2[nu]=0;
    if(l==r) dot[nu]=ar[l];
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu, l, r);
    }
}
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        add[nu]*=v1, add2[nu]*=v1, add2[nu]+=v2;
    }
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu, l, r);
    }
}
double que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu]*add[nu]+add2[nu]*(r-l+1);
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        double an=que(nu*2, l, mid)+que(nu*2+1, mid+1, r);
        recalc(nu, l, r);
        return an;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    build(1, 0, n-1);
    for(int a=0; a<q; a++)
    {
        int ty, l1, r1, l2, r2;
        scanf("%d%d%d", &ty, &l1, &r1);
        l1--, r1--;
        if(ty==1)
        {
            lg=l1, rg=r1;
            double su1=que(1, 0, n-1);
            scanf("%d%d", &l2, &r2);
            l2--, r2--, lg=l2, rg=r2;
            double su2=que(1, 0, n-1);
            int q1=r1-l1+1, q2=r2-l2+1;
            v1=1.0*(q1-1)/q1, v2=(su2/q2)/q1;
            lg=l1, rg=r1;
            cha(1, 0, n-1);
            v1=1.0*(q2-1)/q2, v2=(su1/q1)/q2;
            lg=l2, rg=r2;
            cha(1, 0, n-1);
        }
        else
        {
            lg=l1, rg=r1;
            cout<<fixed<<setprecision(7)<<que(1, 0, n-1)<<"\n";
        }
    }
}