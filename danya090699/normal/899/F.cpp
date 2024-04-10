#include <bits/stdc++.h>
#define iter set <int>::iterator
using namespace std;
const int sz=2e5+10, sz2=256;
int n, m;
int dot[sz*4], lg;
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=1;
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        dot[nu]=dot[nu*2]+dot[nu*2+1];
    }
}
void cha(int nu, int l, int r)
{
    if(l==r) dot[nu]=0;
    else
    {
        int mid=(l+r)>>1;
        if(lg<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        dot[nu]=dot[nu*2]+dot[nu*2+1];
    }
}
int que(int nu, int l, int r, int q)
{
    if(l==r)
    {
        if(q) return l+1;
        else return l;
    }
    else
    {
        int mid=(l+r)>>1;
        if(dot[nu*2]>q) return que(nu*2, l, mid, q);
        else return que(nu*2+1, mid+1, r, q-dot[nu*2]);
    }
}
set <int> se[sz2];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    char an[n];
    for(int a=0; a<n; a++)
    {
        char sy;
        cin>>sy;
        se[sy].insert(a);
        an[a]=0;
    }
    build(1, 0, n-1);
    for(int a=0; a<m; a++)
    {
        int l, r;
        char sy;
        scanf("%d%d", &l, &r);
        cin>>sy;
        l--;
        l=que(1, 0, n-1, l), r=que(1, 0, n-1, r);
        iter le=se[sy].lower_bound(l), ri=se[sy].lower_bound(r);
        for(iter it=le; it!=ri; it++)
        {
            lg=*it, cha(1, 0, n-1);
        }
        se[sy].erase(le, ri);
    }
    for(int a=0; a<sz2; a++)
    {
        for(iter it=se[a].begin(); it!=se[a].end(); it++) an[*it]=a;
    }
    for(int a=0; a<n; a++) if(an[a]!=0) cout<<an[a];
}