#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll gcd(ll a,ll b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,k,a,b;
    cin >> n >> k >> a >> b;
    ll mi=(ll)(1e18),ma=0;
    for(ll i=0;i<n;i++)
    {
        ll p1=a;
        ll p2=b+(k*i);
        ll dif=(p1-p2+n*k)%(n*k);
        ll res=(n*k)/(gcd(n*k,dif));
        mi=min(res,mi);
        ma=max(res,ma);
    }

    for(ll i=0;i<n;i++)
    {
        ll p1=k-a;
        ll p2=b+(k*i);
        ll dif=(p1-p2+n*k)%(n*k);
        ll res=(n*k)/(gcd(n*k,dif));
        mi=min(res,mi);
        ma=max(res,ma);
    }

    for(ll i=0;i<n;i++)
    {
        ll p1=a;
        ll p2=k-b+(k*i);
        ll dif=(p1-p2+n*k)%(n*k);
        ll res=(n*k)/(gcd(n*k,dif));
        mi=min(res,mi);
        ma=max(res,ma);
    }

    for(ll i=0;i<n;i++)
    {
        ll p1=k-a;
        ll p2=k-b+(k*i);
        ll dif=(p1-p2+n*k)%(n*k);
        ll res=(n*k)/(gcd(n*k,dif));
        mi=min(res,mi);
        ma=max(res,ma);
    }

    cout << mi << ' ' << ma << '\n';

    return 0;
}