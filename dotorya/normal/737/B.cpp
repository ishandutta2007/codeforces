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
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
//#include <unordered_map>

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

int IT_MAX = 1<<19;
const int MOD = 100000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

vector <int> V;
char in[200050];

int main() {
	int N, A, B, K, i, j;
	scanf("%d %d %d %d", &N, &A, &B, &K);
	scanf("%s", in + 1);
	V.push_back(0);
	for (i = 1; i <= N; i++) if (in[i] == '1') V.push_back(i);
	V.push_back(N + 1);

	int s = 0;
	sort(V.begin(), V.end());
	for (i = 0; i + 1 < V.size(); i++) {
		int t = V[i + 1] - V[i] - 1;
		s += t / B;
	}

	printf("%d\n", s - A + 1);
	for (i = 0; i + 1 < V.size(); i++) {
		int st = V[i] + 1, en = V[i + 1] - 1;
		while (s >= A && en - st + 1 >= B) {
			printf("%d ", st + B - 1);
			st += B;
			s--;
		}
	}
	return !printf("\n");
}