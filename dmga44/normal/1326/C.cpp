#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005
#define mod (ll)(998244353)

int p[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin >> n >> k;
    vector<pii> ps;
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
        ps.push_back(pii(p[i],i));
    }

    sort(all(ps));

    vector<ll> inter;
    for(int i=0;i<k;i++)
        inter.push_back(ps[n-i-1].second);

    sort(all(inter));

    ll r1=0;
    for(int i=0;i<k;i++)
        r1+=(n-i);

    ll r2=1;
    for(int i=0;i<k-1;i++)
        r2=(r2*(inter[i+1]-inter[i]))%mod;
    cout << r1 << ' ' << r2 << '\n';

    return 0;
}