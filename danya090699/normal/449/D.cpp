#include <bits/stdc++.h>
using namespace std;
const int sz=20, mod=1e9+7;
int dp[1<<sz], st[1<<sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        dp[x]++;
        st[a+1]=(st[a]*2+1)%mod;
    }
    for(int i=0; i<sz; i++)
    {
        for(int mask=0; mask<(1<<sz); mask++)
        {
            if((mask&(1<<i))==0) dp[mask]+=dp[mask+(1<<i)];
        }
    }
    for(int mask=0; mask<(1<<sz); mask++)
    {
        int q=__builtin_popcount(mask);
        if(q&1) an-=st[dp[mask]];
        else an+=st[dp[mask]];
        if(an<0) an+=mod;
        if(an>=mod) an-=mod;
    }
    cout<<an;
}