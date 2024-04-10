#include <iostream>

using namespace std;
typedef pair<int, int> pii;

int n,m,k;
int g[100][100][100];
int c[100][100][100];

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			string s;
			cin >> s;
			for(int l = 0; l < k; ++l) {
				g[i][j][l] = s[l] == '1';
				c[i][j][l] = 0;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			for(int l = 0; l < k; ++l) {
				if(j != m-1 && l != k-1 && g[i][j][l] && g[i][j+1][l+1]) {
					c[i][j+1][l] |= g[i][j+1][l] & !g[i][j][l+1];
					c[i][j][l+1] |= g[i][j][l+1] & !g[i][j+1][l];
				}
				if(i != n-1 && l != k-1 && g[i][j][l] && g[i+1][j][l+1]) {
					c[i+1][j][l] |= g[i+1][j][l] & !g[i][j][l+1];
					c[i][j][l+1] |= g[i][j][l+1] & !g[i+1][j][l];
				}
				if(j != m-1 && i != n-1 && g[i][j][l] && g[i+1][j+1][l]) {
					c[i][j+1][l] |= g[i][j+1][l] & !g[i+1][j][l];
					c[i+1][j][l] |= g[i+1][j][l] & !g[i][j+1][l];
				}

				if(!g[i][j][l]) continue;
				if(i != 0 && i != n-1)
					c[i][j][l] |= g[i-1][j][l] & g[i+1][j][l];
				if(j != 0 && j != m-1)
					c[i][j][l] |= g[i][j-1][l] & g[i][j+1][l];
				if(l != 0 && l != k-1)
					c[i][j][l] |= g[i][j][l-1] & g[i][j][l+1];
			}
		}
	}
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			for(int l = 0; l < k; ++l)
				ans += c[i][j][l];
	cout << ans << "\n";
	return 0;
}