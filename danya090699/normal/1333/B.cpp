#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, pl=0, mi=0, ok=1;
        scanf("%d", &n);
        int ar[n];
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            if(x>ar[a] and !pl) ok=0;
            if(x<ar[a] and !mi) ok=0;
            if(ar[a]==1) pl=1;
            if(ar[a]==-1) mi=1;
        }
        printf(ok ? "YES\n" : "NO\n");
    }
}