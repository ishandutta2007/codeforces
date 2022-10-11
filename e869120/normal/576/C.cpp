#include<iostream>
#include<vector>
using namespace std;
#pragma warning(disable: 4996)
int n, a[1000009], b[1000009]; vector<int>v[1009][1009]; vector<int>J;
int main() {
	cin >> n; for (int i = 1; i <= n; i++) { scanf("%d%d", &a[i], &b[i]); v[a[i] / 1001][b[i] / 1001].push_back(i); }
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			int cx = 0, cy = 0;
			if (i % 2 == 1) { cx = i; cy = j; }
			else { cx = i; cy = 999 - j; }
			for (int k = 0; k < v[cx][cy].size(); k++)J.push_back(v[cx][cy][k]);
		}
	}
	for (int i = 0; i < J.size(); i++) { if (i)cout << " "; cout << J[i]; }cout << endl;
	return 0;
}