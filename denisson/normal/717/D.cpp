#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <cassert>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
using namespace std;

double P[137];
double G[137][137];

int n, x;

struct matr {
	vector<vector<double> > T;
	matr() {
		T.resize(137, vector<double>(137));
	}
};

matr mul(matr A, matr B) {
	matr cur;
	for (int i = 0; i < 128; i++)
		for (int j = 0; j < 128; j++)
			for (int k = 0; k < 128; k++)
				cur.T[i][j] += A.T[i][k] * B.T[k][j];
	return cur;
}

matr bp(matr A, int k) {
	if (k == 1) {
		return A;
	}
	if (k % 2) {
		return mul(bp(A, k - 1), A);
	}
	matr H = bp(A, k / 2);
	return mul(H, H);
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	cin >> n >> x;

	for (int i = 0; i <= x; i++)
		cin >> P[i];


	matr G;
	for (int i = 0; i < 128; i++)
		for (int j = 0; j < 128; j++)
			if ((i ^ j) <= x)
				G.T[i][j] = P[i ^ j];

	matr dp;
	dp.T[0][0] = 1;

	/*dp[0][0] = 1;

	for (int h = 0; h <= n; h++) {
	for (int l = 0; l < 128; l++) {
	for (int t = 0; t < 128; t++) {
	dp[h + 1][l] += dp[h][t] * G[t][l];
	}
	}
	}*/

	matr K = mul(dp, bp(G, n));
	/*
	for (int i = 0; i <= n; i++) {
	for (int j = 0; j < 4; j++)
	err("%.5f, ", K.T[i][j]);
	err("\n");
	}*/

	//C[i][j] += A[i][k] * B[k][j];


	printf("%.10f", 1 - K.T[0][0]);
	return 0;
}