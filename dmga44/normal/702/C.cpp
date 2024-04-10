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
#define mod (int)(1e4+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

bool solve(vector<ll> &a,vector<ll> &b,ll x)
{
    bool res=1;
    for(auto y : a)
    {
        int pp=lower_bound(all(b),y+x+1)-lower_bound(all(b),y-x);
        if(!pp)
            res=0;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<ll> pa(n),pb(m);
    for(int i=0;i<n;i++)
        cin >> pa[i];
    for(int i=0;i<m;i++)
        cin >> pb[i];

    sort(all(pb));
    sort(all(pa));

    ll res=-1;
    for(ll po=(1ll<<32);po;po>>=1)
        if(!solve(pa,pb,res+po))
            res+=po;
    res++;
    db(res)

    return 0;
}
/**
3 2
-2 2 4
-3 0
**/