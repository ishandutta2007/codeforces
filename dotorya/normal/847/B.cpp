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
const db ERR = 1e-10;

int indt[600000];
void update(int p, int v) {
	p += IT_MAX - 1;
	indt[p] = v;
	for (p /= 2; p; p /= 2) indt[p] = max(indt[2 * p], indt[2 * p + 1]);
}
int getmx(int p1, int p2) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;
	int rv = -INF;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv = max(rv, indt[p1++]);
		if (p2 % 2 == 0) rv = max(rv, indt[p2--]);
	}
	return rv;
}


int in[200050];
bool chk[200050];

int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 1; i <= N; i++) update(i, in[i]);

	while (1) {
		vector <int> Va;
		int prv = 0, pval = -1;
		while (1) {
			int st = prv + 1, en = N, mi, rv = N + 1;
			while (st <= en) {
				mi = (st + en) / 2;
				if (getmx(prv + 1, mi) > pval) {
					rv = mi;
					en = mi - 1;
				}
				else st = mi + 1;
			}
			if (rv == N + 1) break;
			Va.push_back(in[rv]);

			prv = rv, pval = in[rv];
			update(rv, -INF);
		}
		if (Va.empty()) break;
		for (auto it : Va) printf("%d ", it);
		printf("\n");
	}
	return 0;
}