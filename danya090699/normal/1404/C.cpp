#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10, inf=1e9;
int dot[sz*4], add[sz*4];
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
int que(int nu, int l, int r)
{
    if(l==r) return l;
    else
    {
        int mid=(l+r)>>1, re;
        push(nu);
        if(dot[nu*2]+add[nu*2]<=0) re=que(nu*2, l, mid);
        else re=que(nu*2+1, mid+1, r);
        recalc(nu);
        return re;
    }
}
int lg, rg, va;
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

int x[sz];
vector <int> sp[sz*4];
void build(int nu, int l, int r)
{
    if(l==r)
    {
        sp[nu].resize(1, x[l]);
    }
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);

        sp[nu].resize(r-l+1);
        merge(sp[nu*2].begin(), sp[nu*2].end(), sp[nu*2+1].begin(), sp[nu*2+1].end(), sp[nu].begin());
    }
}

int que2(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        return sp[nu].end()-lower_bound(sp[nu].begin(), sp[nu].end(), lg);
    }
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        return que2(nu*2, l, mid)+que2(nu*2+1, mid+1, r);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]), x[a]=-1;
    for(int a=0; a<n*4; a++) dot[a]=inf;
    for(int a=n-1; a>=0; a--)
    {
        ar[a]--;
        if(ar[a]<=a)
        {
            //cout<<a-ar[a]<<" ";
            lg=a, rg=a, va=a-ar[a]-inf, cha(1, 0, n-1);
        }
        while(dot[1]+add[1]<=0)
        {
            //cout<<"!";
            int p=que(1, 0, n-1);
            x[p]=a;
            lg=p, rg=p, va=inf, cha(1, 0, n-1);

            if(p+1<n) lg=p+1, rg=n-1, va=-1, cha(1, 0, n-1);
        }
    }
    build(1, 0, n-1);

    //for(int a=0; a<n; a++) cout<<x[a]<<" ";

    for(int a=0; a<q; a++)
    {
        int X, Y;
        scanf("%d%d", &X, &Y);
        lg=X, rg=n-1-Y;
        printf("%d\n", que2(1, 0, n-1));
    }
}