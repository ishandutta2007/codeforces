#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int st[n+1];
    st[0]=1;
    for(int a=1; a<=n; a++) st[a]=(10ll*st[a-1])%mod;
    for(int a=1; a<n; a++)
    {
        int q=((n-a-2+1)*10*9*9)%mod;
        if(a<=n-2) q=1ll*q*st[n-2-a]%mod;
        q=(q+10ll*2*9*st[n-1-a])%mod;
        printf("%d ", q);
    }
    cout<<10;
}