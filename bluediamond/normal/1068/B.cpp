#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,a=0; cin>>n;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            a++;
            if(i*i==n) break;
            a++;
        }
    }
    cout<<a<<"\n";
    return 0;
}
/**

**/