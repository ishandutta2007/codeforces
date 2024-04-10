#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

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
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> ac(n+1);
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(allr(a));
    for(int i=0;i<n;i++)
        ac[i+1]=ac[i]+a[i];
    ll res1=0;
    for(ll i=0;i<n;i++)
        res1+=i*a[i];

    int q;
    cin >> q;
    while(q--)
    {
        ll k;
        cin >> k;
        if(k==1)
            cout << res1 << ' ';
        else
        {
            int p=1;
            ll sz=k;
            ll mul=1;
            ll res=0;
            while(p+sz<=n)
            {
                res+=mul*(ac[sz+p]-ac[p]);
                p+=sz;
                mul++;
                sz*=k;
            }
            res+=mul*(ac[n]-ac[p]);
            cout << res << ' ';
        }
    }
    cout << '\n';

    return 0;
}
/**
5
2 3 4 1 1
2
2 3
**/