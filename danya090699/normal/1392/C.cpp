#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n];
        long long an=0;
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        for(int a=1; a<n; a++) an+=max(0, ar[a-1]-ar[a]);
        printf("%lld\n", an);
    }
}