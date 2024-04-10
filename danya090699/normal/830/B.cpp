//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define iter set <int>::iterator
using namespace std;
const int sz=1e5+10;
int dot[sz*4], ar[sz], lg, rg;
set <int> se[sz];
void recalc(int nu){dot[nu]=dot[nu*2]+dot[nu*2+1];}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=1;
    else
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
void del(int nu, int l, int r)
{
    if(l==r) dot[nu]=0;
    else
    {
        int mid=(l+r)/2;
        if(rg<=mid) del(nu*2, l, mid);
        else del(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)/2;
        return que(nu*2, l, mid)+que(nu*2+1, mid+1, r);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, po=0;
    cin>>n;
    build(1, 0, n-1);
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        se[ar[a]].insert(a);
    }
    sort(ar, ar+n);
    long long an=0;
    for(int a=0; a<n; a++)
    {
        int x=ar[a];
        iter it=se[x].lower_bound(po);
        if(it==se[x].end())
        {
            lg=po, rg=n-1;
            an+=que(1, 0, n-1);
            po=0;
        }
        it=se[x].lower_bound(po);
        lg=po, rg=*it;
        se[x].erase(it);
        an+=que(1, 0, n-1);
        del(1, 0, n-1);
        po=rg;

    }
    cout<<an;
}