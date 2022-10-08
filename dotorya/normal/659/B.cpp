#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 987654321;
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

vector <pair<int, string>> in[10050];

char u[105];
int main() {
	int N, M, i, t1, t2;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		scanf("%s %d %d", u, &t1, &t2);
		string x = string(u);

		in[t1].push_back(mp(t2, x));
	}

	for (i = 1; i <= M; i++) {
		sort(in[i].begin(), in[i].end());
		if (in[i].size() == 2 || in[i][in[i].size() - 2].first != in[i][in[i].size() - 3].first) printf("%s %s\n", in[i][in[i].size() - 2].second.c_str(), in[i][in[i].size() - 1].second.c_str());
		else printf("?\n");
	}
	return 0;
}
//*/