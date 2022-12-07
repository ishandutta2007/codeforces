#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
inline int sum(int x, int y)
{
    return (x+y<mod) ? x+y : x+y-mod;
}
inline int dif(int x, int y)
{
    return (x-y>=0) ? x-y : x-y+mod;
}
inline int mul(int x, int y)
{
    return (1ll*x*y)%mod;
}
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=mul(re, x);
        y>>=1;
        x=mul(x, x);
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, an=0;
    cin>>n>>k;
    int st[n+1], rev[n+1];
    st[0]=1;
    for(int a=1; a<=n; a++)
    {
        st[a]=mul(st[a-1], k);
        rev[a]=po(dif(st[a], 1), mod-2);
    }
    for(int a2=1; a2<n; a2++)
    {
        vector <int> pr;
        int x=a2;
        for(int a=2; a*a<=x; a++)
        {
            if(x%a==0)
            {
                pr.push_back(a);
                while(x%a==0) x/=a;
            }
        }
        if(x>1) pr.push_back(x);

        int m=pr.size(), mask[1<<m];
        for(int a=0; a<(1<<m); a++)
        {
            mask[a]=1;
            for(int i=0; i<m; i++) if(a&(1<<i)) mask[a]*=pr[i];
        }

        for(int d=1; d*a2<n; d++)
        {
            int a=a2*d, l, r=min(n-(a-d), n-1)/d, q=0;
            for(int b=0; b<(1<<m); b++)
            {
                if(__builtin_popcount(b)&1) q-=r/mask[b];
                else q+=r/mask[b];
            }
            an=sum(an, mul(q, st[d]));
            l=r+1, r=(n-1)/d, q=0;
            for(int b=0; b<(1<<m); b++)
            {
                int lg=l/mask[b]+(l%mask[b]>0), rg=r/mask[b], k=d*mask[b];

                if(lg<=rg)
                {
                    int cnt=rg-lg+1, add;
                    lg=st[a-(n-lg*k)], rg=st[a-(n-rg*k)];

                    if(st[k]==1) add=mul(lg, cnt);
                    else add=mul(dif(mul(rg, st[k]), lg), rev[k]);

                    if(__builtin_popcount(b)&1) q=dif(q, add);
                    else q=sum(q, add);
                }
            }
            an=sum(an, q);
        }
    }
    an=mul(an, po(st[n], mod-2));
    cout<<an;
}