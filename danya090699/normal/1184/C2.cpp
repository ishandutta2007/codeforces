#include <bits/stdc++.h>
using namespace std;
const int sz=4e6+10;
int dot[sz*4], add[sz*4];
vector <int> sp[sz];
void push(int nu)
{
    add[nu*2]+=add[nu];
    add[nu*2+1]+=add[nu];
    add[nu]=0;
}
void recalc(int nu)
{
    dot[nu]=max(dot[nu*2]+add[nu*2], dot[nu*2+1]+add[nu*2+1]);
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
    int n, r;
    cin>>n>>r;
    for(int a=0; a<n; a++)
    {
        int x0, y0;
        scanf("%d%d", &x0, &y0);
        int x=x0+y0+sz/2, y=x0-y0+sz/2;
        sp[x].push_back(y);
    }
    int yk=0, an=0;
    for(int a=0; a<sz; a++)
    {
        while(yk<min(sz, a+2*r+1))
        {
            for(int b=0; b<sp[yk].size(); b++)
            {
                int y=sp[yk][b];
                lg=max(0, y-2*r), rg=y, va=1;
                cha(1, 0, sz-1);
            }
            yk++;
        }
        an=max(an, dot[1]);
        for(int b=0; b<sp[a].size(); b++)
        {
            int y=sp[a][b];
            lg=max(0, y-2*r), rg=y, va=-1;
            cha(1, 0, sz-1);
        }
    }
    cout<<an;
}