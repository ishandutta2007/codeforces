#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10, inf=1e9;
int ar[sz], dot[sz*4];
void build(int nu, int l, int r)
{
    if(l==r) dot[nu]=ar[l];
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        dot[nu]=min(dot[nu*2], dot[nu*2+1]);
    }
}
int p;
void cha(int nu, int l, int r)
{
    if(l==r)
    {
        dot[nu]=inf;
    }
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
    if(l>=lg and r<=rg)
    {
        return dot[nu];
    }
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
    int q;
    cin>>q;
    while(q)
    {
        q--;
        int n;
        scanf("%d", &n);
        int ok=1;
        vector <int> st[n+1];
        for(int a=0; a<n; a++)
        {
            scanf("%d", &ar[a]);
            st[ar[a]].push_back(a);
        }
        for(int a=1; a<=n; a++) reverse(st[a].begin(), st[a].end());
        build(1, 0, n-1);
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            if(st[x].size())
            {
                lg=0, rg=st[x].back();
                if(que(1, 0, n-1)==x)
                {
                    p=st[x].back(), st[x].pop_back();
                    cha(1, 0, n-1);
                }
                else ok=0;
            }
            else ok=0;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
}