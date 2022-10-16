#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, M = 998244353, N = 1e6 + 7;

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}
int ad(int a, int b) {
	return add(a, b), a;
}
int mu(int a, int b) {
	return int(1LL * a * b % M);
}
void mul(int& a, int b) {
	a = mu(a, b);
}
int inv(int a) {
	return a == 1 ? 1 : M - mu(M / a, inv(M % a));
}
int f[N], iv[N], fi[N];

int cnt[N], dp_ways[N], dp_sum[N];

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		cnt[x]++;
	}

[&] () {

	int g = 0;
	vi hebe;
	for(int i = 1; i <= n; i++) if(cnt[i]) {
		hebe.PB(cnt[i]);
		g = __gcd(g, cnt[i]);
	}

	if(g == n) {
		cout << 1 << '\n';
		return;
	}
	int tot_ways = 0, tot_sum = 0;
	for(int k = 2; k <= n; k++) if(n % k == 0 && g % (n / k) == 0) {
		// k is the min rep len
		int ways = f[k];
		for(int x:hebe) 
			mul(ways, fi[x / (n / k)]);
		add(dp_ways[k], ways);

		int sum = 0;

		for(int i = 0, pre = 0; i < SZ(hebe); i++) {
			int x = hebe[i] / (n / k);
			int cur = mu(fi[x - 1], f[x]);
			add(sum, mu(cur, pre));
			add(pre, cur);
		}

		add(sum, sum);
		mul(sum, f[k - 2]);
		for(int x:hebe) 
			mul(sum, fi[x / (n / k)]);
		mul(sum, k);
		add(dp_sum[k], sum);

		add(tot_ways, mu(dp_ways[k], iv[k]));
		add(tot_sum, mu(mu(dp_sum[k], iv[k]), n / k));

		for(int i = 2 * k; i <= n; i += k) {
			add(dp_ways[i], M - dp_ways[k]);
			add(dp_sum[i], M - mu(dp_sum[k], i / k));
		}
	}

	assert(tot_ways);
	cout << mu(tot_sum, inv(tot_ways)) << '\n';

} ();

	for(int i = 1; i <= n; i++) {
		cnt[i] = 0;
		dp_sum[i] = 0;
		dp_ways[i] = 0;
	}
}

signed main()
{
	IO_OP;

	f[0] = 1;
	for(int i = 1; i < N; i++)
		f[i] = mu(f[i - 1], i);
	iv[1] = 1;
	for(int i = 2; i < N; i++)
		iv[i] = M - mu(M / i, iv[M % i]);
	fi[0] = 1;
	for(int i = 1; i < N; i++)
		fi[i] = mu(fi[i - 1], iv[i]);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

}