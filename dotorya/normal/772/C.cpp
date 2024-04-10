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
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)

ll gcd(ll a, ll b) {
	return (a == 0) ? b : gcd(b%a, a);
}

vector <int> Vl[200050];
bool chk[200050];

int rev[200050];
int dp[200050];

int mul_inv(int a, int b) {
	int t1 = a, t2 = b, t3;
	int v1 = 1, v2 = 0, v3;
	while (t2 != 1) {
		int x = t1 / t2;
		t3 = t1 - x*t2;
		v3 = v1 - x*v2;
		t1 = t2, t2 = t3;
		v1 = v2, v2 = v3;
	}
	return (v2 + b) % b;
}
int getv(int a, int b, int g) {
	int x = gcd(a, g);
	a /= x, b /= x, g /= x;
	return (ll)b * mul_inv(a, g) % g;
}
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	while (N--) {
		scanf("%d", &i);
		chk[i] = true;
	}
	for (i = 0; i < M; i++) {
		if (chk[i]) continue;
		Vl[gcd(i, M)].push_back(i);
	}

	for (i = 1; i <= M; i++) {
		dp[i] += Vl[i].size();
		for (j = i; j <= M; j += i) {
			if (dp[j] < dp[i]) {
				dp[j] = dp[i];
				rev[j] = i;
			}
		}
	}
	
	vector <int> Va;
	int t = M;
	while (t) {
		for (auto it : Vl[t]) Va.push_back(it);
		t = rev[t];
	}
	reverse(all(Va));

	printf("%d\n", (int)Va.size());
	t = 1;
	for (auto it : Va) {
		printf("%d ", getv(t, it, M));
		t = it;
	}
	return !printf("\n");
}