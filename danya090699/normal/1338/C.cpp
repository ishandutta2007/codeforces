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
        int n, i=0, an=0;
        scanf("%lld", &n);
        n--;
        int nu=n/3;
        while(nu>=(1ll<<i)) nu-=(1ll<<i), i+=2;

        int ar[4][2][3]={
            {{0, 0, 0}, {0, 0, 0}},
            {{1, 0, 1}, {0, 1, 1}},
            {{0, 1, 1}, {1, 1, 0}},
            {{1, 1, 0}, {1, 0, 1}},
        };
        for(int a=0; a<i; a+=2)
        {
            for(int b=0; b<2; b++)
            {
                if(ar[nu%4][b][n%3]) an+=(1ll<<(a+b));
            }
            nu/=4;
        }
        if(n%3==0) an+=(1ll<<i);
        if(n%3==1) an+=(1ll<<(i+1));
        if(n%3==2) an+=(1ll<<i)+(1ll<<(i+1));

        printf("%lld\n", an);
    }
}