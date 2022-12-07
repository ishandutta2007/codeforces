#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n], d[m];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    for(int a=0; a<m; a++) scanf("%lld", &d[a]);
    int g=0, fo=0;
    for(int a=0; a+1<n; a++) g=__gcd(g, ar[a+1]-ar[a]);
    for(int a=0; a<m; a++)
    {
        if(g%d[a]==0)
        {
            cout<<"YES\n"<<ar[0]<<" "<<a+1;
            fo=1;
            break;
        }
    }
    if(fo==0) cout<<"NO";
}