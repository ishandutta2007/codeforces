#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
char _;
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#ifdef _getchar_nolock
#define getchar _getchar_nolock
#endif
#ifdef _putchar_nolock
#define putchar _putchar_nolock
#endif
#ifdef getchar_unlocked
#define getchar getchar_unlocked
#endif
#ifdef putchar_unlocked
#define putchar putchar_unlocked
#endif
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
void scan(pii &x) {scan(x.first); scan(x.second);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 2e5+2, MM = 1e6+2, MOD = 1e8, BASE = 131;
int fpow (int base, int ex) {int res = 1;while (ex) {if (ex&1) res = res*1LL*base%MOD;base = base*1LL*base%MOD;ex>>=1;}return res;}
ll lcm (ll a, ll b) {return a*b/__gcd(a,b);}
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int rand (int a, int b) {return uniform_int_distribution<int>(a,b)(rnd);}
ll randll (ll a, ll b) {return uniform_int_distribution<ll>(a,b)(rnd);}
int moddiv (int a, int b) {return a*1LL*fpow(b,MOD-2)%MOD;}
int p[MN], sz[MN];
bool vis[MN];
int find (int n) {return p[n] == n ? n : p[n] = find(p[n]);}
void merge (int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa == fb) return;
    if (sz[fa] > sz[fb]) swap(fa,fb);
    p[fa] = fb;
    sz[fb] += sz[fa];
}
int main () {
    int n,m,a,b, ans = 0;
    scan(n,m);
    for (int i = 1; i <= n; i++) {
        p[i]=i;
        sz[i]=1;
    }
    for (int i = 1; i <= m; i++) {
        scan(a, b);
        merge(a, b);
    }
    for (int i = 1; i <= n; i++) {
        int cur = find(i);
        if (!vis[cur]) {
            vis[cur] = 1;
            ans += sz[cur]-1;
        }
    }
    printf ("%d\n",m-ans);
    return 0;
}