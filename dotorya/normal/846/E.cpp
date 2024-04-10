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

ll mymul(ll a, ll b) {
	bool c = false;
	if (a < 0) {
		a *= -1;
		c = true;
	}
	if (b < 0) {
		b *= -1;
		c = !c;
	}

	ll rv;
	if ((2 * LL_INF) / b < a) rv = 2 * LL_INF;
	else rv = min(a*b, 2 * LL_INF);
	if (c) rv *= -1;
	return rv;
}

vector <pll> son[100050];
ll B[100050];
ll A[100050];
ll in[100050];
ll par[100050][2];
void DFS(int n) {
	for (auto it : son[n]) DFS(it.second);

	if (in[n] < 0) {
		if (n == 1) {
			printf("NO\n");
			exit(0);
		}
		int t1 = par[n][0], t2 = par[n][1];
		in[t1] -= mymul(-in[n], t2);
		if (in[t1] < -LL_INF) {
			printf("NO\n");
			exit(0);
		}
	}
	else {
		int t1 = par[n][0], t2 = par[n][1];
		in[t1] += in[n];
	}
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", &B[i]);
	for (i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (i = 2; i <= N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		son[t1].emplace_back(t2, i);
		par[i][0] = t1, par[i][1] = t2;
	}
	for (i = 1; i <= N; i++) in[i] = B[i] - A[i];

	DFS(1);
	return !printf("YES\n");
}