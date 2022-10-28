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

// #define int long long
typedef int ll;
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
#define MOD  998244353
// #define EPS 1e-7
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
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }


ld modp(ld b, ll e) {
    ld ans=1; for(;e;b=b*b,e/=2) if(e&1) ans=ans*b; return ans; }


ll dsu[64*2*1024+10];
bool occ[64*2*1024+10];
vector<ll>v[2];
vector<bool>b[2];
int fpar(int i) 
{
    return (dsu[i]<0)?i:dsu[i]=fpar(dsu[i]);
}
ll ans=0;
void merge(int i, int j) 
{
    if((i=fpar(i))!=(j=fpar(j))) 
    {
        ans--;
        if(dsu[i]>dsu[j])
        {
            swap(i,j);
        }
        dsu[i]+=dsu[j];
        dsu[j]=i;
    }
}

ll find(char ch)
{
    if(ch>='A'&&ch<='F')
    {
        return 10+(ch-'A');
    }
    return ch-'0';
}

map<char,string>m;
string finds(char ch)
{
    if(m.find(ch)!=m.end())
    {
        return m[ch];
    }
    ll bt=find(ch);
    string s="";
    rep(i,4)
    {
        s=(char)('0'+bt%2)+s;
        bt/=2;
    }
    return m[ch]=s;
}
ll kx=0;
ll find()
{
    while(true)
    {
        if(occ[kx]==0)
        {
            occ[kx]=1;
            return kx;
        }
        kx++;
    }
}
void solve()
{
    rep(i,32*1024+10)
    {
        dsu[i]=-1;
    }
    ll n,m;
    cin>>n>>m;
    m/=4;
    ll c=0;
    b[0].pb(0);
    v[0].pb(find());
    rep(i,m)
    {
        char ch;
        cin>>ch;
        string st=finds(ch);
        rep(j,4)
        {
            v[0].pb(find());
            if(st[j]=='1'&&b[0][c]==1)
            {
                merge(v[0][c+1],v[0][c]);
            }
            b[0].pb((st[j]-'0'));
            ans+=st[j]-'0';
            c++;
        }
    }
    rep(i,n-1)
    {
        b[1].pb(0);
        kx=0;
        v[1].pb(find());
        c=0;
        rep(j,m)
        {
            char ch;
            cin>>ch;
            string st=finds(ch);
            rep(k,4)
            {
                v[1].pb(find());
                if(st[k]=='1'&&b[1][c]==1)
                {
                    v[1][c+1]=v[1][c];
                    ans--;
                }
                if(st[k]=='1'&&b[0][c+1]==1)
                {
                    merge(v[1][c+1],v[0][c+1]);
                }
                b[1].pb((st[k]-'0'));
                ans+=st[k]-'0';
                c++;
            }
        }
        rep(i1,32*1024+10)
        {
            occ[i1]=0;
        }
        for(ll j=1;j<=4*m;j++)
        {
            occ[fpar(v[1][j])]=1;
            v[1][j]=fpar(v[1][j]);
            
        }
        rep(i1,32*1024+10)
        {
            if(occ[i1]==0)
                dsu[i1]=-1;
        }
        v[0].clear();
        b[0].clear();
        swap(b[0],b[1]);
        swap(v[0],v[1]);

    }
    cout<<ans<<endl;



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
        // cout<<"Case "<<i<<": "<<endl;
        solve();
    }
    end_routine();
}