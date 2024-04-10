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
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 100000000000ll
#define MOD 1000000007
#define EPS 1e-7
#define PI 3.1415926535897932385
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

vector<pair<ll,ll>>add[2000005];
vector<pair<ll,ll>>del[2000005];
ll dsu[100005];
ll n,m,q;
ll diff[2000005];
ll mat[305][305];
ll dx[]={0,-1,0,1};
ll dy[]={1,0,-1,0};
bool in(ll x,ll y)
{
    return x>=0&&y>=0&&x<n&&y<m;
}
int fpar(int i) 
{
    return (dsu[i]<0)?i:dsu[i]=fpar(dsu[i]);
}
ll merge(int i, int j) 
{
    if((i=fpar(i))!=(j=fpar(j))) 
    {
        if(dsu[i]>dsu[j])
            swap(i,j);
        dsu[i]+=dsu[j];
        dsu[j]=i;
        return 1;
    }
    return 0;
}
void ad(const vector<pair<ll,ll>>&v,ll f)
{
    rep(i,n)
    {
        rep(j,m)
        {
            dsu[i*m+j]=-1;
            mat[i][j]=0;
        }
    }
    for(auto z:v)
    {
        ll cur=1;
        ll x=z.ff/m;
        ll y=z.ff%m;
        mat[x][y]=1;
        rep(j,4)
        {
            ll nx=x+dx[j];
            ll ny=y+dy[j];
            if(in(nx,ny)&&mat[nx][ny])
            {
                cur-=merge(x*m+y,nx*m+ny);
            }
        }
        diff[z.ss]+=cur*f;
    }

}
void solve() 
{
    cin>>n>>m>>q;
    ll cl=0;
    rep(i,q)
    {
        ll x,y,c;
        cin>>x>>y>>c;x--;y--;
        if(mat[x][y]==c)
            continue;
        cl=c+1;
        add[c].pb(mp(x*m+y,i));
        del[mat[x][y]].pb(mp(x*m+y,i));
        mat[x][y]=c;
    }
    rep(i,n)
    {
        rep(j,m)
        {
            del[mat[i][j]].pb(mp(i*m+j,q));
        }
    }
    rep(i,cl)
    {
        ad(add[i],1);
        // for(auto x:add[i])
        // {
        //     trace(x);
        // }
        // cout<<endl;
        reverse(all(del[i]));
        ad(del[i],-1);
    }
    ll ans=1;
    rep(i,q)
    {
        ans+=diff[i];
        cout<<ans<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   //cout<<fixed;
#ifdef bhartiya
    cin.exceptions(cin.failbit);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    fr(i,1,t)
    {
        solve();
    }
    end_routine();
}