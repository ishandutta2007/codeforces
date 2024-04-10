#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while(t--)
    {
        ll n,g,b;
        cin >> n >> g >> b;
        ll x=n/(g+b);
        ll p1=x*g+min((n%(g+b)),g);
        if(p1*2>=n)
            db(n)
        else
        {
            ll tar=(n+1)/2;
            tar--;
            x=tar/g;
            db((x*(g+b))+(tar%g)+1)
        }
    }

    return 0;
}
/**
3
5 1 1
8 10 10
1000000000 1 1000000000
**/