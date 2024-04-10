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

vector<ll> ed[101];
ll mat[101][101];

void solve()
{
    ll n,m;
    cin >> n >> m;

    fr(i,1,n)
    {
        fr(j,1,n)
        {
            mat[i][j] = INF;
        }
        mat[i][i] = 0;
    }

    rep(i,m)
    {
        ll u,v;
        cin >> u >> v;
        ed[u].pb(v);
        ed[v].pb(u);
        mat[u][v] = min(mat[u][v],1ll);
        mat[v][u] = min(mat[v][u],1ll);
    }

    ll dp[n+1][n+1];
    fr(i,1,n)
    {
        fr(j,1,n)
        {
            dp[i][j] = mat[i][j];               
        }
    }
    fr(k,1,n)
    {
        fr(i,1,n)
        {
            fr(j,1,n)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);   
            }
        }
    }
    
    ll s,b,k,h;
    cin >> s >> b >> k >> h;
    ll ans = h*s;

    vector<pair<ll, pair<ll, ll> > > v1;
    vector<pair<ll, ll> > v2;

    rep(i,s)
    {
        ll x,a,f;
        cin >> x >> a >> f;
        v1.pb(mp(x,mp(a,f)));
    }
    rep(i,b)
    {
        ll x,d;
        cin >> x >> d;
        v2.pb(mp(x,d));
    }

    bool canbe[b+1];
    fill0(canbe);
    map<pair<ll, ll> , ll> m1;
    ll numm[s];
    fill0(numm);
    vector<ll> which[b];

    rep(i,s)
    {
        rep(j,b)
        {
            ll u = v1[i].ff;
            ll v = v2[j].ff;
            ll f = v1[i].ss.ss;
            ll a = v1[i].ss.ff;
            ll d = v2[j].ss;

            if(dp[u][v]<=f && a>=d)
            {
                numm[i]++;
                which[j].pb(i);
            }
        }
        m1[mp(numm[i],i)];
    }

    while(m1.size())
    {
        auto it = m1.begin();
        ll num2 = it->first.ff;
        ll ind = it->first.ss;
        m1.erase(it);

        numm[ind] = 0;
        if(num2==0)
            continue;

        rep(i,b)
        {
            ll u = v1[ind].ff;
            ll v = v2[i].ff;
            ll f = v1[ind].ss.ss;
            ll a = v1[ind].ss.ff;
            ll d = v2[i].ss;

            if(dp[u][v]<=f && a>=d && (!canbe[i]))
            {
                canbe[i] = 1;
                rep(j,which[i].size())
                {
                    if(numm[which[i][j]]!=0)
                    {
                        m1.erase(mp(numm[which[i][j]],which[i][j]));
                        numm[which[i][j]]--;
                        m1[mp(numm[which[i][j]],which[i][j])];
                    }
                }
                break;
            }
        }
    }

    ll num = 0;
    rep(i,b)
    {
        if(canbe[i])
            num++;
    }
    
    ans = min(ans,num*k);

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