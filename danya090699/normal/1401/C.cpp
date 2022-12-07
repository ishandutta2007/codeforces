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
        cin>>n;
        int ar[n], ar2[n], mi=1e9+10, ok=1;
        for(int a=0; a<n; a++)
        {
            scanf("%d", &ar[a]);
            mi=min(mi, ar[a]);
            ar2[a]=ar[a];
        }
        sort(ar2, ar2+n);
        for(int a=0; a<n; a++)
        {
            if(ar[a]%mi and ar[a]!=ar2[a]) ok=0;
        }
        printf(ok ? "YES\n" : "NO\n");
    }
}