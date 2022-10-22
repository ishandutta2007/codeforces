#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define LL long long
#define LD long double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;		

char s[100111];

LL a, b;

unordered_map <LL, int> prime;

void solve() {
	prime.clear();
	scanf ("%lld %lld", &a, &b);
	LL A, B, G;
	A = a;
	B = b;
	LL g = __gcd(a, b);
	G = g;
	vector <LL> pp;
	for (int i = 2; 1LL * i * i <= g; ++i) {
		while (g % i == 0) {
			pp.pb(i);
			g /= i;
		}
	}
	if (g > 1) pp.pb(g);
	vector <LL> p;
	for (int i = 2; 1LL * i * i <= b; ++i) {
		while (b % i == 0) {
			p.pb(i);
			b /= i;
		}
	}
	if (b > 1) p.pb(b);
	vector <LL> dop;
	
	for (auto it : pp)
		prime[it]++;
	
	for (auto it : p) {
		if (prime[it] == 0) dop.pb(it);
		else prime[it]--;
	}
	
	sort(dop.begin(), dop.end());
	dop.erase(unique(dop.begin(), dop.end()), dop.end());
	
	LL ans = 0;
	for (int mask = 0; mask < (1 << ss(dop)); ++mask) {
		LL liczba = 1;
		for (int j = 0; j < ss(dop); ++j)
			if ((mask >> j) & 1)
				liczba *= dop[j];
		liczba *= G;
		LL ile = (A + B - 1) / liczba - (A - 1) / liczba;
		int cnt = __builtin_popcount(mask) % 2;
		if (cnt == 0) ans += ile;
		else ans -= ile;
	}
	printf ("%lld\n", ans);		
}
		
		

int main() {	
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
		
	
	return 0;
}