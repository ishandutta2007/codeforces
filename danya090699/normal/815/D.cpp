#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, xm, ym, zm, lg, rg, add, ans=0;
struct el
{
    int x, y, z;
};
struct el2
{
    int su=0, mi=0, add=-1;
};
el *ar;
el2 *dot;
bool comp(el a, el b){return a.x<b.x;}
void push(int nu)
{
    if(dot[nu].add!=-1)
    {
        dot[nu*2].add=dot[nu].add;
        dot[nu*2+1].add=dot[nu].add;
        dot[nu].add=-1;
    }
}
void recalc(int nu, int ls, int rs)
{
    dot[nu].su=max(dot[nu*2].su, dot[nu*2].add*ls)+max(dot[nu*2+1].su, dot[nu*2+1].add*rs);
    dot[nu].mi=max(dot[nu*2+1].mi, dot[nu*2+1].add);
}
void ins(int nu, int l, int r)
{
    if(l>=lg and r<=rg) dot[nu].add=add;
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)/2;
        push(nu);
        ins(nu*2, l, mid);
        ins(nu*2+1, mid+1, r);
        recalc(nu, mid-l+1, r-mid);
    }
}
int que(int nu, int l, int r)
{
    if(l==r) return l;
    else
    {
        push(nu);
        int mid=(l+r)/2, cmi=max(dot[nu*2].mi, dot[nu*2].add), an;
        if(cmi>=add) an=que(nu*2+1, mid+1, r);
        else an=que(nu*2, l, mid);
        recalc(nu, mid-l+1, r-mid);
        return an;
    }
}
int que2(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return max(dot[nu].su, dot[nu].add*(r-l+1));
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)/2;
        push(nu);
        int an=que2(nu*2, l, mid)+que2(nu*2+1, mid+1, r);
        recalc(nu, mid-l+1, r-mid);
        return an;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>xm>>ym>>zm;
    ar=new el[n];
    for(int a=0; a<n; a++)
    {
        scanf("%lld%lld%lld", &ar[a].x, &ar[a].y, &ar[a].z);
        ar[a].x--, ar[a].y--, ar[a].z--;
    }
    sort(ar, ar+n, comp);
    int sufy[xm+1], sufz[xm+1], yk=n-1;
    sufy[xm]=-1, sufz[xm]=-1;
    for(int a=xm-1; a>=0; a--)
    {
        sufy[a]=sufy[a+1], sufz[a]=sufz[a+1];
        while(yk>=0)
        {
            if(ar[yk].x>=a)
            {
                sufy[a]=max(sufy[a], ar[yk].y);
                sufz[a]=max(sufz[a], ar[yk].z);
                yk--;
            }
            else break;
        }
    }
    yk=0;
    dot=new el2[ym*4];
    for(int a=0; a<xm; a++)
    {
        while(yk<n)
        {
            if(ar[yk].x<a)
            {
                rg=ar[yk].y, add=ar[yk].z+1;
                if(max(dot[1].mi, dot[1].add)<add) lg=que(1, 0, ym-1);
                else lg=ym;
                if(lg<=rg) ins(1, 0, ym-1);
                yk++;
            }
            else break;
        }
        lg=sufy[a]+1, add=sufz[a]+1;
        if(max(dot[1].mi, dot[1].add)<add) rg=que(1, 0, ym-1);
        else rg=ym;
        rg--;
        rg=max(rg, lg-1);
        if(lg<=rg)
        {
            ans+=zm*(rg-lg+1)-que2(1, 0, ym-1);
        }
        ans+=(zm-add)*(ym-1-rg);
    }
    cout<<ans;
}