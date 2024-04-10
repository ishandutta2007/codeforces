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

vector <pll> V1[100050];
vector <pll> V2[100050];
int main() {
	int N, M, K, i, j;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= M; i++) {
		int t1, t2, t3, t4;
		scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
		if (t3 == 0) V1[t2].emplace_back(t1, t4);
		else V2[t3].emplace_back(t1, t4);
	}
	
	ll inf = 10000000000000ll;
	vector <pll> Vq;
	for (i = 1; i <= N; i++) {
		if (V1[i].empty()) return !printf("-1\n");
		sort(all(V1[i]));
		for (j = 1; j < V1[i].size(); j++) V1[i][j].second = min(V1[i][j].second, V1[i][j - 1].second);
		
		ll prv = inf;
		for (j = 0; j < V1[i].size(); j++) {
			Vq.emplace_back(V1[i][j].first, V1[i][j].second - prv);
			prv = V1[i][j].second;
		}

		if (V2[i].empty()) return !printf("-1\n");
		sort(all(V2[i]));
		for (j = (int)V2[i].size() - 2; j >= 0; j--) V2[i][j].second = min(V2[i][j].second, V2[i][j + 1].second);

		for (j = 0; j < V2[i].size(); j++) {
			ll nxt = inf;
			if (j + 1 != V2[i].size()) nxt = V2[i][j + 1].second;
			
			Vq.emplace_back(V2[i][j].first - K, nxt - V2[i][j].second);
		}
	}

	ll cur = inf * N;
	for (i = 1; i <= N; i++) cur += V2[i][0].second;

	ll ans = cur;
	sort(all(Vq));
	for (i = 0; i < Vq.size(); i++) {
		cur += Vq[i].second;
		if (i + 1 == Vq.size() || Vq[i].first != Vq[i + 1].first) ans = min(ans, cur);
	}
	if (ans >= inf) ans = -1;
	return !printf("%lld\n", ans);
}