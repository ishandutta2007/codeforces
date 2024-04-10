#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, s, an=0;
    cin>>n>>s;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    sort(ar, ar+n);
    if(ar[n/2]<s)
    {
        for(int a=n/2; a<n; a++) if(ar[a]<s) an+=s-ar[a];
    }
    if(ar[n/2]>s)
    {
        for(int a=0; a<=n/2; a++) if(ar[a]>s) an+=ar[a]-s;
    }
    cout<<an;
}