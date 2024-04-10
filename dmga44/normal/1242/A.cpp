#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    if(n==1)
    {
        db(1)
        return 0;
    }
    else if(n==2)
    {
        db(2)
        return 0;
    }

    vector<ll> primes;
    for(ll i=2;i<=1e6+5;i++)
    {
        if(n%i==0)
        {
            primes.push_back(i);
            while(n%i==0)
                n/=i;
        }
    }
    if(n!=1)
        primes.push_back(n);

    if(primes.size()==1)
        db(primes[0])
    else
        db(1)

    return 0;
}