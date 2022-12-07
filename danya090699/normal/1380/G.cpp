#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
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
    int n;
    cin>>n;
    int pref[n];
    for(int a=0; a<n; a++) scanf("%d", &pref[a]);
    sort(pref, pref+n, greater <int>());
    for(int a=1; a<n; a++) pref[a]=(pref[a-1]+pref[a])%mod;
    int rev=po(n, mod-2);
    for(int a=1; a<=n; a++)
    {
        int an=0;
        for(int i=0; a*i<n; i++)
        {
            int l=a*i, r=min(l+a-1, n-1);
            int add=pref[r];
            if(l)
            {
                add-=pref[l-1];
                if(add<0) add+=mod;
            }
            an=(an+1ll*add*i)%mod;
        }
        printf("%d ", 1ll*an*rev%mod);
    }
}