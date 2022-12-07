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
        int q[n+1], su=0, an=0;
        for(int a=1; a<=n; a++) q[a]=0;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            q[x]++;
        }
        for(int a=1; a<=n; a++)
        {
            su+=q[a];
            int add=su/a;
            an+=add, su-=add*a;
        }
        printf("%d\n", an);
    }
}