#include <bits/stdc++.h>
using namespace std;
const int sz=4e5+10;
struct el
{
    int l=0, r=0, su=0, mi, ma, add=0;
};
el dot[sz*4];

void push(int nu)
{
    dot[nu*2].add+=dot[nu].add;
    dot[nu*2+1].add+=dot[nu].add;
    dot[nu].add=0;
}
void recalc(int nu)
{
    int lmi=dot[nu*2].mi+dot[nu*2].add, rmi=dot[nu*2+1].mi+dot[nu*2+1].add;

    dot[nu].mi=min(lmi, rmi);
    dot[nu].ma=max(dot[nu*2].ma, dot[nu*2+1].ma);

    if(lmi<rmi)
    {
        dot[nu].l=dot[nu*2].l;
        dot[nu].r=max(dot[nu*2].r, dot[nu*2+1].ma);
        dot[nu].su=dot[nu*2].su;
    }
    if(lmi>rmi)
    {
        dot[nu].l=max(dot[nu*2].ma, dot[nu*2+1].l);
        dot[nu].r=dot[nu*2+1].r;
        dot[nu].su=dot[nu*2+1].su;
    }
    if(lmi==rmi)
    {
        dot[nu].l=dot[nu*2].l;
        dot[nu].r=dot[nu*2+1].r;
        dot[nu].su=dot[nu*2].su+max(dot[nu*2].r, dot[nu*2+1].l)+dot[nu*2+1].su;
    }
}
int n, qq, ar[sz], q[sz];
void build(int nu, int l, int r)
{
    if(l==r)
    {
        dot[nu].mi=ar[l], dot[nu].ma=q[l];
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
int p;
void cha2(int nu, int l, int r)
{
    if(l==r) dot[nu].ma=q[l];
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        if(p<=mid) cha2(nu*2, l, mid);
        else cha2(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
set <int> se[sz];
void f(int i, int ty)
{
    if(se[i].size())
    {
        int l=*se[i].begin();
        auto it=se[i].end();
        it--;
        int r=*it;

        lg=l*2+1, rg=r*2+1, va=ty, cha(1, 0, n*2);

        q[l*2+1]=(ty==1) ? se[i].size() : 0, p=l*2+1, cha2(1, 0, n*2);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>qq;
    int ch[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ch[a]);
        se[ch[a]].insert(a);
    }
    for(int a=0; a<sz; a++)
    {
        if(se[a].size())
        {
            int l=*se[a].begin();
            auto it=se[a].end();
            it--;
            int r=*it;
            ar[l*2+1]++, ar[r*2+2]--;
            q[l*2+1]=se[a].size();
        }
    }
    int cu=0;
    for(int a=0; a<=n*2; a++) cu+=ar[a], ar[a]=cu;
    build(1, 0, n*2);
    printf("%d\n", n-dot[1].su);
    for(int a=0; a<qq; a++)
    {
        int i, x;
        scanf("%d%d", &i, &x);
        i--;
        f(ch[i], -1);
        se[ch[i]].erase(i);
        f(ch[i], 1);
        ch[i]=x;
        f(ch[i], -1);
        se[ch[i]].insert(i);
        f(ch[i], 1);
        printf("%d\n", n-dot[1].su);
    }
}