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

vector <pair <int, int>> V[1050];
int main() {
	int N, t1, t2, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &t1, &t2);
		V[t1 / 1000].push_back(pii(t2, i));
	}

	for (i = 0; i <= 1000; i++) sort(V[i].begin(), V[i].end());
	for (i = 0; i <= 1000; i++) {
		if (i % 2) for (int j = 0; j < V[i].size(); j++) printf("%d ", V[i][j].second);
		else for (int j = (int)V[i].size() - 1; j >= 0; j--) printf("%d ", V[i][j].second);
	}
	return 0;
}
//*/