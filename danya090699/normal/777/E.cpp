#include <bits/stdc++.h>
#define int long long
using namespace std;
struct el
{
    int rs, rb, h, nu;
};
int n, *dot, lg, rg, va;
el *ba;
bool comp(el a, el b)
{
    if(a.rb!=b.rb) return (a.rb>b.rb);
    else return (a.rs>b.rs);
}
bool comp2(el a, el b){return (a.rs<b.rs);}
bool comp3(el a, el b){return (a.nu<b.nu);}
void recalc(int nu)
{
    dot[nu]=max(dot[nu*2], dot[nu*2+1]);
}
void cha(int nu, int l, int r)
{
    if(l==r) dot[nu]=va;
    else
    {
        int mid=(l+r)/2;
        if(lg<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
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
        return (max(que(nu*2, l, mid), que(nu*2+1, mid+1, r)));
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    ba=new el[n], dot=new int[n*4];
    for(int a=0; a<n; a++) cin>>ba[a].rs>>ba[a].rb>>ba[a].h;
    sort(ba, ba+n, comp);
    for(int a=0; a<n; a++) ba[a].nu=a;
    sort(ba, ba+n, comp2);
    int ar[n], pos[n], best=0;
    for(int a=0; a<n; a++)
    {
        ar[a]=ba[a].rs, pos[ba[a].nu]=a;
    }
    sort(ba, ba+n, comp3);
    for(int a=0; a<n*4; a++) dot[a]=0;
    for(int a=0; a<n; a++)
    {
        int an=0;
        lg=0;
        rg=lower_bound(ar, ar+n, ba[a].rb)-ar;
        rg--;
        if(rg>=0) an=que(1, 0, n-1);
        an+=ba[a].h;
        lg=pos[a], va=an;
        cha(1, 0, n-1);
        best=max(best, an);
    }
    cout<<best;
}