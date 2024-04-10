#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, x, an=0, su=0;
        scanf("%lld%lld", &n, &x);
        int ar[n];
        for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
        sort(ar, ar+n, greater <int>());
        for(int a=0; a<n; a++)
        {
            su+=ar[a];
            if(su/(a+1)>=x) an=a+1;
        }
        printf("%lld\n", an);
    }
}