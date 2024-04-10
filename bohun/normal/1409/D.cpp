#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;

using namespace std;

int T, s;
ll n, pw[20];

int main() {
	pw[0] = 1;
	for (int i = 1; i <= 18; ++i)
		pw[i] = 10 * pw[i - 1];
	scanf ("%d", &T);
	while (T--) {
		scanf ("%lld%d", &n, &s);
		ll out = 0;
		while (true) {
			int S = 0;
			for (int i = 18; 0 <= i; --i) {
				S += (n / pw[i]) % 10;
				if (S > s) {
					out += pw[i] - n % pw[i];
					n += pw[i] - n % pw[i];
					break;
				}
			}
			if (S <= s) break;
		}				
		printf ("%lld\n", out);
	}
	return 0;
}