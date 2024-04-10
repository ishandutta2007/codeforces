#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

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
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
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
#define MAXN (ll)(3e2+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    vector<ll> t(n);
    vector<ll> ts[4];
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> t[i];
        cin >> a >> b;
        ts[a*2+b].push_back(t[i]);
    }

    for(int i=0;i<4;i++)
        sort(all(ts[i]));

    if(ts[3].size()+ts[1].size()<k || ts[3].size()+ts[2].size()<k)
    {
        db(-1)
        return 0;
    }

    vector<ll> acs[4];
    for(int i=0;i<4;i++)
    {
        acs[i].push_back(0);
        for(auto y : ts[i])
            acs[i].push_back(acs[i].back()+y);
    }

    ll res=1e10;
    for(int i=0;i<=k;i++)
        if(acs[3].size()>i && acs[1].size()>k-i && acs[2].size()>k-i)
            res=min(res,acs[3][i]+acs[1][k-i]+acs[2][k-i]);
    db(res)

    return 0;
}