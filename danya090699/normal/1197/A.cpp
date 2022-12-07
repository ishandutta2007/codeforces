#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n;
        scanf("%d", &n);
        int ar[n];
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        sort(ar, ar+n);
        printf("%d\n", min(ar[n-2]-1, n-2));
    }
}