#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], st[n+1];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    st[0]=1;
    for(int a=1; a<=n; a++) st[a]=(st[a-1]*2)%mod;
    int su=0, q=0;
    for(int a=0; a<n; a++)
    {
        su=(su*2)%mod;
        if(a>0) su=(su+ar[a-1])%mod;
        q=(q+1ll*(su+ar[a])*st[n-1-a])%mod;
    }
    cout<<q;
}