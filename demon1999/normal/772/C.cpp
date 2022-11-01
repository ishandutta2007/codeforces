#include <bits/stdc++.h>
  
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define prev previ
#define tm tmmm
#define div divv
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll mod = ll(1e9) + 7;

int n, m, ok[300000], dp[300000], pr[300000];
vector<int> k[300000], a, div;

void my_gcd(ll x, ll y, ll &a, ll &b) {
	if (x < y) {
		my_gcd(y, x, b, a);
		re;
	}
	if (y == 0) {
		a = 1;
		b = 0;
		re;
	}
	ll na, nb;
	my_gcd(y, x % y, nb, na);
	a = na;
	b = nb - (x / y) * na;
}
int main() {
	//iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	scanf("%d%d", &n, &m);
	a.resize(n);
	forn (i, n) {
		cin >> a[i];
		ok[a[i]] = 1;
	}
	forn (i, m) {
		if (ok[i] == 0)
			k[__gcd(i, m)].push_back(i);
	}
	dp[1] = sz(k[1]);
	for (int i = 1; i <= m; i++)
		if (m % i == 0) 
			div.push_back(i);
	for (int i = 0; i < sz(div); i++) {
		dp[i] = 0;
		pr[i] = -1;
		forn (j, i)
			if (div[i] % div[j] == 0 && dp[i] < dp[j]) {
				dp[i] = dp[j];
				pr[i] = j;
			} 
		dp[i] += sz(k[div[i]]);
	}
	int ans = 0, pos = 0;
	for (int i = 0; i < sz(div); i++)
		if (dp[i] > ans) {
			ans = dp[i];
			pos = i;
		}
	vector<int> an;
	while (pos >= 0) {
		for (int v : k[div[pos]])
			an.push_back(v);
		pos = pr[pos];
	}
	an.push_back(1);
	reverse(an.begin(), an.end());
	printf("%d\n", ans);
	for (int i = 1; i < sz(an); i++) {
		ll a, b;
		my_gcd(an[i - 1], m, a, b);
		a *= (ll(an[i]) / ll(__gcd(an[i - 1], m)));
		a %= m;
		a += ll(m);
		a %= m;
		printf("%d ", int(a));
	}
}