#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Operation {
	char ch;
	int x;
	int y;
};

vector<Operation> ans;

set<int> have;

void add(vector<int> &gauss, int x) {

	for (int i = 59; i >= 0; i--) {
		if (!((1LL<<i)&x)) continue;
		if (gauss[i] == -1) {
			gauss[i] = x;
			break;
		}

		if (!have.count(x ^ gauss[i])) {
			ans.pb({'^', x, gauss[i]});
			have.insert(x^gauss[i]);
		}

		x ^= gauss[i];

	}

}

int get_shifted(vector<int> &gauss) {
	int X = 0;
	int oldest = -1;

	for (int i = 59; i >= 0; i--) {
		if (gauss[i] == -1) continue;
		if (rand() % 2) {

			if (!have.count(X ^ gauss[i])) {
				ans.pb({'^', X, gauss[i]});
				have.insert(X^gauss[i]);
			}

			X ^= gauss[i];
			if (oldest == -1) oldest = i;
		}
	}

	if (X==0) {
		int u = 0;
		while (true) {
			if (gauss[u%60] != -1 && rand() % 2) return gauss[u%60];
			u++;
		}
	}

	int remaining = 59 - oldest;
	int Q = rand() % (remaining + 1);

	for (int i = 0; i < Q; ++i) {
		if (!have.count(X + X)) {
			ans.pb({'+', X, X});
			have.insert(X+X);
		}
		X += X;
	}

	return X;
}

main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	srand(time(NULL));

	int n;
	cin >> n;

	have.insert(n);
	ans.pb({'^', n, n});
	have.insert(0);

	vector<int> gauss(60, -1);
	add(gauss, n);

	int steps = 0;
	while (gauss[0] == -1) {

		int X = get_shifted(gauss);
		int Y = get_shifted(gauss);

		if (X + Y < (1LL<<60)) {
			if (!have.count(X + Y)) {
				ans.pb({'+', X, Y});
				have.insert(X+Y);
			}
			add(gauss, X+Y);
		}

	}

	assert(ans.size() <= 100000);
	assert(have.count(1));

	cout << ans.size() << '\n';
	for (auto x : ans) {
		cout << x.x << " " << x.ch << " " << x.y << '\n';
	}


}