#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, inf=1e9;
int dot[sz*4];
int p, va;
void cha(int nu, int l, int r)
{
    if(l==r) dot[nu]=va;
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        dot[nu]=min(dot[nu*2], dot[nu*2+1]);
    }
}
int lg, rg;
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu];
    else if(l>rg or r<lg) return inf;
    else
    {
        int mid=(l+r)>>1;
        return min(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int last[n+1], us[n+2];
    for(int a=0; a<=n; a++) last[a]=0;
    for(int a=0; a<n+2; a++) us[a]=0;
    for(int a=1; a<=n; a++)
    {
        int x;
        scanf("%d", &x);
        x--;
        if(x)
        {
            us[0]=1;
            lg=0, rg=x-1;
            if(que(1, 0, n)>last[x]) us[x]=1;
        }
        last[x]=a;
        p=x, va=a, cha(1, 0, n);
    }
    for(int a=1; a<=n; a++)
    {
        lg=0, rg=a-1;
        if(que(1, 0, n)>last[a]) us[a]=1;
    }
    for(int a=0; ; a++)
    {
        if(!us[a])
        {
            cout<<a+1;
            break;
        }
    }
}