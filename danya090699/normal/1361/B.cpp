#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=1ll*re*x%mod;
        y>>=1;
        x=1ll*x*x%mod;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, p;
        scanf("%d%d", &n, &p);
        int ar[n];
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        sort(ar, ar+n, greater <int>());
        int d=0, power=0, fo=0, an;
        for(int a=0; a<n; a++)
        {
            if(d)
            {
                if(p!=1)
                {
                    while(power>ar[a] and 2000000/p>d)
                    {
                        power--, d*=p;
                    }
                }
                else power=ar[a];

                if(power>ar[a])
                {
                    fo=1;
                    an=1ll*d*po(p, power)%mod;
                    for(int b=a; b<n; b++)
                    {
                        an-=po(p, ar[b]);
                        if(an<0) an+=mod;
                    }
                    break;
                }
                else d--;
            }
            else d=1, power=ar[a];
        }
        if(!fo) an=1ll*d*po(p, power)%mod;
        printf("%d\n", an);
    }
}