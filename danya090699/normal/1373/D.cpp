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
        scanf("%d", &n);
        int ar[n];
        long long su=0, add=0;
        for(int a=0; a<n; a++)
        {
            scanf("%d", &ar[a]);
            if(a%2==0) su+=ar[a];
        }
        for(int i=0; i<2; i++)
        {
            long long mi=0, cu=0;
            for(int a=i; a+1<n; a+=2)
            {
                cu-=ar[a+i];
                cu+=ar[a+(i^1)];
                add=max(add, cu-mi);
                mi=min(mi, cu);
            }
        }
        printf("%lld\n", su+add);
    }
}