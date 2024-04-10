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
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX;
const int MOD = 9901;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

int in[100050];
int ans[100050];
bool chk[100050];
vector <pii> V;

int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 1; i <= N; i++) {
		if (chk[i]) continue;
		chk[i] = true;
		int p = in[i];
		for (j = 1; chk[p] != true; j++, p = in[p]) chk[p] = true;
		V.push_back(pii(j, i));
	}

	sort(V.begin(), V.end());
	if (V[0].first == 1) {
		printf("YES\n");
		for (i = 1; i <= N; i++) if (i != V[0].second) printf("%d %d\n", i, V[0].second);
		return 0;
	}

	else if (V[0].first >= 3) return printf("NO\n"), 0;

	for (i = 1; i < V.size(); i++) if (V[i].first % 2) return printf("NO"), 0;
	
	printf("YES\n");
	fill(chk + 1, chk + N + 1, false);
	chk[V[0].second] = chk[in[V[0].second]] = true;
	for (i = 1; i <= N; i++) {
		if (chk[i]) continue;
		chk[i] = true;
		ans[i] = V[0].second;
		int p = in[i];
		for (j = 1; chk[p] != true; j++, p = in[p]) {
			chk[p] = true;
			if (j % 2 == 1) ans[p] = in[V[0].second];
			else ans[p] = V[0].second;
		}
	}

	printf("%d %d\n", V[0].second, in[V[0].second]);
	for (i = 1; i <= N; i++) {
		if (i == V[0].second || i == in[V[0].second]) continue;
		printf("%d %d\n", i, ans[i]);
	}
	return 0;
}
//*/