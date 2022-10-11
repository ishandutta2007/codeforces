#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<functional>
#include<cstdio>
using namespace std;
#pragma warning(disable:4996)
int p[11][101][101], n, q, c, x[100009], y[100009], s[100009];
int main() {
	cin >> n >> q >> c; c++;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &x[i], &y[i], &s[i]);
		for (int j = 0; j < c; j++)p[j][x[i]][y[i]] += (s[i] + j) % c;
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int k = 1; k <= 100; k++)p[i][j][k] += p[i][j][k - 1];
		}
		for (int j = 1; j <= 100; j++) {
			for (int k = 0; k <= 100; k++)p[i][j][k] += p[i][j - 1][k];
		}
	}
	for (int i = 0; i < q; i++) {
		int t, a, b, v, d; scanf("%d%d%d%d%d", &t, &a, &b, &v, &d); t %= c;
		cout << p[t][a - 1][b - 1] + p[t][v][d] - p[t][a - 1][d] - p[t][v][b - 1] << endl;
	}
	return 0;
}