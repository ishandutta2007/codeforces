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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)

int in[505];
int u[505];
int main() {
	int N, i, j;
	ll K;
	scanf("%d %lld", &N, &K);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	K = min(K, 505ll);

	int c = 0;
	for (i = 1; i <= N; i++) u[i] = i;
	while (1) {
		if (in[u[1]] < in[u[2]]) {
			swap(u[1], u[2]);
			c = 0;
		}
		c++;
		if (c >= K) return !printf("%d\n", in[u[1]]);
		int t = u[2];
		for (i = 2; i < N; i++) u[i] = u[i + 1];
		u[N] = t;
	}
	return 0;
}