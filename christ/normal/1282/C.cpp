#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
char _;
bool neg;
int _p;
char _b[50];
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#ifdef getchar_unlocked
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
#define max(...) maxx(__VA_ARGS__)
#define min(...) minn(__VA_ARGS__)
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
void scan (char *x) {for(_p=0;(_=getchar())!=' '&&_!=10;x[_p++]=_);}
template <typename t> void scan (t& x) {while((x=getchar())<'0') neg=x=='-'; for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); if(neg)x=-x;}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
template <typename t> t maxx (const t &a, const t &b) {return a > b ? a : b;}
template <typename t, typename ...r> t maxx (const t &a, const r &...b) {return maxx(a,maxx(b...));}
template <typename t> t minn (const t &a, const t &b) {return a < b ? a : b;}
template <typename t, typename ...r> t minn (const t &a, const r &...b) {return minn(a,minn(b...));}
template <typename t> void uin (t &a, const t &b) {a = minn(a,b);}
template <typename t, typename ...r> void uin (t &a, const r &...b) {a = minn(a,b...);}
template <typename t> void uax (t &a, const t &b) {a = maxx(a,b);}
template <typename t, typename ...r> void uax (t &a, const r &...b) {a = maxx(a,b...);}
void print (char *x) {for(_p=0;x[_p];putchar(x[_p++]));}
template <typename t> void print (t a) {if(a==0){putchar('0');return;}if(a<0)putchar('-'), a=-a;for(_b[_p=0]='0'+a%10;a/10;_b[++_p]='0'+(a/=10)%10);for (;~_p;putchar(_b[_p--]));}
template <typename t, typename ...r> void print (t &a, r &...b) {print(a);putchar(' ');print(b...);}
template <typename t, typename ...r> void println (t &a, r& ...b) {print(a,b...);putchar(10);}
void printlns (){}
template <typename t, typename ...r> void printlns (t &a, r &...b) {print(a); putchar(10); printlns(b...);}
const int MN = 2e3+2, MOD = 1e9+7, BASE = 131;
int fpow (int base, int ex) {int res = 1;while (ex) {if (ex&1) res = res*1LL*base%MOD;base = base*1LL*base%MOD;ex>>=1;}return res;}
ll lcm (ll a, ll b) {return a*b/__gcd(a,b);}
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int rand (int a, int b) {return uniform_int_distribution<int>(a,b)(rnd);}
ll randll (ll a, ll b) {return uniform_int_distribution<ll>(a,b)(rnd);}
int moddiv (int a, int b) {return a*1LL*fpow(b,MOD-2)%MOD;}
#define int long long
int k,p,n;
int32_t main () {
    int tests;
    scanf ("%lld",&tests);
    while (tests--) {
      int n,t,ac,b;
      scanf ("%lld %lld %lld %lld",&n,&t,&ac,&b);
      vector<pll> a(n+1);
      int cnteasy = 0;
      for (int i = 1; i <= n; i++) {scanf ("%lld",&a[i].second);if(!a[i].second)++cnteasy;}
      for (int i = 1; i <= n; i++) scanf ("%lld",&a[i].first);
      sort(a.begin()+1,a.end());
      //you only want to leave right before a problem becomes mandatory
      //for each a[i], find the earliest time s/t all mandatory problems before a[i] are finished, the answer for a[i] is the answer for a[i-1] + amount of time it takes to solve problem i
      vector<ll> dp(n+1);
      dp[0] = 0; 
      int easys = max(0LL,min(cnteasy,(a[1].first-1)/ac));
      int easytime = easys*ac;
      int hards = max(0LL,min(n-cnteasy,(a[1].first-1-easytime)/b));
      int ans = easys + hards;
      for (int i = 1; i <= n; i++) {
        cnteasy -= a[i].second == 0;
        dp[i] = dp[i-1] + (a[i].second == 1 ? b : ac);
        if ((i == n && dp[i] <= t) || (i != n && dp[i] < a[i+1].first)) {
          int ret = i;
          int nxt = i == n ? t+1 : a[i+1].first;
          int easys = max(0LL,min(cnteasy,(nxt-1-dp[i])/ac));
          int easytime = easys*ac;
          ret += easys;
          int hards = max(0LL,min(n-i-cnteasy,(nxt-1-dp[i]-easytime)/b));
          ret += hards;
          ans = max(ans,ret);
        }
      }
      printf ("%lld\n",ans);
    }
    return 0;
}