#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int ar[sz], p[sz], n, dot[sz*4];
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=ar[l];
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        dot[nu]=max(dot[nu*2], dot[nu*2+1]);
    }
}
int lg, rg;
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu];
    else if(l>rg or r<lg) return -1;
    else
    {
        int mid=(l+r)>>1;
        return max(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
    }
}
int an=0;
void dfs(int l, int r)
{
    lg=l, rg=r;
    int x=que(1, 0, n-1);
    if(p[x]-l<r-p[x])
    {
        for(int a=l; a<p[x]; a++)
        {
            if(p[x-ar[a]]>p[x] and p[x-ar[a]]<=r) an++;
        }
    }
    else
    {
        for(int a=p[x]+1; a<=r; a++)
        {
            if(p[x-ar[a]]>=l and p[x-ar[a]]<p[x]) an++;
        }
    }
    if(p[x]!=l) dfs(l, p[x]-1);
    if(p[x]!=r) dfs(p[x]+1, r);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        p[ar[a]]=a;
    }
    build(1, 0, n-1);
    dfs(0, n-1);
    cout<<an;
}