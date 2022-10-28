// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef ritick
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#define int long long
typedef long long ll;
typedef long double ld;
typedef long double f80;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 100000000000000000
#define inf 1000000000
#define EPS 1e-9
#define MOD  1000000007

// #define PI 3.1415926535897932384626

#define PI acos(-1)

#define pb emplace_back
#define bitc __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define len(x) (int)x.length()

#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it, ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs

#ifdef ritick
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";__p(arg1);cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(; ;i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    const char *comma=names+i;
    cout.write(names,comma-names)<<" : ";
    __p(arg1);
    cout<<"| ";
    __f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<int>(l, r)(rng32)
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }


ld modp(ld b, ll e) {
    ld ans=1; for(;e;b=b*b,e/=2) if(e&1) ans=ans*b; return ans; }


ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }


ll p[100005];
// map<ll,ll>m;
void solve()
{
    ll n;
    cin>>n;  
    // m.clear(); 
    vector<ll>v;
    vector<ll>vx;
    v.pb(n);
    set<ll>s;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v.pb(i);
            if(p[i]==i)
            {
                vx.pb(i);
            }
            if((n/i)!=i)
            {
                v.pb(n/i);
            }
        }
    }
    ll x1=n;
    for(auto z:vx)
    {
        while(x1%z==0)
        {
            x1/=z;
        }
    }
    if(x1>1)
    {
        vx.pb(x1);
    }
    // trace(vx);
    if(vx.size()==2&&v.size()==3)
    {
        for(auto z:v)
        {
            cout<<z<<' ';
        }
        cout<<endl;
        cout<<(1)<<endl;
    }
    else
    {
        for(auto z:v)
        {
            s.insert(z);
        }
        s.erase(n);
        
        // trace(vx);
        ll lx=0;
        rep(i,vx.size()-1)
        {
            
                s.erase(vx[i]*vx[i+1]);
                lx=vx[i+1];
        }
        if(vx.size()>2)
        {
            s.erase(lx*vx[0]);
        }
        ll last=-1;
        for(auto z:vx)
        {
            if(last!=-1)
            {
                cout<<last*z<<' ';
            }
            last=z;
            vector<ll>rem;
            for(auto xx:s)
            {
                if(xx%z==0)
                {
                    rem.pb(xx);
                    cout<<xx<<' ';
                }
            }
            for(auto xx:rem)
            {
                s.erase(xx);
            }
        }
        cout<<n <<' ';
        if(vx.size()>2)
            cout<<last*vx[0]<<endl;
        else
            cout<<endl;
        cout<<"0"<<endl;
    }


}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(20);   cout<<fixed;
    #ifdef ritick
        cin.exceptions(cin.failbit);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    cin>>t;
    for(ll i=2;i<=100000;i++)
    {
        if(p[i]==0)
        {
            for(ll j=i;j<=100000;j+=i)
            {
                p[j]=i;
            }
        }
    }
    fr(i,1,t)
    {   
        // cout<<"Case "<<i<<": "<<endl;
        solve();
    }
    end_routine();
}