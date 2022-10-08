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

int IT_MAX = 1 << 19;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <int> Va;
vector <int> Vstk;

set <int> Sx;
int in[200050];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) Sx.insert(i);
	for (i = 1; i <= K; i++) scanf("%d", &in[i]);

	int cur = 0;
	for (i = 1; i <= N; i++) {	
		int t = in[i];
		if (i > K) {
			auto it = Sx.end();
			it--;
			if (!Vstk.empty()) {
				it = Sx.lower_bound(Vstk.back());
				if (it == Sx.begin()) return !printf("-1\n");
				it--;
			}
			t = *it;
		}
		if (!Vstk.empty() && Vstk.back() < t) return !printf("-1\n");
		Vstk.push_back(t);
		Sx.erase(t);
		while (!Vstk.empty()) {
			if (Vstk.back() != cur + 1) break;
			Vstk.pop_back();
			cur++;
		}
		Va.push_back(t);
	}
	for (auto it : Va) printf("%d ", it);
	return !printf("\n");
}