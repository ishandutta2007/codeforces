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

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

vector <pii> Ve;
vector <int> conn[300050];
bool dchk[300050];
int rev[300050];
int main() {
	int N, K, D, i;
	scanf("%d %d %d", &N, &K, &D);
	for (i = 1; i <= K; i++) {
		int t;
		scanf("%d", &t);
		dchk[t] = true;
	}
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
		Ve.emplace_back(t1, t2);
	}
	
	vector <int> Vu;
	for (i = 1; i <= N; i++) {
		if (dchk[i]) {
			Vu.push_back(i);
			rev[i] = i;
		}
	}
	for (i = 0; i < Vu.size(); i++) {
		for (auto it : conn[Vu[i]]) {
			if (dchk[it]) continue;
			dchk[it] = true;
			rev[it] = rev[Vu[i]];
			Vu.push_back(it);
		}
	}
	
	vector <int> Va;
	for (i = 0; i < Ve.size(); i++) {
		int t1 = Ve[i].first, t2 = Ve[i].second;
		if (rev[t1] != rev[t2]) Va.push_back(i + 1);
	}
	printf("%d\n", (int)Va.size());
	for (auto it : Va) printf("%d ", it);
	return !printf("\n");
}