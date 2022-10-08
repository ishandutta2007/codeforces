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
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

vector <int> conn[100050];
vector <int> rconn[100050];

vector <int> conn2[100050];
int inc[100050];

bool dchk[100050];
vector <int> Vu;
int main() {
	int N, K, i, t1, t2;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= K; i++) {
		scanf("%d", &t1);
		Vu.push_back(t1);
		dchk[t1] = true;
	}
	for (i = 1; i <= N; i++) {
		scanf("%d", &t1);
		while (t1--) {
			scanf("%d", &t2);
			conn[t2].push_back(i);
			rconn[i].push_back(t2);
		}
	}
	for (i = 0; i < Vu.size(); i++) {
		for (auto it : rconn[Vu[i]]) {
			if (dchk[it]) continue;
			dchk[it] = true;
			Vu.push_back(it);
		}
	}
	
	for (i = 1; i <= N; i++) {
		for (auto it : conn[i]) {
			if (!dchk[i] || !dchk[it]) continue;
			conn2[i].push_back(it);
			inc[it]++;
		}
	}
	for (i = 1; i <= N; i++) if (!dchk[i]) inc[i] = INF;

	int c = Vu.size();
	//printf("%d\n", (int)Vu.size());
	Vu.clear();
	for (i = 1; i <= N; i++) if (!inc[i]) Vu.push_back(i);
	for (i = 0; i < Vu.size(); i++) {
		//printf("%d ", Vu[i]);
		for (auto it : conn2[Vu[i]]) {
			inc[it]--;
			if (!inc[it]) Vu.push_back(it);
		}
	}

	if (c != Vu.size()) printf("-1");
	else {
		printf("%d\n", c);
		for (auto it : Vu) printf("%d ", it);
	}
	return !printf("\n");
}