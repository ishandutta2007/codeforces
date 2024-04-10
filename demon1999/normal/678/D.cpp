#include <bits/stdc++.h> 

using namespace std; 
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define gi get_int()
typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll cnn = 800, md = 1000000007, sz_g = 200000, pq = 100000000, inf = 1000000000LL,
 mod2 = 5000000, ma = 128 * 1024, ma1 = 8;

void my_assert() {
	while(true);
}
ll get_int() {
	int n;
	scanf("%d", &n);
	re n;
}

ll n, a, b, x;

ll pow1(ll a, ll k) {
	if (k == 1) re a % md;
	if (k == 0) re 1 % md;
	ll ans = pow1(a, k / 2LL);
	ans = (ans * ans) % md;
	ans = (ans * pow1(a, k % 2)) % md;
	re (ans + md) % md;
}

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen("sum.in", "r", stdin);
    //freopen("unitopsort.out", "w", stdout);
   	cin >> a >> b >> n >> x;
   	if (a == 1LL) {
   		ll ans = (x + b * (n % md)) % md;
   		ans = (ans % md + md) % md;
   		cout << ans;
    	return 0;
   	}
   	ll ans = b * (((1LL - pow1(a, n)) * pow1(1LL - a, md - 2)) % md) % md + x * pow1(a, n)%md;
   	ans = (ans % md + md) % md;
   	cout << ans;
    return 0;
}