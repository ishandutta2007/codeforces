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
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>  ordered_set;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 1000000000000000000ll
#define MOD 998244353 
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
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }



ll dp[5005];
ll ch[5005];
void solve()
{
    ll sum=0;
    ll n,k,req;
    cin>>n>>k>>req;
    vector<ll>v;
    dp[0]=1;
    ll sx=0;
    rep(i,n)
    {
        ll x;
        cin>>x;
        v.pb(x);
        sum+=x-(x%k);
        x=x%k;
        sx+=x;
        vector<ll>xx;
        for(ll j=0;j<k;j++)
        {
            if(dp[j]&&(j+x)%k!=0&&dp[(j+x)%k]==0)
            {
                // trace((j+x)%k,j,i);
                xx.pb((j+x)%k);
                ch[(j+x)%k]=i;
            }
        }
        for(auto z:xx)
        {
            dp[z]=1;
        }
    }
    ll z=req%k;
    sum+=(sx-z)-(sx-z)%k;
    if(dp[z]==0||sum+z<req)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        if(z==0)
        {
            for(int i=1;i<n;i++)
            {
                if((v[i]+k-1)/k==0)
                    continue;
                cout<<(v[i]+k-1)/k<<" "<<i+1<<" 1"<<endl;
            }
            ll t=req/k;
            if(t!=0)
                cout<<t<<" 1 "<<2<<endl;
        }
        else
        {
            vector<ll>vx;
            ll last=0;
            ll cur=z;
            // ll btx=5;
            while(cur!=0)
            {
                vx.pb(ch[cur]);
                // trace(ch[cur]);
                ll bt=v[ch[cur]]%k;
                // trace(cur,ch[cur]);
                cur=(cur-bt+k)%k;
                // cout<<"rem";
                // trace(cur);
            }
            set<ll>s;
            for(auto zx:vx)
            {
                s.insert(zx);
            }
            for(ll i=1;i<vx.size();i++)
            {
                ll x=vx[i];
                x=v[x];
                if((x+k-1)/k==0)
                    continue;
                cout<<(x+k-1)/k<<" "<<vx[i]+1<<" "<<vx[0]+1<<endl;
                v[vx[0]]+=x;
                v[vx[i]]=0;
            }
            ll xx=req-v[vx[0]];
            if(xx<0)
            {
                ll xz=(-xx)/k;
                ll tx=(vx[0]+2);
                if(tx>n)
                {
                    tx=1;
                }
                cout<<xz<<' '<<vx[0]+1<<' '<<tx<<endl;
            }
            else if(xx>0)
            {
                ll last=0;
                for(int i=0;i<n;i++)
                {
                    if(s.find(i)==s.end())
                    {
                        last=i;
                    }
                }
                for(int i=0;i<n;i++)
                {
                    if(s.find(i)==s.end()&&i!=last)
                    {
                        ll xz=v[i];
                        if(xz!=0)
                        {
                            cout<<(xz+k-1)/k<<' '<<i+1<<' '<<last+1<<endl;
                        }
                    }
                }
                // trace(last);
                cout<<xx/k<<' '<<last+1<<' '<<vx[0]+1<<endl;
            }
        }
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
    int tx=1;
    // cin>>tx;
    fr(i,1,tx)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}