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

ll cnt[300050];
void aa(int lvl) {
	if (cnt[lvl] == 0) return;
	printf("(");
	aa(lvl + 1);
	printf(")");
	for (int i = 2; i <= cnt[lvl]; i++) printf("()");
}
int main() {
	ll N, K, i;
	scanf("%lld %lld", &N, &K);

	if (K > N*(N - 1) / 2) return !printf("Impossible\n");

	ll v = 0;
	for (v = 1; v * (v + 1) / 2 <= K; v++);
	v--;

	for (i = 0; i <= v; i++) cnt[i] = 1;

	K -= v * (v + 1) / 2;
	if (K != 0) {
		ll t1 = K, t2 = N - v - 1;
		cnt[t1 / t2] += t2 - t1 % t2;
		cnt[t1 / t2 + 1] += t1 % t2;
	}
	else cnt[0] += N - v - 1;

	aa(0);
	return !printf("\n");
}