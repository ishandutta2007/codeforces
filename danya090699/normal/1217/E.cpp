#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, inf=2e9;
pair <int, int> dot[9][sz*4];
int ar[9][sz];
void recalc(pair <int, int> l, pair <int, int> r, pair <int, int> &su)
{
    int ar[4]={l.first, l.second, r.first, r.second};
    sort(ar, ar+4);
    su={ar[0], ar[1]};
}
void build(int i, int nu, int l, int r)
{
    if(l==r) dot[i][nu]={ar[i][l], inf};
    else
    {
        int mid=(l+r)>>1;
        build(i, nu*2, l, mid);
        build(i, nu*2+1, mid+1, r);
        recalc(dot[i][nu*2], dot[i][nu*2+1], dot[i][nu]);
    }
}
int p;
void cha(int i, int nu, int l, int r)
{
    if(l==r) dot[i][nu]={ar[i][l], inf};
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid) cha(i, nu*2, l, mid);
        else cha(i, nu*2+1, mid+1, r);
        recalc(dot[i][nu*2], dot[i][nu*2+1], dot[i][nu]);
    }
}
int lg, rg;
pair <int, int> que(int i, int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[i][nu];
    else if(l>rg or r<lg) return {inf, inf};
    else
    {
        int mid=(l+r)>>1;
        pair <int, int> re;
        recalc(que(i, nu*2, l, mid), que(i, nu*2+1, mid+1, r), re);
        return re;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<n; a++)
    {
        int x, x2;
        scanf("%d", &x);
        x2=x;
        for(int i=0; i<9; i++) ar[i][a]=(x%10) ? x2 : inf, x/=10;
    }
    for(int i=0; i<9; i++) build(i, 1, 0, n-1);
    for(int a=0; a<m; a++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty==1)
        {
            int x, x2;
            scanf("%d%d", &p, &x);
            p--, x2=x;
            for(int i=0; i<9; i++) ar[i][p]=(x%10) ? x2 : inf, x/=10, cha(i, 1, 0, n-1);
        }
        else
        {
            int an=inf;
            scanf("%d%d", &lg, &rg);
            lg--, rg--;
            for(int i=0; i<9; i++)
            {
                pair <int, int> re=que(i, 1, 0, n-1);
                if(re.second!=inf) an=min(an, re.first+re.second);
            }
            if(an==inf) printf("-1\n");
            else printf("%d\n", an);
        }
    }
}