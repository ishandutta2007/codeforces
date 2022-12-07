#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, inf=1e9+10;
int ar[sz], dot[sz*4], lg, rg;
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
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, c;
    cin>>n>>c;
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    build(1, 0, n-1);
    long long dp[n+1], su=0;
    dp[0]=0;
    for(int a=1; a<=n; a++)
    {
        su+=ar[a-1];
        dp[a]=dp[a-1];
        if(a>=c)
        {
            lg=a-c, rg=a-1;
            dp[a]=max(dp[a], dp[a-c]+que(1, 0, n-1));
        }
    }
    cout<<su-dp[n];
}