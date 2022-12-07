#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
struct el
{
    bool add=0, l, r;
    int pref[2], suf[2], ma[2], len;
};
el dot[sz*4];
void push(int nu)
{
    dot[nu*2].add^=dot[nu].add;
    dot[nu*2+1].add^=dot[nu].add;
    dot[nu].add=0;
}
void recalc(el &re, el &l, el &r)
{
    re.len=l.len+r.len;
    re.l=l.l^l.add;
    re.r=r.r^r.add;
    for(int i=0; i<2; i++)
    {
        re.ma[i]=max(l.ma[i^l.add], r.ma[i^r.add]);
        re.pref[i]=l.pref[i^l.add];
        re.suf[i]=r.suf[i^r.add];
        if(l.r^l.add==r.l^r.add || l.r^l.add==i)
        {
            re.ma[i]=max(re.ma[i], l.suf[i^l.add]+r.pref[i^r.add]);

            if(l.pref[i^l.add]==l.len) re.pref[i]=l.len+r.pref[i^r.add];

            if(r.suf[i^r.add]==r.len) re.suf[i]=r.len+l.suf[i^l.add];
        }
    }
}
char s[sz];
void build(int nu, int l, int r)
{
    if(l==r)
    {
        dot[nu].l=(s[l]=='<'), dot[nu].r=(s[l]=='<');
        dot[nu].len=1;
        for(int i=0; i<2; i++)
        {
            dot[nu].pref[i]=1;
            dot[nu].suf[i]=1;
            dot[nu].ma[i]=1;
        }
    }
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(dot[nu], dot[nu*2], dot[nu*2+1]);
        //cout<<l<<" "<<r<<" "<<dot[nu].len<<"\n";
    }
}
int lg, rg;
el que(int nu, int l, int r)
{
    //cout<<l<<" "<<r<<"\n";
    if(l>=lg and r<=rg)
    {
        dot[nu].add^=1;
        return dot[nu];
    }
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        el re;
        if(rg<=mid) re=que(nu*2, l, mid);
        else if(lg>mid) re=que(nu*2+1, mid+1, r);
        else
        {
            el ll=que(nu*2, l, mid), rr=que(nu*2+1, mid+1, r);
            recalc(re, ll, rr);
        }
        recalc(dot[nu], dot[nu*2], dot[nu*2+1]);
        return re;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    scanf("%s", s);
    build(1, 0, n-1);
    for(int a=0; a<q; a++)
    {
        scanf("%d%d", &lg, &rg);
        lg--, rg--;
        el re=que(1, 0, n-1);
        printf("%d\n", re.ma[re.add]);
    }
}