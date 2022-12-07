#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, m;
    cin>>n>>k>>m;
    int ar[n], su=0;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        su+=ar[a];
    }
    sort(ar, ar+n);
    double an=0;
    for(int a=0; a<min(n, m+1); a++)
    {
        int le=m-a;
        le=min(le, k*(n-a));
        an=max(an, 1.0*(su+le)/(n-a));
        su-=ar[a];
    }
    cout<<fixed<<setprecision(10)<<an;
}