/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;
const int INF = 1e9;

int n, ans = INF;
vector<vector<int> > a[4], res;

int get() {
	int c1 = 0, c2 = 0;
	for (int i = 0; i < 2 * n; ++i) {
		for (int j = 0; j < 2 * n; ++j) {
			if (res[i][j] == ((i + j) % 2)) {
				c1++;
			}
			else {
				c2++;
			}
		}
	}
	return min(c1, c2);
}

void push(int x0, int y0, int pos) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			res[x0 + i][y0 + j] = a[pos][i][j];
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < 4; ++i) {
		a[i].resize(n, vector<int> (n));
	}
	res.resize(2 * n, vector<int> (2 * n));
	for (int i = 0; i < 4; ++i) {
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < n; ++y) {
				char c;
				cin >> c;
				a[i][x][y] = c - '0';
			}
		}
	}
	vector<int> p = {0, 1, 2, 3};
	while (true) {
		//cout << "kek" << endl;
		push(0, 0, p[0]);
		push(n, 0, p[1]);
		push(0, n, p[2]);
		push(n, n, p[3]);
		ans = min(ans, get());
		if (!next_permutation(p.begin(), p.end()))
			break;
	}
	cout << ans << endl;
}