#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long k;
        cin>>n>>k;
        int ar[n], mi=2e9, ma=-2e9;
        for(int a=0; a<n; a++)
        {
            scanf("%d", &ar[a]);
            mi=min(mi, ar[a]), ma=max(ma, ar[a]);
        }
        for(int a=0; a<n; a++)
        {
            if(k&1) printf("%d ", ma-ar[a]);
            else printf("%d ", ar[a]-mi);
        }
        printf("\n");
    }
}