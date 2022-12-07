#include <bits/stdc++.h>
using namespace std;
const int sz=4e5+10, inf=1e9;
int dot[sz*4], add[sz*4], n, k, m;
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
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=n-l+1;
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
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu]+add[nu];
    else if(l>rg or r<lg) return inf;
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        int re=min(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
        recalc(nu);
        return re;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k>>m;
    build(1, 0, n*2);
    set <pair <int, int> > us;
    multiset <int, greater <int> > mx;
    for(int a=0; a<m; a++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int h=y+abs(x-k);
        if(us.find({x, y})==us.end())
        {
            us.insert({x, y}), mx.insert(h), va=-1;
        }
        else
        {
            us.erase({x, y}), mx.erase(mx.find(h)), va=1;
        }
        lg=0, rg=h, cha(1, 0, n*2);

        if(mx.size())
        {
            lg=0, rg=*mx.begin();
            int an=max(0, -que(1, 0, n*2));
            printf("%d\n", an);
        }
        else printf("0\n");
    }
}