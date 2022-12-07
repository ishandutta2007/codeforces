#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    if(n==1) cout<<ar[0];
    else
    {
        sort(ar, ar+n);
        int su=ar[n-1]-ar[0];
        for(int a=1; a<n-1; a++) su+=abs(ar[a]);
        cout<<su;
    }

}