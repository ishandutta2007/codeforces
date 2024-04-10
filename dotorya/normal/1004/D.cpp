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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int cnt[1000050];
int tcnt[1000050];
int main() {
	int T, i, j;
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}

	if (cnt[0] != 1) return !printf("-1\n");

	int mx = 0;
	for (i = 0; i <= T; i++) if (cnt[i]) mx = i;
	if (mx == 0) {
		if (T == 1) return !printf("1 1\n1 1\n");
		return !printf("-1\n");
	}

	ll sum = 0;
	for (i = 0; i <= T; i++) sum += (ll)i * cnt[i];

	for (ll n = 1; n * n <= T; n++) {
		if (T%n) continue;
		ll m = T / n;

		for (ll x = 1; x <= (n + 1) / 2; x++) {
			ll y = n + m - x - mx;
			if (y < 1 || y > (m + 1) / 2) continue;

			ll v = m * (x*x - (n + 1)*x + n*(n + 1) / 2) + n * (y*y - (m + 1)*y + m*(m + 1) / 2);
			if (v != sum) continue;

			memset(tcnt, 0, sizeof(tcnt));
			for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) tcnt[abs(x - i) + abs(y - j)]++;
			for (i = 0; i <= T; i++) if (cnt[i] != tcnt[i]) break;
			if (i > T) return !printf("%lld %lld\n%lld %lld\n", n, m, x, y);
		}
	}
	return !printf("-1\n");
}