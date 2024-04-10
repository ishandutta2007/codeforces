//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=11e5;
int n, k, an=0, dp[sz], sm[50], fh;
void dfs(int mask, int to, int last, int q)
{
    int mask2=(to&fh);
    an=max(an, q+dp[mask2]);
    for(int b=last+1; b<n; b++)
    {
        if((mask&sm[b])==mask) dfs(mask+(1ll<<b), (to&sm[b]), b, q+1);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k;
    fh=(1ll<<(n/2))-1;
    for(int a=0; a<n; a++)
    {
        sm[a]=0;
        for(int b=0; b<n; b++)
        {
            int x;
            cin>>x;
            sm[a]+=x*(1ll<<b);
        }
    }
    dp[0]=0;
    queue <pair <int, int> > qu;
    qu.push(make_pair(0, -1));
    while(qu.size()>0)
    {
        int q=qu.size();
        for(int a=0; a<q; a++)
        {
            int mask=qu.front().first, last=qu.front().second;
            an=max(an, dp[mask]);
            for(int b=last+1; b<n/2; b++)
            {
                int mask2=(sm[b]&mask), nmask=mask+(1ll<<b);
                dp[nmask]=max(dp[mask], dp[mask2]+1);
                qu.push(make_pair(nmask, b));
            }
            qu.pop();
        }
    }
    for(int a=n/2; a<n; a++) dfs((1ll<<a), sm[a], a, 1);
    cout<<fixed<<setprecision(10)<<(k*k*(an-1))/(2.0*an);
}