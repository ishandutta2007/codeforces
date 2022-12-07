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
        scanf("%d", &n);
        int ar[n], ok=1;
        long long su=0;
        for(int a=0; a<n; a++)
        {
            scanf("%d", &ar[a]);
            su+=ar[a];
            if(a+1<n and su<=0) ok=0;
        }
        su=0;
        for(int a=n-1; a>=0; a--)
        {
            su+=ar[a];
            if(a and su<=0) ok=0;
        }
        printf(ok ? "YES\n" : "NO\n");
    }
}