#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int matrix[507][507];
int tatrix[507][507];

int main(){
#ifdef LOCAL
	freopen("M_input.txt", "r", stdin);
	//freopen("M_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> tatrix[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		int a = 0;
		for (int j = 0; j < m; ++j) {
			a ^= (matrix[i][j] ^ tatrix[i][j]);
		}

		if (a) {
			cout << "No";
			exit(0);
		}
	}

	for (int i = 0; i < m; ++i) {
		int a = 0;
		for (int j = 0; j < n; ++j) {
			a ^= (matrix[j][i] ^ tatrix[j][i]);
		}

		if (a) {
			cout << "No";
			exit(0);
		}
	}

	cout << "Yes";

}