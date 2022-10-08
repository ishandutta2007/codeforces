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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

pii operator + (pii a, pii b) {
	return pii(a.first + b.first, a.second + b.second);
}
class Node {
public:
	int v;
	pii c;
	Node() {
		v = 0;
		c = pii(0, 0);
	}
};
Node indt[600000];
void propagate(int n) {
	if (indt[n].v) {
		swap(indt[2 * n].c.first, indt[2 * n].c.second);
		indt[2 * n].v = !indt[2 * n].v;
		swap(indt[2 * n + 1].c.first, indt[2 * n + 1].c.second);
		indt[2 * n + 1].v = !indt[2 * n + 1].v;
		indt[n].v = false;
	}
}
void update(int st, int en, int S, int E, int n) {
	if (en < S || E < st) return;
	if (st <= S && E <= en) {
		indt[n].v = !indt[n].v;
		swap(indt[n].c.first, indt[n].c.second);
		return;
	}
	propagate(n);

	int M = (S + E) / 2;
	update(st, en, S, M, 2 * n);
	update(st, en, M + 1, E, 2 * n + 1);
	indt[n].c = indt[2 * n].c + indt[2 * n + 1].c;
}
int getsum(int st, int en, int S, int E, int n) {
	if (en < S || E < st) return 0;
	if (st <= S && E <= en) return indt[n].c.second;
	propagate(n);

	int M = (S + E) / 2;
	return getsum(st, en, S, M, 2 * n) + getsum(st, en, M + 1, E, 2 * n+1);
}

vector <int> son[200050];
int lr[200050][2];
int tus = 0;
void DFS(int n) {
	lr[n][0] = ++tus;
	for (auto it : son[n]) DFS(it);
	lr[n][1] = tus;
}

int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 2; i <= N; i++) {
		int t;
		scanf("%d", &t);
		son[t].push_back(i);
	}
	DFS(1);
	for (i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		if (t) indt[IT_MAX + lr[i][0] - 1].c = pii(0, 1);
		else indt[IT_MAX + lr[i][0] - 1].c = pii(1, 0);
	}
	for (i = IT_MAX - 1; i >= 0; i--) indt[i].c = indt[2 * i].c + indt[2 * i + 1].c;
//	printf("%d\n", getsum(2, 2, 1, IT_MAX, 1));

	int Q;
	scanf("%d", &Q);
	while (Q--) {
		char c[10];
		int t;
		scanf("%s %d", c, &t);
		if (c[0] == 'p') update(lr[t][0], lr[t][1], 1, IT_MAX, 1);
		else printf("%d\n", getsum(lr[t][0], lr[t][1], 1, IT_MAX, 1));
	}
	return 0;
}