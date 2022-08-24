#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int matrix[300007][8];
int pos[256];

int main(){
#ifdef LOCAL
	freopen("O_input.txt", "r", stdin);
	//freopen("O_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cin >> matrix[i][j];
	}

	int L = -(1e9+7), R = (1e9+7);
	int a, b;

	while (R-L>1) {
		int M = (L+R)/2;
		for (int i = 0; i < (1<<m); ++i) pos[i] = -1;

		for (int i = 0; i < n; ++i) {
			int tut = 0;
			for (int j = 0; j < m; ++j) {
				if (matrix[i][j] >= M) {
					tut |= (1<<j);
				}
			}
			//cout << i << " " << tut << "\n";
			pos[tut] = i;
		}

		//exit(0);

		bool can = false;

		for (int e = 0; e < (1<<m); ++e) {
			for (int f = 0; f < (1<<m); ++f) {
				if (pos[e] != -1 && pos[f] != -1) {
					if ((e|f) == ((1<<m)-1)) {
						a = pos[e], b = pos[f];
						can = true;
					}
				}
			}
		}

		if (can) L = M;
		else R = M;

	}

	cout << (a+1) << " " << (b+1) << endl;



}