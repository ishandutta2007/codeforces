#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

// 
int T, N, K;
string S;

// 
int c1[1 << 19];
int c2[1 << 19];
int c3[1 << 19];

bool solve() {
	for (int i = 0; i < K; i++) c1[i] = 0;
	for (int i = 0; i < K; i++) c2[i] = 0;
	for (int i = 0; i < K; i++) c3[i] = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '0') c1[i % K] += 1;
		if (S[i] == '1') c2[i % K] += 1;
		if (S[i] == '?') c3[i % K] += 1;
	}
	int cl = 0, cr = K;
	for (int i = 0; i < K; i++) {
		if (c1[i] >= 1 && c2[i] >= 1) return false;
		if (c1[i] >= 1) cl += 1;
		if (c2[i] >= 1) cr -= 1;
	}
	if (cr < (K >> 1) || (K >> 1) < cl) return false;
	return true;
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &N, &K);
		cin >> S;
		bool ret = solve();
		if (ret == true) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}