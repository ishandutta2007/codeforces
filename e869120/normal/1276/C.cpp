#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 19], cnt[1 << 19];
int score1[1 << 19], score2[1 << 19];
vector<int> X;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		X.push_back(A[i]);
	}
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	for (int i = 1; i <= N; i++) A[i] = lower_bound(X.begin(), X.end(), A[i]) - X.begin();
	for (int i = 1; i <= N; i++) cnt[A[i]]++;

	for (int i = 0; i < X.size(); i++) {
		score1[cnt[i] - 1]++;
		score2[cnt[i]] += cnt[i];
	}
	for (int i = 1; i <= N; i++) score2[i] += score2[i - 1];
	for (int i = N; i >= 1; i--) score1[i] += score1[i + 1];

	int maxn = 0, idx = -1;
	for (int i = 1; i <= N; i++) {
		int v = (score1[i] * i + score2[i]) / i;
		if (maxn < i * v && i <= v) {
			maxn = i * v;
			idx = i;
		}
	}

	vector<int> vec; vector<pair<int, int>> E;
	for (int i = 0; i < X.size(); i++) E.push_back(make_pair(cnt[i], i));
	sort(E.begin(), E.end()); reverse(E.begin(), E.end());
	for (int t = 0; t < E.size(); t++) {
		int i = E[t].second;
		for (int j = 0; j < min(cnt[i], idx); j++) vec.push_back(X[i]);
	}
	vector<vector<int>> ans(idx, vector<int>(maxn / idx, 0)); int cnts = 0;
	for (int j = 0; j < maxn / idx; j++) {
		for (int i = 0; i < idx; i++) {
			ans[i][(i + j) % (maxn / idx)] = vec[cnts];
			cnts++;
		}
	}
	
	printf("%d\n", maxn);
	printf("%d %d\n", idx, maxn / idx);
	for (int i = 0; i < idx; i++) {
		for (int j = 0; j < maxn / idx; j++) {
			if (j) printf(" ");
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}