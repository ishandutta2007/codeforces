#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], pref[n], suf[n], su=0;
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a]);
        if(a-2<0) pref[a]=ar[a];
        else pref[a]=pref[a-2]+ar[a];
        su+=ar[a];
    }
    for(int a=n-1; a>=0; a--)
    {
        if(a+2<n) suf[a]=suf[a+2]+ar[a];
        else suf[a]=ar[a];
    }
    int an=0;
    for(int a=0; a<n; a++)
    {
        int cu=su;
        if(a-1>=0) cu-=pref[a-1];
        if(a+2<n) cu-=suf[a+2];
        an=max(an, cu);
    }
    cout<<an;
}