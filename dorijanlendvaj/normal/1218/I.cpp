#include <bits/stdc++.h>
using namespace std;
 
int input() {
	char c; cin >> c;
	return c == '1';
}
 
void print_ans(vector<int> r, vector<int> c) {
	int ans = 0;
	for (int i: r) ans += i;
	for (int i: c) ans += i;
 
	cout << ans << '\n';
	for (int i = 0; i < r.size(); i++) {
		if (r[i]) cout << "row " << i << '\n';
		if (c[i]) cout << "col " << i << '\n';
	}
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
 
	int n; cin >> n;
	int a[n][n], c[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = input();
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] ^= input();
		}
	}
	for (int i = 0; i < n; i++) {
		c[i] = input();
	}
	vector<int> tog_row(n), tog_col(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i] + c[j] == 0) {
				if (a[i][j]) {
					cout << -1; exit(0);
				}
			} else if (c[i] + c[j] == 1) {
				if (a[i][j]) {
					if (c[j] == 1) {
						if (!tog_row[i]) {
							tog_row[i] = 1;
						}
					} else {
						if (!tog_col[j]) {
							tog_col[j] = 1;
						}
					}
				}
			}	
		}
	} 
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tog_row[i] || tog_col[j]) {
				if (tog_row[i] && c[j]) a[i][j] ^= 1;
				if (tog_col[j] && c[i]) a[i][j] ^= 1;
				
				if (a[i][j]) {
					cout << -1; exit(0);
				}
			}
		}
	} 
 
	string sample_space;
	for (int i = 0; i < n; i++) {
		if (!tog_row[i] && c[i]) {
			for (int j = 0; j < n; j++) {
				if (!tog_col[j] && c[j]) {
					sample_space.push_back(a[i][j] + '0');
				} else {
					sample_space.push_back('X');
				}
			}
			break;
		}
	} 
	if (sample_space.empty()) {
		print_ans(tog_row, tog_col);
	}
 
	for (int i = 0; i < n; i++) {
		if (!tog_row[i] && c[i]) {
			string space1, space2;
			for (int j = 0; j < n; j++) {
				if (tog_col[j] == 0 && c[j]) {
					space1.push_back(a[i][j] + '0');
					space2.push_back(1 - a[i][j] + '0');
				} else {
					space1.push_back('X');
					space2.push_back('X');
				}
			}
			
			if (space1 == sample_space) continue;
			if (space2 == sample_space) {
				tog_row[i] = 1;
				for (int j = 0; j < n; j++) {
					if (c[j]) a[i][j] ^= 1;
				}
			} else {
				cout << -1;
				exit(0);
			}
		}
	} 
	for (int i = 0; i < n; i++) {
		if (sample_space[i] == '1') {
			tog_col[i] = 1;
		}
	} 
 
	print_ans(tog_row, tog_col);
 
	return 0;
}