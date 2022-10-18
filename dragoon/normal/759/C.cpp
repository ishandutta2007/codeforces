#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

struct Node {
	int cnt_pop, cnt_push;
	int x;
};

Node node[100005 * 4];
int n;

void build(int at, int l, int r) {
	if (l == r) {
		node[at].cnt_pop = 0;
		node[at].cnt_push = 0;
		node[at].x = -1;
		return;
	}
	int m = (l + r) / 2;
	build(at * 2, l, m);
	build(at * 2 + 1, m + 1, r);
}

void push(int at, int l, int r, int pos, int x) {
	if (l == r) {
		node[at].cnt_pop = 0;
		node[at].cnt_push = 1;
		node[at].x = x;
		return;
	}
	int m = (l + r) / 2;
	if (pos <= m) push(at * 2, l, m, pos, x);
	else push(at * 2 + 1, m + 1, r, pos, x);

	if (node[at * 2].cnt_push <= node[at * 2 + 1].cnt_pop) {
		node[at].cnt_pop = node[at * 2].cnt_pop + (node[at * 2 + 1].cnt_pop - node[at * 2].cnt_push);
		node[at].cnt_push = node[at * 2 + 1].cnt_push;
	}
	else {
		node[at].cnt_pop = node[at * 2].cnt_pop;
		node[at].cnt_push = node[at * 2].cnt_push - node[at * 2 + 1].cnt_pop + node[at * 2 + 1].cnt_push;
	}
}

void pop(int at, int l, int r, int pos) {
	if (l == r) {
		node[at].cnt_pop = 1;
		node[at].cnt_push = 0;
		return;
	}
	int m = (l + r) / 2;
	if (pos <= m) pop(at * 2, l, m, pos);
	else pop(at * 2 + 1, m + 1, r, pos);

	if (node[at * 2].cnt_push <= node[at * 2 + 1].cnt_pop) {
		node[at].cnt_pop = node[at * 2].cnt_pop + (node[at * 2 + 1].cnt_pop - node[at * 2].cnt_push);
		node[at].cnt_push = node[at * 2 + 1].cnt_push;
	}
	else {
		node[at].cnt_pop = node[at * 2].cnt_pop;
		node[at].cnt_push = node[at * 2].cnt_push - node[at * 2 + 1].cnt_pop + node[at * 2 + 1].cnt_push;
	}
}

int query(int at, int l, int r, int npop) {
	if (node[at].cnt_push <= npop) return -1;
	if (l == r) return node[at].x;

	int m = (l + r) / 2;
	if (node[at * 2 + 1].cnt_push > npop) {
		return query(at * 2 + 1, m + 1, r, npop);
	}
	npop -= node[at * 2 + 1].cnt_push;
	npop += node[at * 2 + 1].cnt_pop;
	return query(at * 2, l, m, npop);
}

int main()
{
	scanf("%d", &n);
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		int p, t;
		scanf("%d %d", &p, &t);
		if (t == 0) {
			// pop
			pop(1, 1, n, p);
		}
		else {
			// push
			int x;
			scanf("%d", &x);
			push(1, 1, n, p, x);
		}
		int ans = query(1, 1, n, 0);
		printf("%d\n", ans);
	}


	return 0;
}