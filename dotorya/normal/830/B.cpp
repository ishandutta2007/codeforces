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

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

int indt[300000];
void update(int p, int v) {
	p += IT_MAX - 1;
	indt[p] = v;
	for (p /= 2; p; p /= 2) indt[p] = indt[2 * p] + indt[2 * p + 1];
}
int getsum(int p1, int p2) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;
	int rv = 0;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv += indt[p1++];
		if (p2 % 2 == 0) rv += indt[p2--];
	}
	return rv;
}

vector <int> Vp[100050];
int in[100050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		Vp[in[i]].push_back(i);
	}

	for (i = 1; i <= N; i++) update(i, 1);
	
	ll ans = 0;
	int cur = 1;
	for (i = 1; i <= 100000; i++) {
		if (Vp[i].empty()) continue;
	
		for (j = 0; j < Vp[i].size(); j++) if (Vp[i][j] >= cur) break;
		
		int en = Vp[i].back();
		if (j) en = Vp[i][j - 1];
		if (cur <= en) ans += getsum(cur, en);
		else ans += getsum(cur, N) + getsum(1, en);
		cur = en + 1;
		if (cur == N + 1) cur = 1;
		for (auto it : Vp[i]) update(it, 0);
	}
	return !printf("%lld\n", ans);
}