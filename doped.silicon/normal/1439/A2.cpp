// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef bhartiya
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
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 1000000000000000000ll
// #define MOD 2000000000000000000ll
#define MOD 1000000007
#define EPS 1e-7
// #define PI 3.1415926535897932385
// #define PI acos(-1)

#define pb emplace_back
#define bitc __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define len(x) (int)x.length()
#define sz(x) (int)x.size();

#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it, ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs

#ifdef bhartiya
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
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }








ll mat[105][105];

void solve()
{   
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            mat[i][j]=s[j-1]-'0';
            // trace(mat[i][j]);
        }
    }
    vector<vector<ll>>ans;
    for(int j=1;j<=m-2;j++)
    {
        for(int i=1;i+1<=n;i+=2)
        {
            if(mat[i][j]+mat[i+1][j]==0)
            {
                continue;
            }
            vector<ll>v;
            ll cnt=3;
            rep(k,2)
            {
                if(mat[i+k][j])
                {
                    cnt--;
                    mat[i+k][j]^=1;
                    v.pb(i+k);
                    v.pb(j);
                }
            }
            rep(k,2)
            {
                if(cnt)
                {
                    cnt--;
                    mat[i+k][j+1]^=1;
                    v.pb(i+k);
                    v.pb(j+1);
                }
            }
            ans.pb(v);
        }
        if(n%2&&mat[n][j])
        {
            vector<ll>v;
            mat[n][j]^=1;
            mat[n-1][j+1]^=1;
            mat[n][j+1]^=1;
            v.pb(n);
            v.pb(j);
            v.pb(n);
            v.pb(j+1);
            v.pb(n-1);
            v.pb(j+1);
            ans.pb(v);
        }
    }
    // rep(i,n)
    // {
    //     rep(j,n)
    //     {
    //         trace(mat[i+1][j+1]);
    //     }
    // }
    // trace(ans.size());
    for(int i=1;i<=n-2;i++)
    {
        if(mat[i][m]+mat[i][m-1]==0)
        {
            continue;
        }
        vector<ll>v;
        ll cnt=3;
        rep(k,2)
        {
            if(mat[i][m-1+k])
            {
                mat[i][m-1+k]^=1;
                cnt--;
                v.pb(i);
                v.pb(m-1+k);
            }
        }
        rep(k,2)
        {
            if(cnt)
            {
                mat[i+1][m-1+k]^=1;
                cnt--;
                v.pb(i+1);
                v.pb(m-1+k);
            }
        }
        ans.pb(v);
    }
    while(true)
    {
        ll c=0;
        vector<ll>v;
        rep(i,2)
        {
            rep(j,2)
            {
                if(mat[n-i][m-j])
                {
                    c++;
                }
            }
        }
        // trace(c);
        if(c==0)
        {
            break;
        }
        else if(c==3)
        {
            rep(i,2)
            {
                rep(j,2)
                {
                    if(mat[n-i][m-j])
                    {
                        v.pb(n-i);
                        v.pb(m-j);
                        mat[n-i][m-j]^=1;
                    }
                }
            }
                    ans.pb(v);
            break;
        }
        else
        {
            ll c0=2;
            ll c1=1;
            if(c==4)
            {
                c1=3;
                c0=0;
            }
            rep(i,2)
            {
                rep(j,2)
                {
                    if(mat[n-i][m-j])
                    {
                        if(!c1)
                        {
                            continue;
                        }
                        c1--;
                        v.pb(n-i);
                        v.pb(m-j);
                        // trace("1",n-i,m-j);
                        mat[n-i][m-j]^=1;
                    }
                    else
                    {
                        if(!c0)
                        {
                            continue;
                        }
                        c0--;
                        // trace("0",n-i,m-j);
                        v.pb(n-i);
                        v.pb(m-j);
                        mat[n-i][m-j]^=1;
                    }
                }
            }
            // rep(i,)
            // trace(c1,c0);

                    ans.pb(v);
        }
    }
    cout<<ans.size()<<endl;
    for(auto z:ans)
    {
        for(auto x:z)
        {
            cout<<x<<' ';
        }
        cout<<endl;
    }
    rep(i,n)
    {
        rep(j,m)
        {
            if(mat[i+1][j+1])
            {
                assert(false);
            }
        }
    }
    // if(ans.size()>n*m)
    // {
    //     while(true)
    //     {
    //         n++;
    //     }
    // }

}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
#ifdef bhartiya
    cin.exceptions(cin.failbit);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    fr(i,1,t)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}