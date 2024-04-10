#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    int pref[n];
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &pref[a]);
        if(a>0) pref[a]+=pref[a-1];
    }
    int cu=0;
    for(int a=0; a<q; a++)
    {
        int x;
        scanf("%lld", &x);
        int p=upper_bound(pref, pref+n, x+cu)-pref;
        if(p==n)
        {
            cu=0;
            printf("%lld\n", n);
        }
        else
        {
            cu+=x;
            printf("%lld\n", n-p);
        }
    }
}