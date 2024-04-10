#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define oset tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

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

ll n,m;
char c[9][9];
ll ans = 0;
ll xx = 0;
ll rem = 0;

char an[9][9];

bool can(ll x, ll y, ll co)
{
    if(x+2>n-1 || y+2>m-1)
        return 0;

    if(co==0)
    {
        if(c[x][y]=='.' && c[x][y+1]=='.' && c[x][y+2]=='.' && c[x+1][y+1]=='.' && c[x+2][y+1]=='.')
            return 1;
    }
    if(co==1)
    {
        if(c[x][y]=='.' && c[x+1][y]=='.' && c[x+2][y]=='.' && c[x+1][y+1]=='.' && c[x+1][y+2]=='.')
            return 1;
    }
    if(co==2)
    {
        if(c[x][y+1]=='.' && c[x+1][y+1]=='.' && c[x+2][y+1]=='.' && c[x+2][y]=='.' && c[x+2][y+2]=='.')
            return 1;
    }
    if(co==3)
    {
        if(c[x+1][y]=='.' && c[x+1][y+1]=='.' && c[x+1][y+2]=='.' && c[x][y+2]=='.' && c[x+2][y+2]=='.')
            return 1;
    }

    return 0;
}

void doit(ll x, ll y, ll co, bool hmm)
{
    char x2 = xx+'A';
    if(hmm)
        x2 = '.';
    if(co==0)
    {
        c[x][y] = x2;
        c[x][y+1] = x2;
        c[x][y+2] = x2;
        c[x+1][y+1] = x2;
        c[x+2][y+1] = x2;
    }
    if(co==1)
    {
        c[x][y] = x2;
        c[x+1][y] = x2;
        c[x+2][y] = x2;
        c[x+1][y+1] = x2;
        c[x+1][y+2] = x2;
    }
    if(co==2)
    {
        c[x][y+1] = x2;
        c[x+1][y+1] = x2;
        c[x+2][y+1] = x2;
        c[x+2][y] = x2;
        c[x+2][y+2] = x2;
    }
    if(co==3)
    {
        c[x+1][y] = x2;
        c[x+1][y+1] = x2;
        c[x+1][y+2] = x2;
        c[x][y+2] = x2;
        c[x+2][y+2] = x2;
    }
}

void recur(ll x, ll y)
{
    if((ll)(rem/5) + xx<=ans)
        return;
    if(x==n && y==0)
    {
        if(xx>ans)
        {
            rep(i,n)
            {
                rep(j,m)
                {
                    an[i][j] = c[i][j];
                }
            }
            ans = xx;
        }
        return;
    }

    ll nx = x;
    ll ny = y+1;
    if(ny==m)
    {
        ny = 0;
        nx++;
    }

    bool hu = 0;
    if(c[x][y]=='.')
        hu = 1;
    rem -= hu;
    recur(nx,ny);
    rem += hu;

    rep(k,4)
    {
        if(can(x,y,k))
        {
            doit(x,y,k,0);
            rem -= 5;
            xx++;
            bool hu2 = 0;
            if(c[x][y]=='.')
                hu2 = 1;
            rem-=hu2;
            recur(nx,ny);
            rem+=hu2;
            doit(x,y,k,1);
            xx--;
            rem += 5;
        }
    }
}

void solve()
{
    cin >> n >> m;
    rep(i,n)
    {
        rep(j,m)
        {
            c[i][j] = '.';
            an[i][j] = '.';
        }
    }

    rem = n*m;
    recur(0,0);
    cout << ans << endl;
    rep(i,n)
    {
        rep(j,m)
        {
            cout << an[i][j];
        }
        cout << endl;
    }
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