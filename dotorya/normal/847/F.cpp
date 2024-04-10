#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

pii in[105];

pii u[105];
int ans[105];

int sn[105];
int main() {
	int N, K, M, A, i, j, k;
	scanf("%d %d %d %d", &N, &K, &M, &A);
	for (i = 1; i <= A; i++) {
		int t;
		scanf("%d", &t);
		in[t].first++;
		in[t].second = -i;
	}

	for (i = 1; i <= N; i++) ans[i] = 3;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) u[j] = in[j];
		if (M != A) u[i] = pii(in[i].first + M - A, -M);

		if (u[i].first == 0) continue;

		int c = 1;
		for (j = 1; j <= N; j++) if (u[i] < u[j]) c++;
		if (c <= K) ans[i] = 2;
	}

	for (i = 1; i <= N; i++) sn[i] = i;
	sort(sn + 1, sn + N + 1, [](int a, int b) {
		return in[a] > in[b];
	});

	for (i = 1; i <= K; i++) {
		int t = sn[i];
		if (in[t].first == 0) continue;
		if (N == K) {
			if (in[t].first != 0) ans[t] = 1;
			continue;
		}

		int c = 0;
		for (j = i + 1; j <= K + 1; j++) c += (in[t].first - in[sn[j]].first + 1);
		if (c > M - A) ans[t] = 1;
	}
	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	return !printf("\n");
}