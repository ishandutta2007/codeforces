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
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }


ll dp[1005][2005];
ll ch[1005][2005];
string st="";

void find(ll x,ll y)
{
    if(x<=0)
    {
        return;
    }
    ll z=ch[x][y];
    char ch='D';
    if(z==y+1)
    {
        ch='L';
    }
    else if(z==y-1)
    {
        ch='W';
    }
    find(x-1,z);
    st+=ch;
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(n==1&&k==1)
    {
        if(s[0]=='W'||s[0]=='?')
        {
            cout<<'W'<<endl;
        }
        else
        {
            cout<<"NO";
        }
        return;
    }
    if(k>n)
    {
        cout<<"NO"<<endl;
        return;
    }
    dp[0][1000]=1;
    for(int i=1;i<n;i++)
    {
        if(s[i-1]=='?')
        {
            for(int j=1000-k+1;j<1000+k;j++)
            {
                if(dp[i-1][j])
                {
                    if(j+1!=1000+k)
                    {
                        // trace(i,j+1);
                        dp[i][j+1]=1;
                        ch[i][j+1]=j;
                    }
                    dp[i][j]=1;
                    ch[i][j]=j;
                    // trace(i,j);
                }
                if(dp[i-1][j+1])
                {
                    dp[i][j]=1;
                    ch[i][j]=j+1;
                }
            }
        }
        else
        {
            ll x=0;
            if(s[i-1]=='W')
            {
                x++;
            }
            else if(s[i-1]=='L')
                x--;
            // trace(x);
            for(ll j=1000-k+1;j<1000+k;j++)
            {
                if(abs(j+x-1000)!=k&&dp[i-1][j])
                {
                    // trace(i,j+x);
                    dp[i][j+x]=1;
                    ch[i][j+x]=j;
                }
            }
        }
    }
    if(s[n-1]=='?')
    {
        if(dp[n-1][1000+k-1]==1)
        {
            dp[n][1000+k]=1;
            ch[n][1000+k]=1000+k-1;
        }
        else if(dp[n-1][1000-k+1]==1)
        {
            dp[n][1000-k]=1;
            ch[n][1000-k]=1000-k+1;
        }
    }
    else
    {
        if(s[n-1]=='W'&&dp[n-1][1000+k-1])
        {
            dp[n][1000+k]=1;
            ch[n][1000+k]=1000+k-1;
        }
        else if(s[n-1]=='L'&&(dp[n-1][1000-k+1]==1))
        {
            dp[n][1000-k]=1;
            ch[n][1000-k]=1000-k+1;
        }
    }
    if(dp[n][1000+k])
    {
        find(n,1000+k);
        cout<<st<<endl;
    }
    else if(dp[n][1000-k])
    {
        find(n,1000-k);
        cout<<st<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
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
        solve();
    }
    end_routine();
}