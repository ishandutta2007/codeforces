#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int x=po(2, m)-1;
    if(x<0) x+=mod;
    cout<<po(x, n);
}