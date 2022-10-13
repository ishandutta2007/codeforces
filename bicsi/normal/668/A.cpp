#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

int Elem[500][500];
int Real[500000];
int elems;

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			Elem[i][j] = ++elems;
		}
	
	int t, r, c, x;
	while(q--) {
		cin >> t;
		if(t == 3) {
			cin >> r >> c >> x;
			Real[Elem[r][c]] = x;
		} else if(t == 1) {
			cin >> r;
			int aux = Elem[r][1];
			for(int i = 2; i <= m; ++i) {
				Elem[r][i - 1] = Elem[r][i];
			}
			Elem[r][m] = aux;
		} else {
			cin >> c;
			int aux = Elem[1][c];
			for(int i = 2; i <= n; ++i) {
				Elem[i - 1][c] = Elem[i][c];
			}
			Elem[n][c] = aux;
		}
	}

	elems = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cout << Real[++elems] << ' ';
		}
		cout << '\n';
	}

	return 0;
}