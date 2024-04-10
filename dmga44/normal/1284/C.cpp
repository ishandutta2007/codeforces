#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
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
typedef complex<ld> point;
#define MAXN 250005

ll fac[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    fac[0]=1;
    for(ll i=1;i<MAXN;i++)
        fac[i]=(fac[i-1]*i)%m;
    ll res=0;
    for(ll i=1;i<=n;i++)
    {
        ll p=n-i+1;
        ll f1=fac[i];
        ll f2=fac[n-i];
        ll add=(p*p)%m;
        add=(add*f1)%m;
        add=(add*f2)%m;
        res=(res+add)%m;
    }
    db(res)

    return 0;
}
/**
5
1 1
1 1
1 2
1 4
1 3
**/