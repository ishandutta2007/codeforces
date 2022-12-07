#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n, k, z, su=0, ma=0, an=0;
        cin>>n>>k>>z;
        int ar[n];
        for(int a=0; a<n; a++)
        {
            scanf("%d", &ar[a]);
            su+=ar[a];
            if(a)
            {
                ma=max(ma, ar[a]+ar[a-1]);
                for(int i=0; i<=z; i++)
                {
                    if(i*2+a==k) an=max(an, su+ma*i);
                    if(i<z and i*2+a+1==k) an=max(an, su+ma*i+ar[a-1]);
                }
            }
        }
        printf("%d\n", an);
    }
}