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

int IT_MAX = 1 << 19;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll val[500050];

ll indt[2][1100000];
void update(int x, int p, ll v) {
	p += IT_MAX - 1;
	
	indt[x][p] = v;
	for (p /= 2; p; p /= 2) indt[x][p] = min(indt[x][2 * p], indt[x][2 * p + 1]);
}
ll getmn(int x, int p1, int p2) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;
	
	ll rv = LL_INF;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv = min(rv, indt[x][p1++]);
		if (p2 % 2 == 0) rv = min(rv, indt[x][p2--]);
	}
	return rv;
}

ll in[500050];
ll sum[500050];

ll cnt[500050];
int main() {
	int N, i;
	scanf("%d", &N);
	//N = 500000;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
		//in[i] = i - 1;
	}
	sort(in + 1, in + N + 1);
	reverse(in + 1, in + N + 1);

	ll S = 0;
	for (i = N; i >= 2; i--) {
		if (cnt[i]) {
			S -= cnt[i];
			cnt[i - 1] += cnt[i];
			cnt[i] = 0;
		}
		cnt[min((ll)i-1, in[i])]++;
		S += min((ll)i - 1, in[i]);
		val[i - 1] = S;
	}
	for (i = 1; i <= N; i++) sum[i] = sum[i - 1] + in[i];
	for (i = 1; i <= N; i++) {
		val[i] += (ll)i*(i - 1);
		val[i] -= sum[i];
	}

	for (i = 1; i <= N; i++) {
		update(0, i, val[i]);
		update(1, i, val[i] + i);
	}

	vector <ll> Va;
	ll p = N + 1;
	for (ll a = 0; a <= N; a++) {
		while (p > 1) {
			if (in[p - 1] >= a) break;

			val[p - 1] += in[p - 1] + min(p - 1, in[p - 1]);
			update(0, p - 1, val[p - 1]);
			update(1, p - 1, p - 1 + val[p - 1]);
			p--;
		}

		if (sum[N] % 2 != a % 2) continue;
		if (getmn(0, p, N) - a < 0) continue;
		if (getmn(0, a, p - 1) + a < 0) continue;
		if (getmn(1, 1, a - 1) < 0) continue;
		Va.push_back(a);
	}
	if (Va.empty()) return !printf("-1\n");

	for (auto it : Va) printf("%lld ", it);
	return !printf("\n");
}