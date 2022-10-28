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
#define MOD 998244353
#define EPS 1e-7
// #define PI 3.1415926535897932385
// #define PI acos(-1)

#define pb push_back
#define mp make_pair

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



vector<ll>ans[14][14];
void find(ll n,ll y)
{
    if(ans[n][y].size())
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO";
        return;
    }
    cout<<0<<' ';
    for(int i=1;i<ans[n][y].size();i++)
    {
        cout<<ans[n][y][i]<<' ';
    }
}
ll cnt=0;
void find(ll fst,ll shift,ll n,ll y)
{
    // trace(n,y,fst);
    if(n<=13)
    {
        cout<<fst<<' ';
        cnt++;
        for(int i=1;i<ans[n][y].size();i++)
        {
            cnt++;
            cout<<shift+ans[n][y][i]<<' ';
        }
    }
    else
    {
        cout<<fst<<' ';
        cnt++;
        ll z=(n+1);
        if((z&(-z))==z)
        {
            if(y==0)
            {
                ll k=z/2-1;
                find(shift+1,shift+1,k,y);
                find(shift+1,shift+1+k,k,y);    
            }
            else
            {
                find(shift+1,shift+1,1,0);
                find(shift+1,shift+2,n-2,y-1);
            }
        }
        else
        {
            if(y==1)
            {
                z-=2;
                if((z&(-z))==z)
                {
                    find(shift+1,shift+1,1,0);
                    find(shift+1,shift+2,n-2,y-1);
                }
                else
                {
                    z-=2;
                    if((z&(-z))==z)
                    {
                        find(shift+1,shift+1,3,0);
                        find(shift+1,shift+4,n-4,y-1);
                    }
                    else
                    {
                        ll x=log2(n);
                        x=(1<<x)-1;
                        ll y=log2(x);
                        y=(1<<y)-1;
                        // swap(x,y);
                        // trace(x,y);
                        if(x+y>n)
                        {
                            find(shift+1,shift+1,y,0);
                            find(shift+1,shift+1+y,n-y-1,1);
                        }
                        else if(x+y==n-1)
                        {
                            find(shift+1,shift+1,y,0);
                            find(shift+1,shift+1+y,n-y-1,0);
                        }
                        else
                        {
                            find(shift+1,shift+1,x,0);
                            find(shift+1,shift+1+x,n-x-1,1);
                        }
                    }
                }
            }
            else
            {
                // trace(n,y,shift);
                ll xz=n-1;
                if((xz&-xz)==xz&&y==2)
                {
                    find(shift+1,shift+1,3,0);
                    find(shift+1,shift+4,n-4,y-1);
                }
                else
                {
                    find(shift+1,shift+1,1,0);
                    find(shift+1,shift+2,n-2,y-1);
                }
            }
        }
    }
}
void solve()
{   
    ans[1][0].pb(0);
    ans[3][0]={0,1,1};
    ans[5][1]={0,1,1,3,3};
    for(int i=7;i<=13;i+=2)
    {
        for(int j=1;j<=i-1;j+=2)
        {
            ll x=j;
            ll y=i-1-j;
            for(int k=0;k<=x;k++)
            {
                for(int k1=0;k1<=x;k1++)
                {
                    ll z=(x>=2*y)||(y>=2*x);
                    if(ans[x][k].size()&&ans[y][k1].size()&&ans[x+y+1][z+k+k1].size()==0)
                    {
                        ll a=x+y+1;
                        ll b=z+k+k1;
                        ans[a][b].pb(0);
                        ans[a][b].pb(1);
                        for(auto xx:ans[x][k])
                        {
                            if(xx==0)
                            {
                                continue;
                            }
                            ans[a][b].pb(xx+1);
                        }
                        ans[a][b].pb(1);
                        for(auto xx:ans[y][k1])
                        {
                            if(xx==0)
                            {
                                continue;
                            }
                            ans[a][b].pb(xx+1+x);
                        }
                    }
                }
            }
        }
    }
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    if(n<=13)
    {
        find(n,k);
        return;
    }

    ll han=1;
    if(n%2==0)
    {
        han=0;
    }
    if(k>=(n-1)/2)
    {
        han=0;
    }
    ll z=(n+1);
    if((z&(-z))==z&&k==1)
    {
        han=0;
    }
    if((z&(-z))!=z&&k==0)
    {
        han=0;
    }
    if(han)
    {
        cout<<"YES"<<endl;
        find(0,0,n,k);
    }
    else
    {
        cout<<"NO"<<endl;
    }
    trace(cnt);




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