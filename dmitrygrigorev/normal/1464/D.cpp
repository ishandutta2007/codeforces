#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

int get_ans(int n) {
	int t = 1;
	while (n % 3 != 0) {
		t = ((ll) t * 2) % mod;
		n -= 2;
	}

	while (n) {
		t = ((ll) t * 3) % mod;
		n -= 3;
	}

	return t;

}

int solve2(vector<int> lens, int n) {

	if (n==1) return 0;

	//for (auto x : lens) cout << x << " ";

	int ans = 0;

	int u = 0;

	bool can = true;
	if (n % 3 != 1) can = false;

	while (u < lens.size()) {
		while (lens[u] > 3) {
			if (lens[u] == 4 && can) {
				can = false;
				break;
			}
			lens.pb(3);
			lens[u] -= 3;
			ans++;
		}
		u++;
	}

	int a = 0, b = 0;
	for (auto x : lens) {
		//cout << x << " ";
		if (x==1) a++;
		if (x == 2) b++;
	}

	while (can) {
		if (b >= 2) {
			b -= 2;
			break;
		}
		else if (a >= 2 && b) {
			a -= 2;
			b -= 1;
			ans++;
			break;
		}
		else if (a >= 2) {
			a -= 2;
			b++;
			ans++;
		}
		else break;
	}

	while (true) {
		if (b && a) {
			b--, a--, ans++;
		}
		else if (a >= 2) {
			a -= 2, b++, ans++;
		}
		else if (b >= 3) {
			b -= 3;
			ans += 3;
		}
		else break;
	}

		if (b && (n%3==1)) return 1e9;


	if (a && (n % 3 == 1)) ans++;

	return ans;

}

int solve(vector<int> lens, int n) {

	if (n==1) return 0;

	//for (auto x : lens) cout << x << " ";

	int ans = 0;

	int u = 0;

	bool can = true;
	if (n % 3 != 1) can = false;

	int Q = 0;

	while (u < lens.size()) {
		while (lens[u] > 3) {
			lens.pb(3);
			lens[u] -= 3;
			ans++;
		}
		if (lens[u] == 2) Q++;
		u++;
	}

	while (u < lens.size()) {
		while (lens[u] > 3) {
			if (lens[u] == 4 && can && Q < 2) {
				can = false;
				break;
			}
			lens.pb(3);
			lens[u] -= 3;
			ans++;
		}
		u++;
	}

	int a = 0, b = 0;
	for (auto x : lens) {
		//cout << x << " ";
		if (x==1) a++;
		if (x == 2) b++;
	}

	while (can) {
		if (b >= 2) {
			b -= 2;
			break;
		}
		else if (a >= 2 && b) {
			a -= 2;
			b -= 1;
			ans++;
			break;
		}
		else if (a >= 2) {
			a -= 2;
			b++;
			ans++;
		}
		else break;
	}

	while (true) {
		if (b && a) {
			b--, a--, ans++;
		}
		else if (a >= 2) {
			a -= 2, b++, ans++;
		}
		else if (b >= 3) {
			b -= 3;
			ans += 3;
		}
		else break;
	}

	if (b && (n%3==1)) return 1e9;

	if (a && (n % 3 == 1)) ans++;

	return ans;

}

void solve() {

	int n;
	cin >> n;

	vector<int> v(n);
	for (auto &x : v) {
		cin >> x;
		x--;
	}

	cout << get_ans(n) << ' ';

	vector<int> lens;
	vector<bool> used(n, false);
	for (int i = 0; i < n; ++i) {
		if (used[i]) continue;
		int T = v[i];

		used[i] = true;
		int len = 1;
		while (!used[T]) {
			used[T] = true;
			T = v[T];
			len++;
		}
		lens.pb(len);

	}

	cout << min(solve(lens, n), solve2(lens, n)) << '\n';

}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}