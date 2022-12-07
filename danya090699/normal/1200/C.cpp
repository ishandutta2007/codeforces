#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q;
    cin>>n>>m>>q;
    int d=__gcd(n, m);
    for(int a=0; a<q; a++)
    {
        int ty1, nu1, ty2, nu2;
        cin>>ty1>>nu1>>ty2>>nu2;
        nu1--;
        if(ty1==1) nu1=nu1/(n/d);
        else nu1=nu1/(m/d);

        nu2--;
        if(ty2==1) nu2=nu2/(n/d);
        else nu2=nu2/(m/d);

        if(nu1==nu2) cout<<"YES\n";
        else cout<<"NO\n";
    }
}