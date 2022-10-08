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
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const db EPS = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

int in[100050];
int u[100050];
int val[100050];

ll cur = 0;
bool dchk[100050];
vector <int> conn[100050];
vector <int> son[100050];
int cnt[100050][2];
void DFS(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		son[n].push_back(it);
		val[it] = val[n] ^ u[it];
		DFS(it);
	}

	int x = u[n];
	cnt[n][val[n]] = 1;
	if (x == 1) cur++;
	for (auto it : son[n]) {
		cur += (ll)cnt[n][1 ^ x] * cnt[it][0];
		cur += (ll)cnt[n][0 ^ x] * cnt[it][1];
		cnt[n][0] += cnt[it][0];
		cnt[n][1] += cnt[it][1];
	}
}
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}

	ll ans = 0;
	for (i = 0; i < 20; i++) {
		for (j = 1; j <= N; j++) u[j] = !!(in[j] & (1 << i));
		for (j = 1; j <= N; j++) {
			dchk[j] = 0;
			cnt[j][0] = cnt[j][1] = 0;
			son[j].clear();
		}
		cur = 0;
		val[1] = u[1];
		DFS(1);
	//	printf("%lld\n", cur);
		ans += cur << (ll)i;
	}
	return !printf("%lld\n", ans);
}