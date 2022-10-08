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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <int> son[100050];
ll dep[100050];
ll S[100050];
ll A[100050];
int par[100050];

void DFS(int n) {
	if (dep[n] % 2 == 1) {
		ll mn = S[par[n]];
		ll mx = LL_INF;
		for (auto it : son[n]) mx = min(mx, S[it]);
		if (mn > mx) {
			printf("-1\n");
			exit(0);
		}

		if (son[n].empty()) S[n] = mn;
		else S[n] = mx;
	}
	for (auto it : son[n]) {
		dep[it] = dep[n] + 1;
		DFS(it);
	}
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 2; i <= N; i++) {
		int t;
		scanf("%d", &t);
		son[t].push_back(i);
		par[i] = t;
	}
	for (i = 1; i <= N; i++) scanf("%lld", &S[i]);
	
	DFS(1);

	ll ans = 0;
	for (i = 1; i <= N; i++) ans += S[i] - S[par[i]];
	return !printf("%lld\n", ans);
}