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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-12;

pii indt[600000];
pii operator + (pii a, pii b) {
	return pii(min(a.first, b.first), max(a.second, b.second));
}
void update(int p, int v) {
	p += IT_MAX;
	indt[p] = pii(v, v);
	for (p /= 2; p; p /= 2) indt[p] = indt[2 * p] + indt[2 * p + 1];
}
pii getsum(int p1, int p2) {
	p1 += IT_MAX;
	p2 += IT_MAX;
	pii rv = pii(INF, -INF);
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv = rv + indt[p1++];
		if (p2 % 2 == 0) rv = rv + indt[p2--];
	}
	return rv;
}
int in[100050];

int dis[100050];
bool isValid(int b, int d, pii u) {
	return b - u.first <= d && u.second - b <= d;
}
int getmx(int a, int b, int N, int d) {
	int s = a + 1, i;
	for (i = IT_MAX + s; i;) {
		if (isValid(b, d, indt[i])) {
			if (i % 2 == 0) i++;
			else if ((i & (i/2+1)) >= (i/2+1)) return INF;
			else i = i / 2 + 1;
		}
		else break;
	}
	for (; i < IT_MAX;) {
		if (isValid(b, d, indt[2 * i])) i = 2 * i + 1;
		else i = 2 * i;
	}
	return i - IT_MAX - 1;
}
int main() {
	srand(time(0));
	int N, s1, s2, i;
	scanf("%d %d %d", &N, &s1, &s2);
	for (i = 1; i <= 2 * IT_MAX; i++) indt[i] = pii(INF, -INF);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
	//	in[i] = rand();
	}
	for (i = 1; i <= N; i++) update(i, in[i]);

	int st = abs(s2 - s1), en = INF, mi, rv = en + 1;
	while (st <= en) {
		mi = (st + en) / 2;

		int S = max(getmx(0, s1, N, mi), getmx(0, s2, N, mi));
		S = min(S, N);
		int p = 0;
		for (i = 1; i <= S; i++) p = max(p, getmx(i, in[i], N, mi));
		for (i = S+1; i <= N; i++) {
			if (S == 0) break;
			if (abs(in[i] - in[i - 1]) <= mi) {
				p = max(p, getmx(i, in[i], N, mi));
				continue;
			}
			if (p < i) break;
			p = max(p, getmx(i, in[i], N, mi));
		}
		if (i > N) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	return !printf("%d\n", rv);
}