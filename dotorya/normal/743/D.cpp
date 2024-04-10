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
const ll MOD = 10007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

const int NMX = 200000 + 50;
ll ans = -LL_INF;

ll in[NMX];
ll sum[NMX];
ll mx[NMX];
vector <int> conn[NMX];
vector <int> son[NMX];
bool dchk[NMX];

vector <ll> V[NMX];
void DFS(int n) {
	mx[n] = -LL_INF;
	dchk[n] = true;
	sum[n] = in[n];
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		DFS(it);
		sum[n] += sum[it];
		V[n].push_back(mx[it]);
		mx[n] = max(mx[n], mx[it]);
	}
	mx[n] = max(mx[n], sum[n]);
	sort(V[n].begin(), V[n].end());
	if (V[n].size() >= 2) ans = max(ans, V[n][V[n].size() - 2] + V[n][V[n].size() - 1]);
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	
	DFS(1);

	if (ans == -LL_INF) printf("Impossible\n");
	else printf("%lld\n", ans);
	return 0;
}