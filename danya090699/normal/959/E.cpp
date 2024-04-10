#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=45;
main()
{
    int n, an=0;
    cin>>n;
    int dp[sz];
    dp[0]=0;
    for(int a=1; a<sz; a++) dp[a]=dp[a-1]*2+(1ll<<(a-1));
    for(int a=sz-1; a>=0; a--)
    {
        if(n>=(1ll<<a))
        {
            an+=dp[a];
            n-=(1ll<<a);
            if(n) an+=(1ll<<a);
        }
    }
    cout<<an;
}