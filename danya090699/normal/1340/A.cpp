#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, ok=1;
        scanf("%d", &n);
        int ar[n];
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        for(int a=0; a+1<n; a++)
        {
            if(ar[a]<ar[a+1])
            {
                if(ar[a]+1!=ar[a+1]) ok=0;
            }
        }
        printf(ok ? "Yes\n" : "No\n");
    }
}