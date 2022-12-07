#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
struct el
{
    int l, r, ok;
};
el dot[sz*4];
set <int> L[sz];
set <int, greater <int> > R[sz];

void recalc(int nu)
{
    dot[nu].l=min(dot[nu*2].l, dot[nu*2+1].l);
    dot[nu].r=max(dot[nu*2].r, dot[nu*2+1].r);
    dot[nu].ok=dot[nu*2].ok&dot[nu*2+1].ok;
    if(dot[nu*2+1].r>=dot[nu*2].l) dot[nu].ok=0;
}
void build(int nu, int l, int r)
{
    if(l==r)
    {
        dot[nu].l=*L[l].begin();
        dot[nu].r=*R[l].begin();
        dot[nu].ok=dot[nu].l>dot[nu].r;
    }
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int p;
void cha(int nu, int l, int r)
{
    if(l==r)
    {
        dot[nu].l=*L[l].begin();
        dot[nu].r=*R[l].begin();
        dot[nu].ok=dot[nu].l>dot[nu].r;
    }
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q;
    cin>>n>>m>>q;
    for(int a=0; a<n; a++)
    {
        L[a].insert(m), R[a].insert(-1);
    }
    build(1, 0, n-1);
    for(int a=0; a<q; a++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        if(x&1)
        {
            x>>=1, y>>=1;
            if(R[x].find(y)!=R[x].end()) R[x].erase(y);
            else R[x].insert(y);
        }
        else
        {
            x>>=1, y>>=1;
            if(L[x].find(y)!=L[x].end()) L[x].erase(y);
            else L[x].insert(y);
        }
        p=x, cha(1, 0, n-1);
        printf(dot[1].ok ? "YES\n" : "NO\n");
    }
}