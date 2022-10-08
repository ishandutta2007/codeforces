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

vector <pll> Vl;
ll ch(ll x) {
	auto it = lower_bound(all(Vl), pll(x, -1));
	if (it != Vl.end() && it->first == x) return it->second;
	return -1;
}

vector <ll> Vin[25];
ll sum[25];

bool dp[65535];
pll rev[65535];

ll ans[25][2];
int getv(int S, ll v) {
	ll oS = S;
	ll ov = v;
	int bs = 1 << S;
	while (1) {
		v += sum[S];
		int p = ch(v);
		if (p == -1) return -1;
		if (bs & (1 << p)) {
			if (p == oS && v == ov) return bs;
			return -1;
		}
		bs |= (1 << p);
		S = p;
	}
}

vector <pair<int, pll>> Vu[25];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		int t1, t2;
		scanf("%d", &t1);
		while (t1--) {
			scanf("%d", &t2);
			Vin[i].push_back(t2);
			Vl.emplace_back(t2, i);
		}
		sort(all(Vin[i]));
	}
	sort(all(Vl));

	ll S = 0;
	for (i = 0; i < N; i++) for (auto it : Vin[i]) S += it;
	if (S % N) return !printf("No\n");

	dp[0] = true;
	for (i = 0; i < N; i++) {
		for (auto it : Vin[i]) sum[i] += it;
		sum[i] -= S / N;

		sum[i] *= -1;
	}

	for (i = 0; i < N; i++) {
		for (auto it : Vin[i]) {
			int bs = getv(i, it);
			if (bs != -1) Vu[i].emplace_back(bs, pll(i, it));
		}
	}

	for (i = 0; i + 1 < (1 << N); i++) {
		if (!dp[i]) continue;

		int p = 0;
		while (i & (1 << p)) p++;

		for (auto it : Vu[p]) {
			if (i & it.first) continue;
			dp[i | it.first] = true;
			rev[i | it.first] = it.second;
		}
	}

	if (!dp[(1 << N) - 1]) return !printf("No\n");

	int bs = (1 << N) - 1;
	while (bs) {
		pll u = rev[bs];

		vector <pll> Vo;
		Vo.push_back(u);
		while (1) {
			pll u2;
			u2.second = Vo.back().second + sum[Vo.back().first];
			u2.first = ch(u2.second);
			Vo.push_back(u2);
			if (Vo[0] == Vo.back()) break;
		}
		for (i = 0; i + 1 < Vo.size(); i++) {
			ans[Vo[i].first][0] = Vo[i].second;
			ans[Vo[i + 1].first][1] = Vo[i].first;
		}

		Vo.pop_back();
		for (auto it : Vo) bs ^= 1 << it.first;
	}

	printf("Yes\n");
	for (i = 0; i < N; i++) printf("%lld %lld\n", ans[i][0], ans[i][1] + 1);
	return 0;
}