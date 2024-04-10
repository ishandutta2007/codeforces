#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long

#ifdef sarthak
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
int begtime = clock();
#else
#define trace(...)
#endif

#ifndef sarthak
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    // #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#define foreach(it,ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fort(i,v) for(auto i:v)
#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define fill(ar,val) rep(i,sizeof(ar)/sizeof(ll)) ar[i]=val
#define fill2(ar,val) rep(i,sizeof(ar)/sizeof(ar[0])) rep(j,sizeof(ar[0])/sizeof(ll)) ar[i][j]=val
#define fill0(ar) memset(ar,0,sizeof(ar))
#define debug(x) cout<<#x<<": "<<x<<endl

#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define sd2(x,y) scanf("%d %d",&x,&y)
#define slld2(x,y) scanf("%lld %lld",&x,&y)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define pd2(x,y) printf("%d %d\n",x,y)
#define plld2(x,y) printf("%lld %lld\n",x,y)
#define all(ar) ar.begin(), ar.end()
#define endl '\n'
#define sz(x) (int)x.size()
#define len(x) (int)x.length()

typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<ll> vi;

#define INF 1000000000000000000
#define PI 3.14159265358979323846L

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngb(chrono::steady_clock::now().time_since_epoch().count()); // can give negative values too

bool done[200001];

void solve()
{
    ll n;
    cin >> n;

    string s;
    cin >> s;

    vector<ll> v;
    for(ll i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
            v.pb(i);
        if(i==1)
            continue;
        if(i*i!=n)
            v.pb(n/i);
    }

    bool hu = 0;
    bool du = 1;    
    ll ans = 0;

    rep(i,n)
    {
        if(s[i]=='1')
            du = 0;
    }
    
    if(du)
    {
        cout << n << endl;
        return;
    }

    rep(i,sz(v))
    {
        ll per = v[i];
        ll vis[n];
        fill0(vis);
        bool du2 = 1;

        rep(j,n)
        {
            if(vis[j])
                break;
            ll k = j;
            ll xo2 = 0;
            while(!vis[k])
            {
                xo2 = xo2^(s[k]-'0');
                vis[k] = 1;
                k = k+per;
                k %=n;
            }
            if(xo2!=0)
                du2 = 0;
        }

        if(du2)
            done[per] = 1;
    }

    fr(i,1,n-1)
    {
        ll xx = __gcd(n,i);
        if(done[xx])
            ans++;
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed;
    cout << setprecision(10);
    #ifdef sarthak
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }

    #ifdef sarthak
    cerr << "Time elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
    #endif
}