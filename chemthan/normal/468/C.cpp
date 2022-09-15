#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

unsigned long long mod_mul(unsigned long long a, unsigned long long b, unsigned long long p) {
    if (b == 0) return 0;
	if (b == 1) return a % p;
	unsigned long long x = mod_mul(a, b >> 1, p);
	if ((b & 1) == 0) return (x << 1) % p;
	else return (((x << 1) % p) + a) % p;
}

ll a;

ll ex(ll n, ll k) {
    if (k == 0) return 1;
    ll res = n, tmp = n;
    k--;
    while (k > 0) {
        if (k & 1) res = mod_mul(res, tmp, a);
        tmp = mod_mul(tmp, tmp, a);
        k >>= 1;
    }
    return res;
}

void solve() {
    cin>>a; int n = 30;
    if (a == 1) {
        cout<<1<<" "<<2; return;
    }
    ll ans = mod_mul(45, mod_mul(n - 1, ex(10, n - 2), a), a) + 1;
    ans = a - (ans % a);
    if (ans == 0) ans = a;
    cout<<ans + 1<<" "<<1;
    int cnt = 0; ll tmp = ans;
    while (tmp) {
        cnt++; tmp /= 10;
    }
    FOR(i, 0, n - cnt - 1) cout<<0;
    cout<<ans;
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}