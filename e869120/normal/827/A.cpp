#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
int n, d[100009]; string S[100009]; vector<int>F[100009]; int G1[2000009], G2[2000009], Y[2000009];
int main() {
	cin >> n;
	for (int i = 0; i < 2000009; i++)G1[i] = -1e9;
	for (int i = 0; i < n; i++) {
		cin >> S[i] >> d[i];
		for (int j = 0; j < d[i]; j++) {
			int t; scanf("%d", &t);
			if (G1[t] < (int)S[i].size()) { G1[t] = S[i].size(); G2[t] = i; }
			F[i].push_back(t);
		}
	}
	int maxn = 0;
	for (int i = 1; i <= 2000000; i++) {
		int R = i + G1[i] - 1;
		if (maxn < R) {
			for (int j = max(maxn + 1, i); j <= R; j++) { Y[j] = (S[G2[i]][j - i] - 'a'); }
			maxn = R;
		}
	}
	for (int i = 1; i <= maxn; i++) { cout << (char)('a' + Y[i]); }cout << endl;
	return 0;
}