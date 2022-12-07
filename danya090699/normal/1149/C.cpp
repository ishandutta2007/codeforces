#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, inf=1e8;
struct el
{
    int l, c, lc, cr, lcr, add=0;
};
el dot[sz*4];
int ar[sz];
void push(int nu)
{
    dot[nu*2].add+=dot[nu].add;
    dot[nu*2+1].add+=dot[nu].add;
    dot[nu].add=0;
}
el gva(el &rt)
{
    el re=rt;
    re.l+=rt.add;
    re.c-=2*rt.add;
    re.lc-=rt.add;
    re.cr-=rt.add;
    return re;
}
void recalc(int nu)
{
    el &v=dot[nu], lt=gva(dot[nu*2]), rt=gva(dot[nu*2+1]);

    v.l=max(lt.l, rt.l);

    v.c=max(lt.c, rt.c);

    v.lc=max(lt.lc, rt.lc);
    v.lc=max(v.lc, lt.l+rt.c);

    v.cr=max(lt.cr, rt.cr);
    v.cr=max(v.cr, lt.c+rt.l);

    v.lcr=max(lt.lcr, rt.lcr);
    v.lcr=max(v.lcr, lt.l+rt.cr);
    v.lcr=max(v.lcr, lt.lc+rt.l);
}
void build(int nu, int l, int r)
{
    if(l==r)
    {
        dot[nu].l=ar[l];
        dot[nu].c=-ar[l]*2;
        dot[nu].lc=-ar[l];
        dot[nu].cr=-ar[l];
        dot[nu].lcr=0;
    }
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
    if(l>=lg and r<=rg) dot[nu].add+=va;
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    char s[n*2];
    scanf("%s", s);
    for(int a=1; a<2*n-1; a++)
    {
        ar[a]=ar[a-1];
        if(s[a-1]=='(') ar[a]++;
        else ar[a]--;
    }
    build(1, 0, 2*n-2);
    printf("%d\n", dot[1].lcr);
    for(int a=0; a<q; a++)
    {
        scanf("%d%d", &lg, &rg);
        lg--, rg--;
        if(lg>rg) swap(lg, rg);
        swap(s[lg], s[rg]);
        if(s[lg]=='(' and s[rg]==')')
        {
            lg++, va=2, cha(1, 0, 2*n-2);
        }
        if(s[lg]==')' and s[rg]=='(')
        {
            lg++, va=-2, cha(1, 0, 2*n-2);
        }
        printf("%d\n", dot[1].lcr);
    }
}