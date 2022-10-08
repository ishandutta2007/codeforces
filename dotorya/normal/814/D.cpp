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

inline ll sq(ll a) {
	return a*a;
}

pair<ll, pll> in[1050];
vector <int> son[1050];
int dep[1050];
bool dchk[1050];
void DFS(int n) {
	dchk[n] = true;
	for (auto it : son[n]) {
		dep[it] = dep[n] + 1;
		DFS(it);
	}
}
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld %lld %lld", &in[i].second.first, &in[i].second.second, &in[i].first);
	sort(in + 1, in + N + 1);
	for (i = 1; i <= N; i++) {
		for (j = i + 1; j <= N; j++) {
			ll d1 = sq(in[j].first - in[i].first);
			ll d2 = sq(in[j].second.first - in[i].second.first) + sq(in[j].second.second - in[i].second.second);
			if (d1 >= d2) break;
		}
		if (j <= N) son[j].push_back(i);
	}

	for (i = N; i >= 1; i--) if (!dchk[i]) DFS(i);

	db ans = 0;
	for (i = 1; i <= N; i++) {
		if (!dep[i] || (dep[i] % 2)) ans += PI * sq(in[i].first);
		else ans -= PI * sq(in[i].first);
	}
	return !printf("%.20lf\n", ans);
}