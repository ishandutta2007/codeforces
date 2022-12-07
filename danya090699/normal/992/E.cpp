#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10;
int dot[sz*4], add[sz*4], d[sz];
int lg, rg, va;
void recalc(int nu)
{
    dot[nu]=max(dot[nu*2]+add[nu*2], dot[nu*2+1]+add[nu*2+1]);
}
void push(int nu)
{
    add[nu*2]+=add[nu];
    add[nu*2+1]+=add[nu];
    add[nu]=0;
}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=d[l];
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) add[nu]+=va;
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
pair<int, int> que(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        if(dot[nu]+add[nu]>=0)
        {
            if(l==r) return make_pair(l, dot[nu]+add[nu]);
            else
            {
                int mid=(l+r)>>1;
                push(nu);
                pair <int, int> re;
                if(dot[nu*2]+add[nu*2]>=0) re=que(nu*2, l, mid);
                else re=que(nu*2+1, mid+1, r);
                recalc(nu);
                return re;
            }
        }
        else return make_pair(-1, -1);
    }
    else if(l>rg or r<lg) return make_pair(-1, -1);
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        pair <int, int> re=que(nu*2, l, mid);
        if(re.first==-1) re=que(nu*2+1, mid+1, r);
        recalc(nu);
        return re;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    int ar[n], su=0;
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a]);
        d[a]=ar[a]-su;
        su+=ar[a];
    }
    build(1, 0, n-1);
    for(int a=0; a<q; a++)
    {
        int p, x;
        scanf("%lld%lld", &p, &x);
        p--;
        lg=p, rg=p, va=x-ar[p], cha(1, 0, n-1);
        if(p+1<n)
        {
            lg=p+1, rg=n-1, va=ar[p]-x, cha(1, 0, n-1);
        }
        ar[p]=x;
        lg=0, rg=n-1;
        int an=-1;
        while(lg<n)
        {
            pair <int, int> re=que(1, 0, n-1);
            if(re.first==-1) break;
            if(re.second==0)
            {
                an=re.first+1;
                break;
            }
            lg=re.first+1;
        }
        printf("%lld\n", an);
    }
}