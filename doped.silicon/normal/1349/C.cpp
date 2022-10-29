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

#define INF 1000000000000000005ll
#define MOD 163577857
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
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }

ll n,m,k;
bool mat[1005][1005];
int dis[1005][1005];
bool chk(ll x,ll y)
{
    return x>=0&&y>=0&&x<n&&y<m;
}
ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
void solve() 
{
    cin>>n>>m>>k;  
    rep(i,n)
    {
        string s;
        cin>>s;
        rep(j,m)
        {
            if(s[j]=='1')
                mat[i][j]=1;
            dis[i][j]=INF;
        }
    }
    queue<pair<pair<ll,ll>,ll>>q;
    rep(i,n)
    {
        rep(j,m)
        {
            rep(xx,4)
            {
                if(chk(i+dx[xx],j+dy[xx])&&mat[i][j]==mat[i+dx[xx]][j+dy[xx]])
                {
                    q.push(mp(mp(i,j),0));
                    dis[i][j]=0;
                    // trace(mat[i][j],mat[i+dx[xx]][j+dy[xx]]);
                    // trace(i,j,i+dx[xx],j+dy[xx],0);
                    // trace(i,j,0);
                    break;
                }
            }
        }
    }
    while(!q.empty())
    {
        auto z=q.front();
        q.pop();
        ll x=z.ff.ff;
        ll y=z.ff.ss;
        ll d=z.ss;
        rep(xx,4)
        {
            if(chk(x+dx[xx],y+dy[xx])&&dis[x+dx[xx]][y+dy[xx]]==INF)
            {

                q.push(mp(mp(x+dx[xx],y+dy[xx]),d+1));
                dis[x+dx[xx]][y+dy[xx]]=d+1;
                // trace(x+dx[xx],y+dy[xx],d+1);
            }
        }
    }
    rep(i,k)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        // trace(dis[x][y]);
        if(z<=dis[x][y])
        {
            cout<<mat[x][y]<<endl;
        }
        else
        {
            z=(z-dis[x][y])%2;
            cout<<(mat[x][y]^z)<<endl;
        }
    }

}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
#ifdef ritick
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