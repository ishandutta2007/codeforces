#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], an=0, be;
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    for(int i=0; i<=60; i++)
    {
        int q=0;
        for(int a=0; a<n; a++) if(ar[a]%(1ll<<i)==0 and ((ar[a]>>i)&1ll)) q++;
        if(an<q) an=q, be=i;
    }
    cout<<n-an<<"\n";
    for(int a=0; a<n; a++)
    {
        if(!(ar[a]%(1ll<<be)==0 and ((ar[a]>>be)&1ll))) printf("%lld ", ar[a]);
    }
}