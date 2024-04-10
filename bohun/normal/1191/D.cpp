//vsp
#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int n;
ll a[100100];

void answer(int x) {
	cout << (x == 0 ? "cslnb\n" : "sjfnb\n");
	exit(0);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	FOR(i, n)
		cin >> a[i];
	sort(a, a + n);

	if (n == 1)
		answer(a[0] % 2);

	int cnt = 0;
	FOR(i, n - 1)
		cnt += a[i] == a[i + 1];
	if (cnt > 1) 
		answer(0);

	int sw = 0;
	if (cnt == 1) {
		sw = 1;
		FOR(i, n - 1)
			if (a[i] == a[i + 1]) {
				if (a[i] == 0)
					answer(0);
				a[i]--;
			}
		sort(a, a + n);
		FOR(i, n - 1)
			if (a[i] == a[i + 1])
				answer(0);
	}

	ll s = 0;
	FOR(i, n)
		s += a[i] - i;
	answer((s % 2) ^ sw);
	return 0;
}