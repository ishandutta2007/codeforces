#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n, ok=1;
        cin>>n;
        int A[n], B[n], su=0;
        for(int a=0; a<n; a++)
        {
            scanf("%lld", &A[a]);
            su-=A[a];
        }
        for(int a=0; a<n; a++)
        {
            scanf("%lld", &B[a]);
            su+=B[a];
        }
        int x=0, ma=-1e9;
        for(int a=0; a<n*2; a++)
        {
            x-=A[a%n];
            ma=max(ma, x);
            x+=B[a%n];
            if(x-ma<0)
            {
                ok=0;
                break;
            }
        }
        if(su<0) ok=0;

        printf(ok ? "YES\n" : "NO\n");
    }
}