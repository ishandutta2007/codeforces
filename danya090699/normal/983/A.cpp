#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int p, q, b;
        scanf("%lld%lld%lld", &p, &q, &b);
        q/=__gcd(p, q);
        while(__gcd(b, q)!=1)
        {
            int x=__gcd(b, q);
            while(q%x==0) q/=x;
        }
        if(q==1) printf("Finite\n");
        else printf("Infinite\n");
    }
}