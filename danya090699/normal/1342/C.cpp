#include <bits/stdc++.h>
#define int long long
using namespace std;
int f(int n, int a, int b)
{
    int x=a*b/__gcd(a, b);
    return n-(n/x*b+min(n%x, b));
}
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int a, b, q;
        cin>>a>>b>>q;
        if(a>b) swap(a, b);
        for(int i=0; i<q; i++)
        {
            int l, r;
            scanf("%lld%lld", &l, &r);
            printf("%lld ", f(r+1, a, b)-f(l, a, b));
        }
        printf("\n");
    }
}