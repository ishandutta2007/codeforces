#include <bits/stdc++.h>
using namespace std;
const int sz=3e3+10;
vector <int> sp[sz], dot[sz*4];
long long su[sz], dp[sz][sz], an=0;
int n, k, q=0;
int lg, rg, va;
void add(int nu, int l, int r)
{
    if(l>=lg and r<=rg) dot[nu].push_back(va);
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        add(nu*2, l, mid);
        add(nu*2+1, mid+1, r);
    }
}
void build(int nu, int l, int r)
{
    for(int a=0; a<dot[nu].size(); a++)
    {
        int i=dot[nu][a];
        q++;
        for(int b=0; b<=k; b++)
        {
            dp[q][b]=dp[q-1][b];
            if(sp[i].size()<=b) dp[q][b]=max(dp[q][b], dp[q-1][b-sp[i].size()]+su[i]);
        }
    }

    if(l==r)
    {
        long long csu=0;
        for(int a=0; a<=min(int(sp[l].size()), k); a++)
        {
            an=max(an, csu+dp[q][k-a]);
            if(a<sp[l].size()) csu+=sp[l][a];
        }
    }
    else
    {
        int mid=(l+r)>>1;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
    }

    q-=dot[nu].size();
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k;
    for(int a=0; a<n; a++)
    {
        int m;
        cin>>m;
        sp[a].resize(m);
        for(int b=0; b<m; b++)
        {
            scanf("%d", &sp[a][b]);
            su[a]+=sp[a][b];
        }
        if(a) lg=0, rg=a-1, va=a, add(1, 0, n-1);

        if(a+1<n) lg=a+1, rg=n-1, va=a, add(1, 0, n-1);
    }
    build(1, 0, n-1);
    cout<<an;
}