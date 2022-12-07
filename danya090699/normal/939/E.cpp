#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=5e5+10;
int pref[sz];
double f(int x, int q)
{
    return (x+pref[q])/(1.0*(q+1));
}
main()
{
    //freopen("input.txt", "r", stdin);
    int q, n=0;
    cin>>q;
    double an=-1;
    for(int a=0; a<q; a++)
    {
        int ty;
        scanf("%lld", &ty);
        if(ty==1)
        {
            int x;
            scanf("%lld", &x), n++, pref[n]=pref[n-1]+x;
            int l=0, r=n-1;
            while(r-l>2)
            {
                int p=(l+r)>>1, p2=((l+r)>>1)+1;
                if(f(x, p)<f(x, p2)) r=p2;
                else l=p;
            }
            for(l; l<=r; l++) an=max(an, x-f(x, l));
        }
        else printf("%.10f\n", an);
    }
}