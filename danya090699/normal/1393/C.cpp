#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int q[n], ma=0;
        for(int a=0; a<n; a++) q[a]=0;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            x--, q[x]++, ma=max(ma, q[x]);
        }
        int m=0;
        for(int a=0; a<n; a++) if(q[a]==ma) m++;
        printf("%d\n", (n-m)/(ma-1)-1);
    }
}