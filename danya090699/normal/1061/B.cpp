#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n+1], r=0, an=0;
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a]);
        r=max(r, ar[a]);
    }
    ar[n]=0;
    sort(ar, ar+n+1);
    for(int a=n; a-1>=0; a--)
    {
        int l=min(ar[a-1], r-1);
        l=max(l, 0ll);
        an+=ar[a]-(r-l);
        r=max(l, 1ll);
        //cout<<r<<" "<<an
    }
    cout<<an;
}