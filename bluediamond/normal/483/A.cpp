#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool ok(ll a,ll b,ll c)
{
    if(__gcd(a,b)==1 && __gcd(b,c)==1 && __gcd(a,c)!=1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll l,r;
    cin>>l>>r;
    for(ll a=l;a<=r;a++)
    {
        for(ll b=a+1;b<=r;b++)
        {
            for(ll c=b+1;c<=r;c++)
            {
                if(ok(a,b,c))
                {
                    cout<<a<<" "<<b<<" "<<c<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"-1\n";
    return 0;
}
/**


**/