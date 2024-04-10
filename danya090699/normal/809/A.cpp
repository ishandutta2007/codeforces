#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0, mod=1e9+7;
    cin>>n;
    int ar[n], st2[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    sort(ar, ar+n);
    st2[0]=1;
    for(int a=1; a<n; a++) st2[a]=(st2[a-1]*2)%mod;
    for(int a=0; a<n; a++)
    {
        an=(an+ar[a]*st2[a])%mod;
        an=an-(ar[a]*st2[n-a-1])%mod;
        if(an<0) an+=mod;
    }
    cout<<an;
}