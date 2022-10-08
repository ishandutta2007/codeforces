//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 131072;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;

vector <int> val[100050];
vector <int> tmp;
int in[100050];
int main() {
	int N, i, j, k;
	scanf("%d", &N);
	if (N == 1) {
		printf("0");
		return 0;
	}
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		int t = in[i];
		while (t != 0) {
			tmp.push_back(t % 2);
			t /= 2;
		}
		while (!tmp.empty()) {
			val[i].push_back(tmp.back());
			tmp.pop_back();
		}
	}

	int L = 0;
	for (L = 0;; L++) {
		for (i = 1; i <= N; i++) if (L >= val[i].size()) break;
		if (i <= N) break;
		for (i = 2; i <= N; i++) if (val[i][L] != val[1][L]) break;
		if (i <= N) break;
	}
	
	int ans = 0;
	for (i = 1; i <= N; i++) {
		for (j = L; j < val[i].size(); j++) if (val[i][j] == 1) break;
		while (val[i].size() != j) {
			val[i].pop_back();
			ans++;
		}
	}

	int t = 0, rv = INF, mn = INF, mx = 0;
	for (i = 1; i <= N; i++) {
		mn = min(mn, (int)val[i].size());
		mx = max(mx, (int)val[i].size());
	}
	for (i = mn; i <= mx; i++) {
		t = 0;
		for (j = 1; j <= N; j++) t += abs((int)val[j].size() - i);
		if (t < rv) rv = t;
	}
	printf("%d", ans + rv);
	return 0;
}