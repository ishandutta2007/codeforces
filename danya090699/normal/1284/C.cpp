#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, mod;
    cin>>n>>mod;
    int fact[n+1], an=0;
    fact[0]=1;
    for(int a=1; a<=n; a++) fact[a]=(1ll*a*fact[a-1])%mod;
    for(int a=1; a<=n; a++)
    {
        int add=(1ll*(n-a+1)*(n-a+1))%mod;
        add=(1ll*add*fact[a])%mod;
        add=(1ll*add*fact[n-a])%mod;
        an=(an+add)%mod;
    }
    cout<<an;
}