#include <bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n], su[m], an=0;
    for(int a=0; a<m; a++) su[a]=0;
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    sort(ar, ar+n);
    for(int a=0; a<n; a++)
    {
        su[a%m]+=ar[a];
        an+=su[a%m];
        printf("%lld ", an);
    }
}