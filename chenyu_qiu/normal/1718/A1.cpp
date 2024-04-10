//HEADER FILES AND NAMESPACES
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>   
using namespace std;
using namespace __gnu_pbds;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
 
// DEFINE STATEMENTS
const long long inf = 1e18;
#define M 1000000007
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define repd(i,a,n) for(ll i=a; i>=n; i--)
#define repit(x) for(auto it=x.begin();it!=x.end();it++)
#define repitr(x) for(auto it=x.rbegin();it!=x.rend();it++)
#define size(x) (int)(x.size())
#define pb push_back
#define pob pop_back
#define mp make_pair
#define f first
#define s second
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define all(x) x.begin(), x.end()
#define M_PI 3.14159265358979323846
#define epsilon (double)(0.000000001)
#define popcount __builtin_popcountll
#define fileio(x,y) freopen(x, "r", stdin); freopen(y, "w", stdout);
#define lc(i) (i<<1)
#define rc(i) (lc(i)|1)
#define mid(x,y) (y-x)/2+x
#define ll1(p) ll p;cin>>p
#define ll2(p,q) ll p,q;cin>>p>>q
#define ll3(p,q,r) ll p,q,r;cin>>p>>q>>r
#define ll4(p,q,r,s) ll p,q,r,s;cin>>p>>q>>r>>s
#define ch1(p) char p;cin>>p
#define ch2(p,q) char p,q;cin>>p>>q
#define str1(p) string p;cin>>p
#define str2(p,q) string p,q;cin>>p>>q
 
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<int> vi;
 
// DEBUG FUNCTIONS 
#ifdef LOCALFLAG
template<typename T>
void __p(T a) { cout<<a; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout<<"{"; __p(a.first); cout<<","; __p(a.second); cout<<"}"; }
template<typename T>
void __p(std::vector<T> a) { cout<<"{"; for(auto it=a.begin(); it<a.end(); it++) __p(*it),cout<<",}"[it+1==a.end()]; }
template<typename T>
void __p(std::set<T> a) { cout<<"{"; for(auto it=a.begin(); it!=a.end();){ __p(*it); cout<<",}"[++it==a.end()]; } }
template<typename T>
void __p(std::multiset<T> a) { cout<<"{"; for(auto it=a.begin(); it!=a.end();) { __p(*it); cout<<",}"[++it==a.end()]; } }
template<typename T, typename F>
void __p(std::map<T,F> a) { cout<<"{\n"; for(auto it=a.begin(); it!=a.end();++it) { __p(it->first); cout << ": "; __p(it->second); cout<<"\n"; } cout << "}\n"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout<<name<<" : "; __p(arg1); cout<<endl; }
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) { int bracket=0,i=0; for(;; i++) if(names[i]==','&&bracket==0) break; else if(names[i]=='(') bracket++; else if(names[i]==')') bracket--; const char *comma=names+i; cout.write(names,comma-names)<<" : "; __p(arg1); cout<<" | "; __f(comma+1,args...); }
#define trace(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#define error(...)
#endif
// DEBUG FUNCTIONS END 
 
// CUSTOM HASH TO SPEED UP UNORDERED MAP AND TO AVOID FORCED CLASHES
struct custom_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };
void myerase(ordered_multiset<long long> &t, int v){
    int rank = t.order_of_key(v);
    ordered_multiset<long long>::iterator it = t.find_by_order(rank);
    t.erase(it);
}
void myerase(ordered_set<long long> &t, int v){
    int rank = t.order_of_key(v);
    ordered_set<long long>::iterator it = t.find_by_order(rank);
    t.erase(it);
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());  // FOR RANDOM NUMBER GENERATION
ll mod_exp(ll a, ll b, ll c) { ll res=1; a=a%c; while(b>0) { if(b%2==1) res=(res*a)%c; b/=2; a=(a*a)%c; } return res; }
ll mymod(ll a,ll b) { return ((a%b)+b)%b; }
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
ll gcdExtended(ll,ll,ll *,ll *);
ll modInverse(ll a, ll m) { 
        ll x, y; 
        ll g = gcdExtended(a, m, &x, &y); 
        g++;   //this line was added just to remove compiler warning
        ll res = (x%m + m) % m;
        return res;
} 
ll gcdExtended(ll a, ll b, ll *x, ll *y) { 
        if (a == 0) { *x = 0, *y = 1; return b; } 
        ll x1, y1; 
        ll gcd = gcdExtended(b%a, a, &x1, &y1);
        *x = y1 - (b/a) * x1; 
        *y = x1; 
        return gcd; 
}
 
 
 
// MOD careful
void solve() {
    ll1(n);
    vll v(n);
    rep(i,0,n) cin>>v[i];
    multiset<ll> s;
    s.insert(0);
    vll pre=v;
    rep(i,1,n) pre[i]^=pre[i-1];
    ll ans=n;
    rep(i,0,n) {
        // trace(s);
        if(s.find(pre[i])==s.end()) {
            s.insert(pre[i]);
        }
        else {
            s.clear();
            s.insert(pre[i]);
            ans--;
        }
    }
    cout<<ans<<"\n";
    // trace(dp);
}
// MOD careful
 
int main()
{
    #ifdef LOCALFLAG 
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
    //fileio(".in",".out")
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
 
 
 
   
    int t=1;
    cin>>t;
    while(t>0) {
        solve();
        t--;
    }
    return 0;
}