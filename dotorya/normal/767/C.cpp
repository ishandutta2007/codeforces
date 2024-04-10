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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)

ll val[1000050];
ll sum[1000050];
int lr[1000050][2];
vector <int> son[1000050];
int tus = 0;
void DFS(int n) {
	sum[n] = val[n];
	lr[n][0] = ++tus;
	for (auto it : son[n]) {
		DFS(it);
		sum[n] += sum[it];
	}
	lr[n][1] = tus;
}

vector <int> Vu1;
vector <int> Vu2;
int main() {
	int N, i, r = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		ll t1, t2;
		scanf("%lld %lld", &t1, &t2);
		if (t1) son[t1].push_back(i);
		else r = i;
		val[i] = t2;
	}
	DFS(r);
	if (sum[r] % 3) return !printf("-1\n");

	for (i = 1; i <= N; i++) {
		if (r == i) continue;
		if (sum[r] / 3 == sum[i]) Vu1.push_back(i);
		if (sum[r] * 2 / 3 == sum[i]) Vu2.push_back(i);
	}
	sort(all(Vu1), [](int a, int b) {
		return lr[a][0] < lr[b][0];
	});
	sort(all(Vu2), [](int a, int b) {
		return lr[a][0] < lr[b][0];
	});

	if (sum[r] == 0) {
		if (Vu1.size() < 2) return !printf("-1\n");
		return !printf("%d %d\n", Vu1[0], Vu1[1]);
	}

	for (auto it : Vu1) {
		int st = 0, en = (int)Vu1.size() - 1, mi, rv = Vu1.size();
		while (st <= en) {
			mi = (st + en) / 2;
			if (lr[Vu1[mi]][0] > lr[it][1]) {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}
		if (rv == Vu1.size()) continue;
		return !printf("%d %d\n", it, Vu1[rv]);
	}
	for (auto it : Vu2) {
		int st = 0, en = (int)Vu1.size() - 1, mi, rv = Vu1.size();
		while (st <= en) {
			mi = (st + en) / 2;
			if (lr[Vu1[mi]][0] > lr[it][0]) {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}
		if (rv == Vu1.size() || lr[Vu1[rv]][0] > lr[it][1]) continue;
		return !printf("%d %d\n", it, Vu1[rv]);
	}
	return !printf("-1\n");
}