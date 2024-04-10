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
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 1000000000000000000ll
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
// #define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }


set<ll>s;
ll l[250005];
map<ll,pair<ll,ll>>ma;
vector<ll>v[250005];
vector<ll>pos[250005];
void solve()
{   
    ll n,m;
    cin>>n>>m;
    rep(i,n)
    {
        rep(j,m)
        {
            ll x;
            cin>>x;
            v[i].pb(x);
        }
        l[i]=2;
    }
    rep(i,n-1)
    {
        vector<ll>vx;
        rep(j,m)
        {
            if(v[i][j]!=v[i+1][j])
            {
                vx.pb(j);
            }
        }
        for(auto z:vx)
        {
            if(s.size()==4)
            {
                break;
            }
            s.insert(z);
            ma[z]=mp(i,i+1);
            if(s.size()==4)
            {
                break;
            }
        }
        if(vx.size()>4)
        {
            cout<<"No"<<endl;
            return;
        }
    }
    vector<ll>vx;
    for(auto z:s)
    {
        vx.pb(ma[z].ff);
        vx.pb(ma[z].ss);
    }
    if(s.size()==0)
    {
        cout<<"Yes"<<endl;
        for(auto z:v[0])
        {
            cout<<z<<' ';
        }
        return;
    }
    ll a=-1,b=-1;
    ll zz=0;
    s.clear();
    // trace(vx);
    for(auto x:vx)
    {
        for(auto y:vx)
        {
            ll cnt=0;
            rep(i,m)
            {
                if(v[x][i]!=v[y][i])
                {
                    cnt++;
                }
            }
            if(cnt>4)
            {
                cout<<"No"<<endl;
                return;
            }
            if(cnt>zz)
            {
                zz=cnt;
                a=x;
                b=y;
            }
        }
    }
    rep(j,m)
    {
        if(v[a][j]!=v[b][j])
        {
            s.insert(j);
        }
    }
    // trace(a,b);
    rep(i,m)
    {
        if(s.find(i)==s.end())
        {
            rep(j,n)
            {
                if(v[j][i]!=v[a][i])
                {
                    l[j]--;
                }
                if(l[j]<0)
                {
                    trace(j);
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
    }
    vx.clear();
    for(auto z:s)
    {
        vx.pb(z);
    }
    ll ans=0;
    ll mask=0;
    rep(i,(1<<vx.size()))
    {
        ll flag=1;
        rep(k,n)
        {
            ll cnt=0;
            rep(j,vx.size())
            {
                ll cmp=v[a][vx[j]];
                if((1<<j)&i)
                {
                    cmp=v[b][vx[j]];
                }
                if(v[k][vx[j]]!=cmp)
                {
                    cnt++;
                }
            }
            if(l[k]-cnt<0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            ans=1;
            mask=i;
            break;
        }
    }
    vector<ll>an;
    if(ans)
    {
        cout<<"Yes"<<endl;
        for(auto z:v[a])
        {
            an.pb(z);
        }
        rep(i,vx.size())
        {
            if(mask&(1<<i))
            {
                an[vx[i]]=v[b][vx[i]];
            }
            else
            {

                an[vx[i]]=v[a][vx[i]];
            }
        }
        for(auto z:an)
        {
            cout<<z<<' ';
        }
    }
    else
    {
        cout<<"No"<<endl;
        return;
    }

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
    // cin>>t;
    fr(i,1,t)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}