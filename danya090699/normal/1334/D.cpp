#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, l, r, pref=0, x=1;
        scanf("%lld%lld%lld", &n, &l, &r);
        for(int a=l; a<=r; a++)
        {
            while(x<n and a>pref+(n-x)*2) pref+=(n-x)*2, x++;
            if(x==n) printf("1 ");
            else
            {
                if((a-pref)&1) printf("%lld ", x);
                else printf("%lld ", x+(a-pref)/2);
            }
        }
        printf("\n");
    }
}