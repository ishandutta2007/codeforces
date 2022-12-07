#include <bits/stdc++.h>
using namespace std;
const int inf=2e9;
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
        int q[n], pr[n], an=inf;
        for(int a=0; a<n; a++) pr[a]=-1;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            x--;
            if(pr[x]!=-1) an=min(an, a-pr[x]+1);
            pr[x]=a;
        }
        if(an==inf) an=-1;
        printf("%d\n", an);
    }
}