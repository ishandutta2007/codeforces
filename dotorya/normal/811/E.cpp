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

int N;
int in[15][100050];

int u[100050];

int r[45];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
class Node {
public:
	int n;
	int v[15][2];
	int st, en;
	Node() {
		n = 0;
		st = 0, en = 0;
		memset(v, 0, sizeof(v));
	}
	Node(int x) {
		int i, j;
		n = 0;
		st = x, en = x;
		
		int p = 0;
		for (i = 0; i < N; i++) {
			if (i + 1 == N || in[i + 1][x] != in[p][x]) {
				n++;
				for (j = p; j <= i; j++) v[j][0] = v[j][1] = n;
				p = i + 1;
			}
		}
	}
	Node operator + (const Node &l) const {
		int i;
		Node rv = Node();
		rv.st = st;
		rv.en = l.en;
		rv.n = n + l.n;
		for (i = 1; i <= 40; i++) r[i] = i;
		for (i = 0; i < N; i++) {
			if (in[i][en] != in[i][l.st]) continue;
			int t1 = v[i][1], t2 = l.v[i][0] + 20;
			if (root(t1) != root(t2)) rv.n--;
			r[root(t1)] = root(t2);
		}

		int x = 0;
		for (i = 1; i <= 40; i++) u[i] = 0;
		for (i = 0; i < N; i++) {
			int t = root(v[i][0]);
			if (!u[t]) u[t] = ++x;
			rv.v[i][0] = u[t];

			t = root(l.v[i][1] + 20);
			if (!u[t]) u[t] = ++x;
			rv.v[i][1] = u[t];
		}
		return rv;
	}
};

Node indt[300000];
vector <int> V1;
vector <int> V2;
int getv(int p1, int p2) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;

	V1.clear(), V2.clear();
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) V1.push_back(p1++);
		if (p2 % 2 == 0) V2.push_back(p2--);
	}
	reverse(all(V2));
	for (auto it : V2) V1.push_back(it);

	Node rv = indt[V1[0]];
	for (int i = 1; i < V1.size(); i++) rv = rv + indt[V1[i]];
	return rv.n;
}
int main() {
	int M, Q, i, j;
	scanf("%d %d %d", &N, &M, &Q);
	for (i = 0; i < N; i++) for (j = 1; j <= M; j++) scanf("%d", &in[i][j]);

	for (i = 1; i <= M; i++) indt[i + IT_MAX - 1] = Node(i);
	for (i = IT_MAX - 1; i >= 1; i--) indt[i] = indt[2 * i] + indt[2 * i + 1];

	while (Q--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		printf("%d\n", getv(t1, t2));
	}
	return 0;
}