#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10, inf=2e9;
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
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], w[n];
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a]);
        ar[a]--;
    }
    for(int a=0; a<n; a++) scanf("%lld", &w[ar[a]]);
    for(int a=0; a<n; a++)
    {
        lg=a+1, rg=n, va=w[a];
        cha(1, 0, n);
    }
    int an=inf;
    for(int a=0; a+1<n; a++)
    {
        lg=ar[a]+1, rg=n, va=-w[ar[a]];
        cha(1, 0, n);
        lg=0, rg=ar[a], va=w[ar[a]];
        cha(1, 0, n);
        an=min(an, dot[1]+add[1]);
    }
    cout<<an;
}