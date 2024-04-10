#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,m;
        cin >> n >> m;
        if(m==0)
            db(0)
        else
        {
            ll tot=(n*(n+1))/2;
            n-=m;
            m++;
            ll mi=n/m;
            ll dif=n%m;
            ll dif2=m-dif;
            dif2=dif2*((mi*(mi+1))/2);
            dif=dif*(((mi+2)*(mi+1))/2);
            tot-=(dif+dif2);
            db(tot)
        }
    }

    return 0;
}