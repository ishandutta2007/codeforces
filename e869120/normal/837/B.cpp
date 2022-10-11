#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
string S[10000]; int n, m, a1, a2, a3; bool OK = true;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> S[i];
		for (int j = 0; j < m; j++) {
			if (S[i][j] == 'R')a1++;
			if (S[i][j] == 'B')a2++;
			if (S[i][j] == 'G')a3++;
		}
	}
	if (a1 == 0 || a2 == 0 || a3 == 0) { cout << "NO" << endl; return 0; }
	if (n % 3 == 0) {
		bool P = false;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				if (S[i][j] != S[i + 1][j] && i % (n / 3) != n / 3 - 1)P = true;
				if (S[i][j] == S[i + 1][j] && i % (n / 3) == n / 3 - 1)P = true;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m - 1; j++) {
				if (S[i][j] != S[i][j + 1])P = true;
			}
		}
		if (P == false)OK = false;
	}
	if (m % 3 == 0) {
		bool P = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m - 1; j++) {
				if (S[i][j] != S[i][j + 1] && j % (m / 3) != m / 3 - 1)P = true;
				if (S[i][j] == S[i][j + 1] && j % (m / 3) == m / 3 - 1)P = true;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				if (S[i][j] != S[i + 1][j])P = true;
			}
		}
		if (P == false)OK = false;
	}
	if (OK == false)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}