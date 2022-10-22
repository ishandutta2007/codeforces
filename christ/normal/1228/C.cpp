#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
char _;
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#ifdef getchar_unlocked
#define getchar getchar_unlocked
    #define putchar putchar_unlocked
#endif
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define lc ind<<1
#define rc ind<<1|1
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 1e5+2, MM = 3e3+2, MOD = 1e9+7, BASE = 131;
ll fpow (ll base, ll ex) {ll res = 1;while (ex) {if (ex&1) res = res*1LL*base%MOD;base = base*1LL*base%MOD;ex>>=1;}return res;}
ll lcm (ll a, ll b) {return a*b/__gcd(a,b);}
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int rand (int a, int b) {return uniform_int_distribution<int>(a,b)(rnd);}
ll randll (ll a, ll b) {return uniform_int_distribution<ll>(a,b)(rnd);}
int moddiv (int a, int b) {return a*1LL*fpow(b,MOD-2)%MOD;}
inline int max (int a, int b) {return a > b ? a : b;}
int freq[MN];
int main () {
    int x; ll n; ll ans = 1;
    scan(x,n);
    for (int i = 2; i * i <= x; i++) {
        while (x%i==0) {
            ++freq[i];
            x/=i;
        }
    }
    if (x>1) {
        ll mult = x;
        ll pow = 0;
        while (mult <= n && mult > 0) {
            ll owo = n/mult;
            ans = (ans*fpow(x,owo))%MOD;
            if (mult > 2000000000000000000LL/x) break;
            mult *= x;
        }
    }
    for (int i = 2; i < MN; i++) if (freq[i]){
        ll mult = i;
        ll pow = 0;
        while (mult <= n && mult > 0) {
            ll owo = n/mult;
            ans = (ans*fpow(i,owo))%MOD;
            if (mult > 2000000000000000000LL/i) break;
            mult *= i;
        }
    }
    printf ("%lld\n",ans);
    return 0;
}