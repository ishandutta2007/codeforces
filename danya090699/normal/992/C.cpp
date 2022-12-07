#include <bits/stdc++.h>
#define int long long
using namespace std;
int po(int x, int y, int mod)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(re*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int x, k, mod=1e9+7;
    cin>>x>>k;
    if(x==0) cout<<0;
    else
    {
        int re=((x%mod)*po(2, k+1, mod))%mod;
        re-=po(2, k, mod), re++;
        if(re<0) re+=mod;
        re%=mod;
        cout<<re;
    }
}