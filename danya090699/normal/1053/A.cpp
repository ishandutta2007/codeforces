#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k, d;
    cin>>n>>m>>k;
    if((n*m*2)%k==0)
    {
        cout<<"YES\n";
        if(k%2)
        {
            if(__gcd(n, k)>1)
            {
                d=__gcd(n, k);
                k/=d, n/=d, n*=2, m/=k;
            }
            else
            {
                d=__gcd(m, k);
                k/=d, m/=d, m*=2, n/=k;
            }
        }
        else
        {
            k/=2;
            d=__gcd(n, k);
            k/=d, n/=d, m/=k;
        }
        cout<<"0 0\n";
        cout<<n<<" 0\n";
        cout<<"0 "<<m;
    }
    else cout<<"NO";
}