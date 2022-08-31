#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

char matrix[107][107];

struct Operation {
	pair<int, int> a;
	pair<int, int> b;
	pair<int, int> c;
};

void print(pair<int, int> x) {
	cout << x.x+1 << " " << x.y + 1 << ' ';
}

void print(vector<Operation> x) {
	cout << x.size() << '\n';
	for (auto t : x) {
		print(t.a);
		print(t.b);
		print(t.c);
		cout << '\n';
	}
}

void apply(pair<int, int> x) {
	if (matrix[x.x][x.y] == '1') matrix[x.x][x.y] = '0';
	else matrix[x.x][x.y] = '1';
}

void apply(Operation x) {
	apply(x.a);
	apply(x.b);
	apply(x.c);
}

void solve() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cin >> matrix[i][j];
	}

	vector<Operation> ans;

	if (n % 2 != 0) {
		for (int i = 0; i < m; ++i) {
			if (matrix[n-1][i] == '0') continue;
			Operation cur;
			cur.a = mp(n-1, i);
			cur.b = mp(n-2, i);
			if (i > 0) cur.c = mp(n-2, i-1);
			else cur.c = mp(n-2, i + 1);
			apply(cur);
			ans.pb(cur);
		}
		n--;
	}

	if (m % 2 != 0) {
		for (int i = 0; i < n; ++i) {
			if (matrix[i][m-1] == '0') continue;
			Operation cur;
			cur.a = mp(i, m-1);
			cur.b = mp(i, m-2);
			if (i > 0) cur.c = mp(i-1, m-2);
			else cur.c = mp(i + 1, m-2);
			apply(cur);
			ans.pb(cur);
		}
		m--;
	}

	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < m; j += 2) {
			while (true) {
				vector<pair<int, int> > bad, good;
				for (int dx = 0; dx < 2; ++dx) {
					for (int dy = 0; dy < 2; ++dy) {
						if (matrix[i+dx][j+dy] == '1') bad.pb(mp(i+dx, j + dy));
						else good.pb(mp(i + dx, j + dy));
					}
				}
				if (!bad.size()) break;
				Operation cur;
				if (bad.size() == 4) {
					cur = {bad[0], bad[1], bad[2]};
				}
				else if (bad.size() == 3) {
					cur = {bad[0], bad[1], bad[2]};
				}
				else if (bad.size() == 2) cur = {bad[0], good[0], good[1]};
				else if (bad.size() == 1) cur = {bad[0], good[0], good[1]};
				apply(cur);
				ans.pb(cur);
			}

		}
	}

	print(ans);

	

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}