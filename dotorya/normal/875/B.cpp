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
//#include <unordered_map>  
//#include <unordered_set>  
#include <vector>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple<int, int, int> t3;
#define rep(i, n) for(int i=0;i<n;i++)

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-12;

class Node {
public:
	int v, mx;
	Node() {
		*this = Node(0, 0);
	}
	Node(int v, int mx) : v(v), mx(mx) {}
};
Node indt[1100000];
void propagate(int n) {
	int v = indt[n].v;
	indt[2 * n].v += v;
	indt[2 * n + 1].v += v;
	indt[2 * n].mx += v;
	indt[2 * n + 1].mx += v;
	indt[n].v = 0;
}
void update(int st, int en, int S, int E, int n, int v) {
	if (E < st || en < S) return;
	if (st <= S && E <= en) {
		indt[n].v += v;
		indt[n].mx += v;
		return;
	}
	propagate(n);

	int M = (S + E) / 2;
	update(st, en, S, M, 2 * n, v);
	update(st, en, M + 1, E, 2 * n + 1, v);
	indt[n].mx = max(indt[2 * n].mx, indt[2 * n + 1].mx);
}
int getmx(int st, int en, int S, int E, int n) {
	if (E < st || en < S) return -INF;
	if (st <= S && E <= en) return indt[n].mx;
	propagate(n);

	int M = (S + E) / 2;
	return max(getmx(st, en, S, M, 2 * n), getmx(st, en, M + 1, E, 2 * n + 1));
}

int main() {
	int N, i;
	scanf("%d", &N);

	printf("%d ", 1);
	for (i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		update(t, t, 1, IT_MAX, 1, -INF);
		update(t + 1, N, 1, IT_MAX, 1, 1);
		if(i != N) printf("%d ", getmx(1, N, 1, IT_MAX, 1) + 1);
		else printf("1 ");
	}
	return !printf("\n");
}