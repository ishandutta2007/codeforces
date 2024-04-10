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

set <ll> Sa;
ll A[2050];
ll Asum[2050];
ll B[2050];
int main() {
	int N, K, i, j;
	scanf("%d %d", &K, &N);
	for (i = 1; i <= K; i++) scanf("%lld", &A[i]);
	for (i = 1; i <= K; i++) Asum[i] = Asum[i - 1] + A[i];
	for (i = 1; i <= N; i++) scanf("%lld", &B[i]);

	for (i = 1; i <= K; i++) {
		set <ll> Sx;
		ll v = B[1] - Asum[i];
		for (j = 1; j <= N; j++) Sx.insert(B[j]);
		for (j = 1; j <= K; j++) {
			v += A[j];
			if (Sx.count(v)) Sx.erase(v);
		}
		if (Sx.empty()) Sa.insert(B[1] - Asum[i]);
	}
	return !printf("%d\n", (int)Sa.size());
}