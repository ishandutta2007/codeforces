#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, q=1;
        scanf("%d", &n);
        int ar[n];
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        sort(ar, ar+n);
        for(int a=0; a<n; a++)
        {
            if(ar[a]<=a+1) q=a+2;
        }
        printf("%d\n", q);
    }
}