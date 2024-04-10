#include <bits/stdc++.h>
#define int long long
using namespace std;
int q, n, *ar, inf=1e9, lg, rg, add;
struct el
{
    int add=-1, m0, m1=inf;
};
el *dot;
void recalc(int nu)
{
    int m01=dot[nu*2].m0, m11=dot[nu*2].m1, m02=dot[nu*2+1].m0, m12=dot[nu*2+1].m1;
    int add1=dot[nu*2].add, add2=dot[nu*2+1].add;
    if(add1==0)
    {
        m01=min(m01, m11), m11=inf;
    }
    if(add1==1)
    {
        m11=min(m01, m11), m01=inf;
    }
    if(add1==2) swap(m01, m11);
    if(add2==0)
    {
        m02=min(m02, m12), m12=inf;
    }
    if(add2==1)
    {
        m12=min(m02, m12), m02=inf;
    }
    if(add2==2) swap(m02, m12);
    dot[nu].m0=min(m01, m02), dot[nu].m1=min(m11, m12);
}
void push(int nu)
{
    int add0=dot[nu].add, add1=dot[nu*2].add, add2=dot[nu*2+1].add;
    if(add0==0 or add0==1)
    {
        dot[nu*2].add=add0, dot[nu*2+1].add=add0;
    }
    if(add0==2)
    {
        if(add1==0 or add1==1) dot[nu*2].add^=1;
        if(add1==2) dot[nu*2].add=-1;
        if(add1==-1) dot[nu*2].add=2;
        if(add2==0 or add2==1) dot[nu*2+1].add^=1;
        if(add2==2) dot[nu*2+1].add=-1;
        if(add2==-1) dot[nu*2+1].add=2;
    }
    dot[nu].add=-1;
}
void build(int nu, int l, int r)
{
    if(l==r) dot[nu].m0=l;
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
    if(l>=lg and r<=rg)
    {
        if(add==0 or add==1) dot[nu].add=add;
        else
        {
            if(dot[nu].add==0 or dot[nu].add==1) dot[nu].add^=1;
            else if(dot[nu].add==2) dot[nu].add=-1;
            else dot[nu].add=2;
        }
    }
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)/2;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>q;
    int so[q][3];
    set <int> se;
    se.insert(1);
    for(int a=0; a<q; a++)
    {
        cin>>so[a][0]>>so[a][1]>>so[a][2];
        se.insert(so[a][1]);
        se.insert(so[a][2]+1);
    }
    n=se.size();
    ar=new int[n];
    int yk=0;
    for(set <int>::iterator it=se.begin(); it!=se.end(); it++)
    {
        ar[yk]=*it, yk++;
    }
    dot=new el[n*4];
    build(1, 0, n-1);
    for(int a=0; a<q; a++)
    {
        int ty=so[a][0], l=so[a][1], r=so[a][2];
        lg=lower_bound(ar, ar+n, l)-ar;
        rg=upper_bound(ar, ar+n, r)-ar-1;
        if(ty==1) add=1;
        if(ty==2) add=0;
        if(ty==3) add=2;
        cha(1, 0, n-1);
        cout<<ar[dot[1].m0]<<"\n";
    }
}