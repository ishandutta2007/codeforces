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
const db ERR = 1e-10;
#define szz(x) (int)(x).size()

int cnt[10050];

int cnt1[17000];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		scanf("%d", &j);
		cnt[j]++;
	}
	for (i = 0; i < 17000; i++) for (j = 0; j < 16; j++) if (i & (1 << j)) cnt1[i]++;
	
	ll ans = 0;
	for (i = 0; i <= 10000; i++) {
		for (j = i + 1; j <= 10000; j++) {
			if (cnt1[i^j] == K) ans += (ll)cnt[i] * cnt[j];
		}
		if (K == 0) ans += (ll)cnt[i] * (cnt[i] - 1) / 2;
	}
	return !printf("%lld\n", ans);
}