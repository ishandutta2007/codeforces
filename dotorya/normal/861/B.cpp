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

int in[105][2];

int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	N--;
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &in[i][0], &in[i][1]);
		in[i][0]--, in[i][1]--;
	}

	int ans = -1;
	for (i = 1; i <= 10000; i++) {
		for (j = 1; j <= M; j++) if (in[j][0] / i != in[j][1]) break;
		if (j > M) {
			int t = N / i;
			if (ans == -1) ans = t;
			if (ans != t) return !printf("-1\n");
		}
	}
	return !printf("%d\n", ans + 1);
}