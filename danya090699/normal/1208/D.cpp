#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10;
int dot[sz*4], add[sz*4], pref[sz];
void push(int nu)
{
    add[nu*2]+=add[nu];
    add[nu*2+1]+=add[nu];
    add[nu]=0;
}
void recalc(int nu)
{
    dot[nu]=dot[nu*2]+add[nu*2];
}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=pref[l];
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int lg, rg, va;
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        add[nu]+=va;
    }
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int que(int nu, int l, int r)
{
    if(l==r) return l;
    else
    {
        push(nu);
        int mid=(l+r)>>1, re;
        if(dot[nu*2+1]+add[nu*2+1]<=va) re=que(nu*2+1, mid+1, r);
        else re=que(nu*2, l, mid);
        recalc(nu);
        return re;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], an[n];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    pref[0]=-1;
    for(int a=2; a<=n; a++) pref[a]=pref[a-1]+a-1;
    build(1, 0, n);
    for(int a=n-1; a>=0; a--)
    {
        va=ar[a];
        an[a]=que(1, 0, n);
        lg=an[a]+1, rg=n, va=-an[a];
        //cout<<lg<<" "<<rg<<" "<<va<<"\n";
        if(lg<=rg) cha(1, 0, n);
    }
    for(int a=0; a<n; a++) printf("%lld ", an[a]);
}