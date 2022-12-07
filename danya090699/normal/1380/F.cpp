#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10, mod=998244353;
int ar[sz], dot[sz*4][2][2];
void recalc(int nu)
{
    for(int a=0; a<2; a++)
    {
        for(int b=0; b<2; b++)
        {
            dot[nu][a][b]=0;
            for(int c=0; c<2; c++)
            {
                dot[nu][a][b]=(dot[nu][a][b]+1ll*dot[nu*2][a][c]*dot[nu*2+1][c][b])%mod;
            }
        }
    }
}
void build(int nu, int l, int r)
{
    if(l==r)
    {
        dot[nu][0][0]=ar[l]+1;
        dot[nu][0][1]=(ar[l]==1);
        dot[nu][1][0]=ar[l]+11-(ar[l]+1)*2;
        dot[nu][1][1]=0;
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
        dot[nu][0][0]=ar[l]+1;
        dot[nu][0][1]=(ar[l]==1);
        dot[nu][1][0]=ar[l]+11-(ar[l]+1)*2;
        dot[nu][1][1]=0;
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
    int n, m;
    cin>>n>>m;
    char s[n+1];
    scanf("%s", s);
    for(int a=0; a<n; a++) ar[a]=s[a]-'0';
    build(1, 0, n-1);
    for(int a=0; a<m; a++)
    {
        int x;
        scanf("%d%d", &p, &x);
        p--;
        ar[p]=x, cha(1, 0, n-1);
        printf("%d\n", dot[1][0][0]);
    }
}