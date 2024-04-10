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

ll A[100050];
ll B[100050];
ll Bsum[100050];

set <ll> Su;
void printans(ll s) {
	auto it = Su.lower_bound(s);

	ll rv = LL_INF;
	if (it != Su.end()) rv = *it - s;
	if (it != Su.begin()) {
		it--;
		rv = min(rv, s - *it);
	}
	printf("%lld\n", rv);
}
int main() {
	int N, M, Q, i;
	scanf("%d %d %d", &N, &M, &Q);
	for (i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (i = 1; i <= M; i++) scanf("%lld", &B[i]);
	
	Bsum[M] = B[M];
	for (i = M - 1; i >= 1; i--) {
		Bsum[i] = B[i] - Bsum[i + 1];
		if (i + N - 1 < M) {
			if ((N+1) % 2 == 1) Bsum[i] -= B[i + N];
			else Bsum[i] += B[i + N];
		}
	}
	for (i = 1; i + N - 1 <= M; i++) Su.insert(Bsum[i]);

	ll ans = 0;
	
	ll s = 0;
	for (i = 1; i <= N; i++) {
		if (i % 2 == 1) s += A[i];
		else s -= A[i];
	}

	printans(s);
	while (Q--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		if (t1 % 2 != t2 % 2);
		else if (t1 % 2 == 0) s -= t3;
		else s += t3;
		printans(s);
	}
	return 0;
}