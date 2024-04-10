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

int in[1000050];
int pos[1000050][2];
int occ[1000050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		if (pos[in[i]][0] == 0) pos[in[i]][0] = i;
		pos[in[i]][1] = i;
		occ[in[i]]++;
	}

	int mxoc = 0;
	for (i = 1; i <= N; i++) if (occ[in[i]] > occ[mxoc]) mxoc = in[i];

	int ans = 0, mn = INF;
	for (i = 1; i <= N; i++) {
		if (occ[in[i]] != occ[mxoc]) continue;
		if (pos[in[i]][1] - pos[in[i]][0] < mn) {
			ans = in[i];
			mn = pos[in[i]][1] - pos[in[i]][0];
		}
	}

	printf("%d %d", pos[ans][0], pos[ans][1]);
	return 0;
}