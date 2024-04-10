#include <stdio.h>
#include <algorithm>
#include <assert.h>
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
#define rep(i, n) for(int i=0;i<n;i++)
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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

vector <int> conn[300050];
int in[300050];
int u[300050];
int chk[300050];
int main() {
	int N, i, t1, t2;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		u[i] = in[i];
	}
	for (i = 1; i < N; i++) {
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	sort(u + 1, u + N + 1);
	if (N >= 2 && u[N - 1] == u[N]) {
		int c = 0;
		for (i = 1; i <= N; i++) {
			if (in[i] == u[N]) {
				c++;
				for (auto it : conn[i]) chk[it]++;
				chk[i]++;
			}
		}
		for (i = 1; i <= N; i++) if (chk[i] >= c) return !printf("%d\n", u[N] + 1);
		return !printf("%d\n", u[N] + 2);
	}

	int p = 0;
	for (i = 1; i <= N; i++) if (in[i] == u[N]) break;
	p = i;

	for (i = 1; i <= N; i++) chk[i] = 2;
	chk[p] = 0;
	for (auto it : conn[p]) chk[it] = 1;
	
	int ans = -INF;
	for (i = 1; i <= N; i++) ans = max(ans, in[i] + chk[i]);
	return !printf("%d\n", ans);
}