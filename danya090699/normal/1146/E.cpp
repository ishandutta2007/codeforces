#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int add[sz*4][2], an[sz][2];
void push(int nu)
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++) add[nu*2+i][j]=add[nu][add[nu*2+i][j]];
    }
    add[nu][0]=0, add[nu][1]=1;
}
int lg, rg, va[2];
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        add[nu][0]=va[add[nu][0]];
        add[nu][1]=va[add[nu][1]];
    }
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
    }
}
void dfs(int nu, int l, int r)
{
    if(l==r)
    {
        an[l][0]=add[nu][0], an[l][1]=add[nu][1];
    }
    else
    {
        int mid=(l+r)>>1;
        push(nu);
        dfs(nu*2, l, mid);
        dfs(nu*2+1, mid+1, r);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int a=0; a<sz*4; a++) add[a][0]=0, add[a][1]=1;
    for(int a=0; a<q; a++)
    {
        char ty[2];
        int x;
        scanf("%s%d", ty, &x);
        if(ty[0]=='<')
        {
            if(x<=0)
            {
                x=-x;
                lg=x+1, rg=sz-1, va[0]=0, va[1]=0, cha(1, 0, sz-1);
            }
            else
            {
                lg=0, rg=x-1, va[0]=1, va[1]=0, cha(1, 0, sz-1);
                lg=x, rg=sz-1, va[0]=0, va[1]=0, cha(1, 0, sz-1);
            }
        }
        else
        {
            if(x>=0)
            {
                lg=x+1, rg=sz-1, va[0]=1, va[1]=1, cha(1, 0, sz-1);
            }
            else
            {
                x=-x;
                lg=0, rg=x-1, va[0]=1, va[1]=0, cha(1, 0, sz-1);
                lg=x, rg=sz-1, va[0]=1, va[1]=1, cha(1, 0, sz-1);
            }
        }
    }
    dfs(1, 0, sz-1);
    for(int a=0; a<n; a++)
    {
        int x=ar[a];
        if(x>=0)
        {
            if(an[x][0]==1) x=-x;
        }
        else
        {
            if(an[-x][1]==0) x=-x;
        }
        printf("%d ", x);
    }
}