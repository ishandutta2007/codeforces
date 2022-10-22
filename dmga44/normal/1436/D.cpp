#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

vector<int> g[MAXN];
ll a[MAXN];
bool ok;

ll dfs(int u,ll x)
{
    bool is_leaf=1;
    ll sum=0;
    for(auto v : g[u])
    {
        is_leaf=0;
        sum+=dfs(v,x);
        sum=min(sum,(ll)1e16);
    }

    if(is_leaf)
    {
        if(a[u]>x)
        {
            ok=0;
            return 0;
        }
        else
            return x-a[u];
    }
    if(sum<a[u])
    {
        ok=0;
        return 0;
    }
    return sum-a[u];
}

bool solve(ll x)
{
    ok=1;
    dfs(0,x);
    return ok;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<n;i++)
    {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }

    for(int i=0;i<n;i++)
        cin >> a[i];

    ll res=-1;
    for(ll po=(1ll<<58);po;po>>=1)
        if(!solve(res+po))
            res+=po;
    db(res+1)

    return 0;
}