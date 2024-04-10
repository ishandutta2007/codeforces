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

bool chk[1050];
vector <int> V;
int main() {
	int i, j, N;
	for (i = 2; i <= 1000; i++) {
		if (chk[i]) continue;
		for (j = 2 * i; j <= 1000; j += i) chk[j] = true;
	}

	scanf("%d", &N);
	int ans = 0;
	for (i = 2; i <= 1000; i++) {
		if (chk[i]) continue;
		int t = i;
		while (t <= N) {
			
			ans++;
			V.push_back(t);
			t *= i;
		}
	}
	printf("%d\n", ans);
	for (i = 0; i < V.size(); i++) printf("%d ", V[i]);
	return 0;
}
//*/