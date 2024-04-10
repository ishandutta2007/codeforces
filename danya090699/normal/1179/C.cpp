#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
int suf[sz], dot[sz*4], add[sz*4];
void push(int nu)
{
    add[nu*2]+=add[nu];
    add[nu*2+1]+=add[nu];
    add[nu]=0;
}
void recalc(int nu)
{
    dot[nu]=min(dot[nu*2]+add[nu*2], dot[nu*2+1]+add[nu*2+1]);
}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=suf[l];
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int rg, va;
void cha(int nu, int l, int r)
{
    if(l==r)
    {
        if(l==rg) add[nu]+=va;
    }
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        if(rg<mid) cha(nu*2, l, mid);
        else add[nu*2]+=va, cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int que(int nu, int l, int r)
{
    if(l==r) return l;
    else
    {
        int mid=(l+r)>>1, re;
        push(nu);
        if(dot[nu*2+1]+add[nu*2+1]<0) re=que(nu*2+1, mid+1, r);
        else re=que(nu*2, l, mid);
        recalc(nu);
        return re;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n], ar2[m];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        suf[ar[a]]--;
    }
    for(int a=0; a<m; a++)
    {
        scanf("%d", &ar2[a]);
        suf[ar2[a]]++;
    }
    for(int a=sz-2; a>=0; a--) suf[a]+=suf[a+1];
    build(1, 0, sz-1);
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int ty, i, x;
        scanf("%d%d%d", &ty, &i, &x);
        i--;
        if(ty==1)
        {
            va=1, rg=ar[i], cha(1, 0, sz-1);
            ar[i]=x;
            va=-1, rg=ar[i], cha(1, 0, sz-1);
        }
        else
        {
            va=-1, rg=ar2[i], cha(1, 0, sz-1);
            ar2[i]=x;
            va=1, rg=ar2[i], cha(1, 0, sz-1);
        }
        if(dot[1]+add[1]>=0) printf("-1\n");
        else printf("%d\n", que(1, 0, sz-1));
    }
}