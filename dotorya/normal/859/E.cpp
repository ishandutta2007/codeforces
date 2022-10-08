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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int r[200050];
int ecnt[200050];
int vcnt[200050];
bool chk[200050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
vector <pii> Ve;
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= 2*N; i++) r[i] = i;
	for (i = 1; i <= N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		Ve.emplace_back(t1, t2);
		r[root(t1)] = root(t2);
	}

	for (i = 1; i <= 2 * N; i++) {
		vcnt[root(i)]++;
	}
	for (auto it : Ve) {
		if (it.first == it.second) chk[root(it.first)] = true;
		ecnt[root(it.first)]++;
	}

	ll ans = 1;
	for (i = 1; i <= 2 * N; i++) {
		if (root(i) != i) continue;
		if (ecnt[i] == 0) continue;

		if (vcnt[i] == ecnt[i]) {
			if (!chk[i]) ans = (ans * 2) % MOD;
		}
		else ans = (ans * vcnt[i]) % MOD;
	}
	return !printf("%lld\n", ans);
}