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
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

class Node {
public:
	vector <int> Vx;
	vector <ll> bit;
	int it_max;
	Node() {
		Vx.clear();
		bit.clear();
	}
	void update(int p, int v) {
		p = lower_bound(all(Vx), p) - Vx.begin() + 1;
		for (; p <= it_max; p += p & (-p)) bit[p] += v;
	}
	ll getsum(int x) {
		x = lower_bound(all(Vx), x + 1) - Vx.begin();

		ll rv = 0;
		for (; x; x -= x & (-x)) rv += bit[x];
		return rv;
	}
};
Node indt[300000];
int val[300000];
void update(int p, int v) {
	if (v == INF) v = 0;
	if (val[p] != 0) for (int i = IT_MAX + p - 1; i; i /= 2) indt[i].update(val[p], p - val[p]);
	if (v != 0) for (int i = IT_MAX + p - 1; i; i /= 2) indt[i].update(v, v - p);
	val[p] = v;
}
ll getsum(int p1, int p2) {
	int op1 = p1, op2 = p2;
	p1 += IT_MAX - 1, p2 += IT_MAX - 1;
	ll rv = 0;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv += indt[p1++].getsum(op2);
		if (p2 % 2 == 0) rv += indt[p2--].getsum(op2);
	}
	return rv;
}

int OA[100050];
int A[100050];
set <int> Sp[100050];
int getnxt(int p) {
	auto it = Sp[A[p]].lower_bound(p + 1);
	if (it == Sp[A[p]].end()) return INF;
	else return *it;
}
int Qu[100050][3];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		OA[i] = A[i];
	}
	for (i = 1; i <= M; i++) scanf("%d %d %d", &Qu[i][0], &Qu[i][1], &Qu[i][2]);

	for (i = 1; i <= N; i++) Sp[A[i]].insert(i);
	for (i = 1; i <= N; i++) {
		int p = getnxt(i);
		if (p == INF) continue;
		for (j = IT_MAX + i - 1; j >= 1; j /= 2) indt[j].Vx.push_back(p);
	}
	for (i = 1; i <= M; i++) {
		if (Qu[i][0] == 2) continue;
		int p = Qu[i][1], x = Qu[i][2];
		
		auto it = Sp[A[p]].lower_bound(p);
		if (it != Sp[A[p]].begin()) {
			auto it2 = it;
			it2++;
			it--;
			if (it2 != Sp[A[p]].end()) {
				int y = *it, z = *it2;
				for (j = IT_MAX + y - 1; j >= 1; j /= 2) indt[j].Vx.push_back(z);
			}
		}
		Sp[A[p]].erase(p);
		A[p] = x;
		Sp[A[p]].insert(p);

		it = Sp[A[p]].lower_bound(p);
		if (it != Sp[A[p]].begin()) {
			it--;
			int y = *it;
			for (j = IT_MAX + y - 1; j >= 1; j /= 2) indt[j].Vx.push_back(p);
		}
		int p2 = getnxt(p);
		if (p2 == INF) continue;
		for (j = IT_MAX + p - 1; j >= 1; j /= 2) indt[j].Vx.push_back(p2);
	}
	for (i = 1; i < IT_MAX * 2; i++) {
		sort(all(indt[i].Vx));
		indt[i].Vx.erase(unique(all(indt[i].Vx)), indt[i].Vx.end());
		
		int x;
		for (x = 2; x < indt[i].Vx.size(); x *= 2);
		indt[i].it_max = x;
		indt[i].bit.resize(x + 1);
	}

	for (i = 1; i <= N; i++) A[i] = OA[i];
	for (i = 1; i <= N; i++) Sp[i].clear();
	for (i = 1; i <= N; i++) Sp[A[i]].insert(i);

	for (i = 1; i <= N; i++) {
		int p = getnxt(i);
		if (p != INF) update(i, p);
	}
	for (i = 1; i <= M; i++) {
		int t1 = Qu[i][0], t2 = Qu[i][1], t3 = Qu[i][2];
		if (t1 == 1) {
			int p = t2, x = t3;

			auto it = Sp[A[p]].lower_bound(p);
			if (it != Sp[A[p]].begin()) {
				int v = INF;
				auto it2 = it;
				it2++;
				it--;
				if (it2 != Sp[A[p]].end()) v = *it2;
				update(*it, v);
			}
			Sp[A[p]].erase(p);
			A[p] = x;
			Sp[A[p]].insert(p);

			it = Sp[A[p]].lower_bound(p);
			if (it != Sp[A[p]].begin()) {
				it--;
				update(*it, p);
			}
			update(p, getnxt(p));
		}
		else printf("%lld\n", getsum(t2, t3));
	}
	return 0;
}