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
const ll MOD = 31991;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int ans[105];
int in[105];
bool chk[105];
int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) ans[i] = -1;

	for (i = 1; i <= M; i++) scanf("%d", &in[i]);
	for (i = 1; i < M; i++) {
		int t = (in[i + 1] - in[i] + N) % N;
		if (t == 0) t = N;
		if (ans[in[i]] >= 0 && ans[in[i]] != t) return !printf("-1\n");
		ans[in[i]] = t;
	}

	for (i = 1; i <= N; i++) {
		if (ans[i] == -1) continue;
		if (chk[ans[i]]) return !printf("-1\n");
		chk[ans[i]] = true;
	}
	vector <int> Vu;
	for (i = 1; i <= N; i++) if (!chk[i]) Vu.push_back(i);
	for (i = 1; i <= N; i++) {
		if (ans[i] == -1) {
			ans[i] = Vu.back();
			Vu.pop_back();
		}
	}
	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	return !printf("\n");
}