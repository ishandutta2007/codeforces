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
        int ar[n];
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        if(ar[0]<ar[n-1]) printf("YES\n");
        else printf("NO\n");
    }
}