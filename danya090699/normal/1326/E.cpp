#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
int dot[sz*4], add[sz*4];
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
    int n;
    cin>>n;
    int p[n], yk=n-1;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        x--, p[x]=a;
    }
    for(int a=0; a<n; a++)
    {
        while(1)
        {
            lg=0, rg=p[yk], va=1, cha(1, 0, n-1);
            if(dot[1]+add[1]>0)
            {
                va=-1, cha(1, 0, n-1);
                break;
            }
            else yk--;
        }
        scanf("%d", &rg);
        lg=0, rg--, va=-1, cha(1, 0, n-1);

        printf("%d ", yk+1);
    }
}