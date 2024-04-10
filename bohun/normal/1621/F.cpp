#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, b, a) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << "\n";
using ll = long long;
using namespace std;

const int N = 100100;

int n, a, b, c;
char s[N];

void solve() {
	cin >> n >> a >> b >> c;
	cin >> s + 1;

	int ones = 0;
	rep(i, 1, n - 1) ones += s[i] == '1' && s[i + 1] == '1';

	int Z0 = 0;
	int B0 = 0;
	int B1 = 0;
	multiset<int> S;
	for (int i = 1; i <= n;) {
		if (s[i] == '1') {
			i++;
			continue;
		}
		int j = i;
		while (j <= n && s[j] == '0') j++;
		if (i == 1 || j == n + 1) {
			B0++;
			B1 += j - i - 1;
		}
		else {
			if (j - i == 1) Z0++;
			else S.insert(j - i);
		}
		i = j;
	}

	ll res = 0;
	rep(hit, 0, 1) {
		int z0 = Z0;
		int b0 = B0;
		int b1 = B1;
		int o1 = ones;
		multiset<int> s = S;
		ll sum = 0;
		auto add = [&](int x) {
			sum += x;
			res = max(res, sum);
		};
		if (hit) {
			if (!o1) continue;
			o1--;
			add(b);
		}
		while (true) {
			if (o1) {
				if (!s.empty()) {
					auto x = *s.begin();
					s.erase(s.begin());
					add(a);
					if (x - 1 > 1)
						s.insert(x - 1);
					else
						z0++;
				}
				else if (b1) {
					b1--;
					add(a);
				}
				else if (z0) {
					z0--;
					o1++;
					add(-c);
				}
				else if (b0) {
					b0--;
					add(-c);
				}
				else break;
			}
			else {
				if (!s.empty() || b1) {
					add(a);
					add(-a);
				}
				if (z0) {
					z0--;
					o1++;
					add(-c);
				}
			}
			if (o1 == 0) break;
			o1--;
			add(b);
		}
	}
	cout << res << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}