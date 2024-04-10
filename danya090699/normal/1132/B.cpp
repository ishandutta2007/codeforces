#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    long long su=0;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        su+=ar[a];
    }
    sort(ar, ar+n);
    int m;
    cin>>m;
    for(int a=0; a<m; a++)
    {
        int q;
        scanf("%d", &q);
        printf("%lld\n", su-ar[n-q]);
    }
}