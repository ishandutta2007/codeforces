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
 
#define INF 200000000
// #define MOD 1000000009
#define eps 1e-7
#define PI 3.1415926535897932385
// #define PI acos(-1)
 
#define pb push_back
#define bitc  __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define sz(x) (int)(x).size()
 
#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = n - 1; i >= 0; i--)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it,ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar,val) memset(ar, val, sizeof(ar))
 
#ifdef rg
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
#define MOD 1000000007

ll modexp(ll b, ll e) {
    ll ans=1; for(;e;b=b*b%MOD,e/=2) if(e&1) ans=ans*b%MOD; return ans;}


void solve()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll l0=0,r0=0,l1=0,r1=0;
    ll i=0;
    vector<ll>v1,v0;
    rep(i1,n)
    {
        if(s[i1]=='0')
        {
            v0.pb(i1);
        }
        else
        {
            v1.pb(i1);
        }
    }
    while(i<n&&s[i]=='0')
    {
        l0++;
        i++;
    }
    i=0;
    while(i<n&&s[i]=='1')
    {
        l1++;
        i++;
    }
    i=n-1;
    while(i>=0&&s[i]=='0')
    {
        r0++;
        i--;
    }
    i=n-1;
    while(i>=0&&s[i]=='1')
    {
        r1++;
        i--;
    }
    // cout<<v0.size()<<endl;
    // cout<<v0[2]<<endl;
    // cout<<v0[v0.size()-1]-v0[0]-1<<endl;
    if(n-l0-r0<=k||n-r1-l1<=k)
    {
        cout<<"tokitsukaze"<<endl;
    }
    else if(v0[v0.size()-1]-v0[0]-1>=k||v1[v1.size()-1]-v1[0]-1>=k||n-max(l0,k)-r0>k||n-max(r0,k)-l0>k||n-max(r1,k)-l1>k||n-max(l1,k)-r1>k)
    {
        cout<<"once again"<<endl;
    }
    else
    {
        cout<<"quailty"<<endl;
    }

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