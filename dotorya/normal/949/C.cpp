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

int IT_MAX = 1 << 17;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first

vector <int> conn[100050];
vector <int> rconn[100050];

int in[100050];

bool dchk[100050];
int G[100050];
int gsz[100050];
vector <int> Vstk;
vector <int> Vl[100050];
void DFS1(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) if (!dchk[it]) DFS1(it);
	Vstk.push_back(n);
}
void DFS2(int n, int g) {
	G[n] = g;
	gsz[g]++;
	Vl[g].push_back(n);
	for (auto it : rconn[n]) if (!G[it]) DFS2(it, g);
}

bool vchk[100050];
int main() {
	int N, M, H, i, j, k;
	scanf("%d %d %d", &N, &M, &H);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);

		if ((in[t1] + 1) % H == in[t2]) {
			conn[t1].push_back(t2);
			rconn[t2].push_back(t1);
		}
		if ((in[t2] + 1) % H == in[t1]) {
			conn[t2].push_back(t1);
			rconn[t1].push_back(t2);
		}
	}
	
	for (i = 1; i <= N; i++) if (!dchk[i]) DFS1(i);

	int gc = 0;
	reverse(all(Vstk));
	for (auto it : Vstk) if (!G[it]) DFS2(it, ++gc);

	for (i = 1; i <= N; i++) for (auto it : conn[i]) if (G[i] != G[it]) vchk[G[i]] = true;

	int ans = INF, ap = -1;
	for (i = 1; i <= gc; i++) {
		if (vchk[i]) continue;
		if (ans > gsz[i]) {
			ans = gsz[i];
			ap = i;
		}
	}
	printf("%d\n", ans);
	sort(all(Vl[ap]));
	for (auto it : Vl[ap]) printf("%d ", it);
	return !printf("\n");
}