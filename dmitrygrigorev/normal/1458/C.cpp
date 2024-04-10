#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int matrix[1007][1007];
int ans[1007][1007];

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}

	pair<int, int> a = mp(0, 0), b = mp(0, 1), c = mp(0, 2);

	for (int i = 0; i < m; ++i) {

		char ch;
		cin >> ch;

		if (ch == 'R') {
			b.x++;
		}
		else if (ch == 'L') {
			b.x--;
		}
		else if (ch == 'U') {
			a.x--;
		}
		else if (ch == 'D') {
			a.x++;
		}

		else if (ch == 'I') {
			swap(b, c);
		}
		else {
			swap(a, c);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			vector<int> A = {i, j, matrix[i][j] - 1};
			int w0 = (((A[a.y] + a.x) % n) + n) % n;
			int w1 = (((A[b.y] + b.x) % n) + n) % n;
			int w2 = (((A[c.y] + c.x) % n) + n) % n;
			ans[w0][w1] = w2;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ans[i][j]+1 << " ";
		}
		cout << '\n';
	}



}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}