#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int matrix[25][25];

main(){
#ifdef LOCAL
	//freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;	

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i%2 == 0) continue;
			int val = (1LL<<(i + j));
			matrix[i][j] = val;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		int res;
		cin >> res;

		res -= matrix[0][0];
		int x = 0, y = 0;
		cout << 1 << " " << 1 << endl;
		while (x != n-1 || y != n-1) {
			if (x == n-1) y++;
			else if (y == n-1) x++;
			else {
				int A = matrix[x+1][y], B = matrix[x][y+1];
				if (A != 0) {
					if ((A&res)) {
						res -= A;
						x++;
					}
					else y++;
				}
				else {
					if ((B&res)) {
						res -= B;
						y++;
					}
					else x++;
				}
			}

			cout << x+1 << " " << y+1 << endl;
		}

	}


}