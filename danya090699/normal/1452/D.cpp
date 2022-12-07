#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=1ll*re*x%mod;
        y>>=1;
        x=1ll*x*x%mod;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int su[2]={1, 0};
    for(int a=1; a<=n; a++)
    {
        int dp=su[(a&1)^1];
        su[a&1]=(su[a&1]+dp)%mod;

        if(a==n)
        {
            int an=1ll*dp*po(po(2, n), mod-2)%mod;
            cout<<an;
        }
    }
}