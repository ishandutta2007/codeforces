#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string T; long long a[10000], p[10000], n, u1[10000], v1[10000], u2[10000], v2[10000];

long long solve(string S) {
	n = (int)S.size() / 2; n++;
	for (int i = 0; i < S.size(); i += 2)a[i / 2 + 1] = (S[i] - '0');
	for (int i = 1; i < S.size(); i += 2) { if (S[i] == '*') { p[i / 2 + 1] = 1; } }

	for (int i = 0; i <= n + 1; i++) { v1[i] = 1; v2[i] = 1; }
	for (int i = 1; i <= n; i++) {
		if (p[i] == 1) { u1[i] = u1[i - 1]; v1[i] = v1[i - 1] * a[i]; }
		else { u1[i] = u1[i - 1] + v1[i - 1] * a[i]; v1[i] = 1; }
	}
	for (int i = n; i >= 1; i--) {
		if (p[i - 1] == 1) { u2[i] = u2[i + 1]; v2[i] = v2[i + 1] * a[i]; }
		else { u2[i] = u2[i + 1] + v2[i + 1] * a[i]; v2[i] = 1; }
	}
	long long maxn = 0;
	for (int i = 1; i <= n; i++) {
		long long R = 0, S = 1; bool C = false;
		for (int j = i; j <= n; j++) {
			if (p[j] == 1) { S *= a[j]; C = true; }
			else { R += S*a[j]; S = 1; C = false; }
			long long V = R;
			if (C == true)V = R + S;
			maxn = max(maxn, u1[i - 1] + u2[j + 1] + v1[i - 1] * v2[j + 1] * V);
		}
	}
	return maxn;
}
int main() {
	cin >> T;
	cout << solve(T) << endl;
	return 0;
}