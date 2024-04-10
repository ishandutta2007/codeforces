#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, d1, d2, mi=inf, ma=-inf;
    cin>>n>>k>>d1>>d2;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int a=0; a<=n; a++)
            {
                int s=a*k;
                if(i) s+=d1;
                else s+=(k-d1);
                if(j) s+=d2;
                else s+=(k-d2);

                s%=(n*k);

                mi=min(mi, (n*k)/__gcd(n*k, s));

                ma=max(ma, (n*k)/__gcd(n*k, s));
            }
        }
    }
    cout<<mi<<" "<<ma;
}