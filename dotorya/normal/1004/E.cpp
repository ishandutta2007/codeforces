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

vector <pll> conn[100050];
ll dis[100050];
int rev[100050];
bool dchk[100050];
void DFS1(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		if (dchk[it.second]) continue;
		dis[it.second] = dis[n] + it.first;
		rev[it.second] = n;
		DFS1(it.second);
	}
}

ll mx_tus;
void DFS2(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		if (dchk[it.second]) continue;
		dis[it.second] = dis[n] + it.first;
		mx_tus = max(mx_tus, dis[it.second]);
		DFS2(it.second);
	}
}

ll sum[100050];
ll dp1[100050];
ll dp2[100050];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	if (N == 1) return !printf("0\n");
	for (i = 1; i < N; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		conn[t1].emplace_back(t3, t2);
		conn[t2].emplace_back(t3, t1);
	}
	DFS1(1);

	int r1 = 1;
	for (i = 2; i <= N; i++) if (dis[r1] < dis[i]) r1 = i;
	memset(dis, 0, sizeof(dis));
	memset(dchk, 0, sizeof(dchk));
	DFS1(r1);

	int r2 = 1;
	for (i = 2; i <= N; i++) if (dis[r2] < dis[i]) r2 = i;

	vector <int> Vl;
	vector <ll> Vd;
	vector <ll> Vv;
	Vl.push_back(r2);
	while (r2 != r1) {
		Vd.push_back(dis[r2] - dis[rev[r2]]);
		r2 = rev[r2];
		Vl.push_back(r2);
	}

	memset(dis, 0, sizeof(dis));
	memset(dchk, 0, sizeof(dchk));
	for (auto it : Vl) dchk[it] = true;
	for (auto it : Vl) {
		mx_tus = 0;
		dis[it] = 0;
		DFS2(it);
		Vv.push_back(mx_tus);
	}

	N = Vl.size();
	K = min(N, K);

	sum[0] = Vd[0];
	for (i = 1; i <= N - 2; i++) sum[i] = sum[i - 1] + Vd[i];

	dp1[0] = Vv[0];
	for (i = 1; i <= N - 1; i++) dp1[i] = max(dp1[i - 1] + Vd[i - 1], Vv[i]);

	dp2[N - 1] = Vv[N - 1];
	for (i = N - 2; i >= 0; i--) dp2[i] = max(dp2[i + 1] + Vd[i], Vv[i]);

	ll ans = LL_INF;
	ll tmx = 0;
	for (auto it : Vv) tmx = max(tmx, it);
	for (i = 0; i + K - 1 < N; i++) {
		ll tot = max(dp1[i], dp2[i + K - 1]);
		tot = max(tot, tmx);
		ans = min(ans, tot);
	}
	return !printf("%lld\n", ans);
}