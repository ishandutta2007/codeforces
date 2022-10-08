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

int IT_MAX = 1 << 15;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int cnt[2000050];
ll sum[2000050];
ll sum2[2000050];
int main() {
	int N, i, j, t;
	ll X, Y;
	scanf("%d %lld %lld", &N, &X, &Y);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		cnt[t]++;
	}
	for (i = 1; i <= 2000000; i++) {
		sum[i] = sum[i - 1] + cnt[i];
		sum2[i] = sum2[i - 1] + (ll)i * cnt[i];
	}

	ll ans = LL_INF;
	for (i = 2; i <= 1000000; i++) {
		ll s = 0;
		for (j = 0;; j++) {
			int st = i*j + 1, en = i * (j + 1) - 1;
			int c = X / Y;

			int st2 = max(st, en - c + 1);
			s += ((ll)i * (j + 1) * (sum[en] - sum[st2 - 1]) - (sum2[en] - sum2[st2 - 1])) * Y;
			s += (sum[st2 - 1] - sum[st - 1]) * X;

			if (en >= 1000000) break;
		}
		ans = min(ans, s);
	}
	return !printf("%lld\n", ans);
}