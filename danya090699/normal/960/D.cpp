#include <bits/stdc++.h>
#define int long long
using namespace std;
int d[60];
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int ty, x, k, l=0;
        scanf("%lld%lld", &ty, &x);
        while((1ll<<l)<=x) l++;
        l--;
        if(ty==1)
        {
            scanf("%lld", &k);
            k=(k+(1ll<<60))%(1ll<<l);
            d[l]=(d[l]+k)%(1ll<<l);
        }
        if(ty==2)
        {
            scanf("%lld", &k);
            k=(k+(1ll<<60))%(1ll<<l);
            for(int b=l; b<60; b++)
            {
                d[b]=(d[b]+k)%(1ll<<b), k*=2;
            }
        }
        if(ty==3)
        {
            int p=(1ll<<l)+(x-(1ll<<l)+d[l])%(1ll<<l);
            for(int b=l; b>=0; b--)
            {
                int nu=p-d[b];
                if(nu<(1ll<<b)) nu+=(1ll<<b);
                printf("%lld ", nu);
                p>>=1;
            }
            printf("\n");
        }
    }
}