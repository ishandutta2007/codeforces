#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], suf[n+1][2], cu=0, an=0;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        ar[a]=__builtin_popcountll(x);
    }
    suf[n][0]=1, suf[n][1]=0;
    for(int a=n-1; a>=0; a--)
    {
        suf[a][0]=suf[a+1][0], suf[a][1]=suf[a+1][1];
        cu=(cu+ar[a])%2;
        suf[a][cu]++;
        int r=min(a+65, n), su=0, ma=0;
        for(int b=a; b<r; b++)
        {
            su+=ar[b], ma=max(ma, ar[b]);
            if(ma<=su-ma and su%2==0) an++;
        }
        if(r<n) an+=suf[r+1][cu];
    }
    cout<<an;
}