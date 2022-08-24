#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

char matrix[307][307];
int sum[3][2];

void solve() {

	int n;
	cin >> n;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			sum[i][j] = 0;
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n ;++j) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 'X') {
				cnt++;
				sum[(i+j)%3][0]++;
			}
			if (matrix[i][j] == 'O') {
				cnt++;
				sum[(i+j)%3][1]++;
			}
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i==j) continue;
			if (3*(sum[i][0] + sum[j][1]) <= cnt) {
				for (int e = 0; e < n; ++e) {
					for (int f = 0; f < n; ++f) {
						int Z = (e+f)%3;
						if (matrix[e][f] == 'X' && i == Z) {
							cout << 'O';
						}
						else if (matrix[e][f] == 'O' && j == Z) {
							cout << 'X';
						}
						else cout << matrix[e][f];
					}
					cout << '\n';
				}
				return;
			}
		}
	}

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

	for (int i = 0; i < t; ++i) {
		solve();

	}

}