/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 55;
string s[N], r[N];
int dp[N][N], n, m;

void ans(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m)
		return;
	if (dp[i][j] != -1) {
		return;
	}
	if (s[i][j] == '#')
		return;
	dp[i][j] = 1;
	ans(i - 1, j);
	ans(i, j + 1);
	ans(i, j - 1);
	ans(i + 1, j);
}

int32_t main(){
	int t = 1;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cin >> n >> m;
		for (int i = 0; i < N; i++) {
			s[i] = "";
			r[i] = "";
		}
		int g = 0, b = 0;
		bool f = true;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			s[i] += '#';
			r[i] = s[i];
		}
		s[n] = "";
		for (int i = 0; i < m + 1; i++) {
			s[n] += '#';
		}
		r[n] = s[n];
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++) {
				if (s[i][j] == 'G')
					g++;
				if (s[i][j] == 'B')
					b++;
				if (s[i][j] == 'B'){
					if (i == 0 && j == 0){
						if (s[i][j + 1] == 'G' || s[i + 1][j] == 'G' || (i + 1 == n - 1 && j == m - 1) || (i == n - 1 && j + 1 == m - 1))
							f = false;
					}else if (i == 0){
						if (s[i][j - 1] == 'G' || s[i][j + 1] == 'G' || s[i + 1][j] == 'G' || (i + 1 == n - 1 && j == m - 1) || (i == n - 1 && j + 1 == m - 1))
							f = false;
					}else if (j == 0){
						if (s[i - 1][j] == 'G' || s[i][j + 1] == 'G' || s[i + 1][j] == 'G' || (i + 1 == n - 1 && j == m - 1) || (i == n - 1 && j + 1 == m - 1))
							f = false;
					}else if (s[i - 1][j] == 'G' || s[i][j - 1] == 'G' || s[i][j + 1] == 'G' || s[i + 1][j] == 'G' || (i + 1 == n - 1 && j == m - 1) || (i == n - 1 && j + 1 == m - 1))
						f = false;
					if (i > 0 && r[i - 1][j] != 'B') {
						r[i - 1][j] = '#';
					}
					if (j < m - 1 && r[i][j + 1] != 'B') {
						r[i][j + 1] = '#';
					}
					if (i < n - 1 && r[i + 1][j] != 'B') {
						r[i + 1][j] = '#';
					}
					if (j > 0 && r[i][j - 1] != 'B') {
						r[i][j - 1] = '#';
					}
				}
			}
		}
		if (g == 0){
			cout << "Yes\n";
			continue;
		}
		if (!f){
			cout << "No\n";
			continue;
		}
		bool h = true;
		for (int i = 0; i < n; i++){
			s[i] = r[i];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dp[i][j] = -1;
			}
		}
		ans(n - 1, m - 1);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (s[i][j] == 'G'){
					if (dp[i][j] != 1) {
						h = false;
					}
				}
			}
		}
		cout << (h ? "Yes" : "No") << endl;
	}
}