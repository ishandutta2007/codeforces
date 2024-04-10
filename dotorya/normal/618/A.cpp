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

int IT_MAX = 131072;
const ll MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

vector <int> V;
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		V.push_back(1);
		while (V.size() > 1) {
			if (V[V.size() - 2] == V[V.size() - 1]) {
				int t = V.back();
				V.pop_back();
				V.pop_back();
				V.push_back(t + 1);
			}
			else break;
		}
	}
	for (auto it : V) printf("%d ", it);
	printf("\n");
	return 0;
}