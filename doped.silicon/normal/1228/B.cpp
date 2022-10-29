#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#ifndef bhartiya
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    // #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
 
#define int long long 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
// not that imp
typedef pair<pii, int> piii;

typedef vector<int> vi;
typedef vector<pii> vii;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

#define INF 1000000000
#define MOD 1000000007
#define mod 1000000007
#define EPS 1e-7
#define PI 3.1415926535897932385
// #define PI acos(-1)
#define ff first
#define ss second
 
#define pb push_back
#define bitc  __builtin_popcountll
#define mp make_pair
#define all(ar) ar.begin(), ar.end()
#define sz(x) (int)(x).size()
 
#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = n - 1; i >= 0; i--)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it,ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar,val) memset(ar, val, sizeof(ar))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

 
#ifdef bhartiya
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
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif
 
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) {return fabs(a - b) < 1e-9;}
int gcd(int a, int b){ return b==0 ? a : gcd(b, a%b); }
ll modpow(ll b, ll e) {
    ll ans=1; for(;e;b=b*b%MOD,e/=2) if(e&1) ans=ans*b%MOD; return ans;}
ll mat[1005][1005];
void solve()
{
    ll h,w;
    cin>>h>>w;
    rep(i,h)
    {
        rep(j,w)
        {
            mat[i][j]=-1;
        }
    }
    rep(i,h)
    {
        ll x;
        cin>>x;
        rep(j,x)
        {
            mat[i][j]=1;
        }
        mat[i][x]=0;
    }
    // rep(i,h)
    // {
    //     rep(j,w)
    //     {
    //         cout<<mat[i][j];
    //     }
    //     cout<<endl;
    // }
    rep(i,w)
    {
        ll x;
        cin>>x;
        // cout<<x<<endl;
        rep(j,x)
        {
            if(mat[j][i]==0)
            {
                cout<<"0";
                return;
            }
            mat[j][i]=1;
        }
        if(mat[x][i]==1)
        {
            cout<<"0";
            return;
        }
        mat[x][i]=0;
        // cout<<mat[0][0]<<endl;
    }
    ll cnt=0;
    rep(i,h)
    {
        rep(j,w)
        {
            // cout<<mat[i][j];
            if(mat[i][j]==-1)
                cnt++;
        }
    }
    cout<<modpow(2,cnt)<<endl;
}

signed main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(10); //cout<<fixed;
    cin.exceptions(cin.failbit);
    #ifdef rg
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    end_routine();
}