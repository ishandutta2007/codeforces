#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        int ar[n], fo=0, ok=(n==1);
        for(int a=0; a<n; a++)
        {
            scanf("%d", &ar[a]);
            if(ar[a]==k) fo=1;
        }
        for(int a=0; a<n; a++)
        {
            if(ar[a]>=k)
            {
                if(a+1<n and ar[a+1]>=k) ok=1;
                if(a+2<n and ar[a+2]>=k) ok=1;
            }
        }
        printf((fo and ok) ? "yes\n" : "no\n");
    }
}