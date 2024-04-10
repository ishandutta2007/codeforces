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

ll n, a, b, p, q;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen("sum.in", "r", stdin);
    //freopen("unitopsort.out", "w", stdout);
   	cin >> n >> a >> b >> p >> q;
   	ll gca = a * b / __gcd(a, b);
   	cout << max((n / a) * p + (n / b - n / gca) * q, 
   				(n / a - n / gca) * p + (n / b) * q);
    return 0;
}