#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, k, a[1000][1000], cnt;
int main() {
	cin >> n >> k;
	if (n*n < k) { cout << "-1" << endl; return 0; }
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int G = 1; if (i != j) { G = 2; }
			if (cnt + G <= k) { cnt++; a[i][j] = 1; if (i != j) { a[j][i] = 1; cnt++; } }
		}
	}
	if (cnt != k) { for (int i = 0; i < n; i++) { if (a[i][i] == 0) { a[i][i] = 1; break; } } }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j)cout << ' '; cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}