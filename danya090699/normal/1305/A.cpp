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
        cin>>n;
        for(int i=0; i<2; i++)
        {
            int ar[n];
            for(int a=0; a<n; a++) scanf("%d", &ar[a]);
            sort(ar, ar+n);
            for(int a=0; a<n; a++) printf("%d ", ar[a]);
            printf("\n");
        }
    }
}