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

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1E-11;

const int NMX = 500000 + 50;
vector <int> son[NMX];
int dep[NMX];
int in[NMX];
void DFS(int n) {
	for (auto it : son[n]) {
		dep[it] = dep[n] + 1;
		DFS(it);
	}
}

int cnt[2][10000050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 2; i <= N; i++) {
		scanf("%d", &j);
		son[j].push_back(i);
	}
	DFS(1);

	int mx = 0;

	int c[2] = { 0,0 };
	for (i = 1; i <= N; i++) {
		cnt[dep[i] % 2][in[i]]++;
		c[dep[i] % 2]++;
		mx = max(mx, dep[i]);
	}

	ll s = 0;
	for (i = 1; i <= N; i++) if (mx % 2 == dep[i] % 2) s ^= in[i];

	ll ans = 0;
	for (i = 1; i <= 10000000; i++) {
		int v = i^s;
		if (v > 10000000) continue;
		ans += (ll)cnt[0][i] * cnt[1][v];
	}
	if (!s) {
		ans += (ll)c[0] * (c[0] - 1) / 2;
		ans += (ll)c[1] * (c[1] - 1) / 2;
	}
	return !printf("%lld\n", ans);
}