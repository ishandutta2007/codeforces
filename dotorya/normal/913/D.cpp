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

int IT_MAX = 1 << 16;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

pii in[200050];
int u[200050];

priority_queue <pii> Hx;
int s = 0;
int main() {
	int N, T, i, j;
	scanf("%d %d", &N, &T);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &in[i].first, &in[i].second);
		u[i] = i;
	}
	sort(u + 1, u + N + 1, [](int a, int b) {
		return in[a].first < in[b].first;
	});

	int p = N;
	for (i = N; i >= 1; i--) {
		while (p) {
			int t = u[p];
			if (in[t].first != i) break;
			Hx.emplace(in[t].second, t);
			s += in[t].second;
			p--;
		}
		while (Hx.size() > i) {
			s -= Hx.top().first;
			Hx.pop();
		}
		if (s <= T && Hx.size() == i) {
			printf("%d\n", i);
			printf("%d\n", i);
			vector <int> Va;
			while (!Hx.empty()) {
				Va.push_back(Hx.top().second);
				Hx.pop();
			}
			sort(all(Va));
			for (auto it : Va) printf("%d ", it);
			return !printf("\n");
		}
	}
	return !printf("0\n0\n\n");
}