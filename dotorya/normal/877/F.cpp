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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first


int u1[100050];
int in[100050];
ll sum[100050];
vector <ll> Vx;
int prv[100050];
int nxt[100050];
int getpos(ll v) {
	int x = lower_bound(all(Vx), v) - Vx.begin();
	if (x == Vx.size() || Vx[x] != v) return -1;
	return x;
}

int st = 1, en = 1, K;
ll cur = 0;
int cnt1[100050];
int cnt2[100050];
void update(int s, int e) {
	while (st > s) {
		st--;
		cnt1[sum[st - 1]]++;
		cnt2[sum[st]]++;
		if (nxt[sum[st-1]] != -1) cur += cnt2[nxt[sum[st-1]]];
	}
	while (en < e) {
		en++;
		cnt1[sum[en - 1]]++;
		cnt2[sum[en]]++;
		if (prv[sum[en]] != -1) cur += cnt1[prv[sum[en]]];
	}
	while (st < s) {
		if (nxt[sum[st - 1]] != -1) cur -= cnt2[nxt[sum[st-1]]];
		cnt1[sum[st - 1]]--;
		cnt2[sum[st]]--;
		st++;
	}
	while (en > e) {
		if (prv[sum[en]] != -1) cur -= cnt1[prv[sum[en]]];
		cnt1[sum[en - 1]]--;
		cnt2[sum[en]]--;
		en--;
	}
}

ll ans[100050];
int main() {
	int N, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%d", &u1[i]);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		if (u1[i] == 2) in[i] *= -1;
		sum[i] = sum[i - 1] + in[i];
	}
	for (i = 0; i <= N; i++) Vx.push_back(sum[i]);
	sort(all(Vx));
	Vx.erase(unique(all(Vx)), Vx.end());
	for (i = 0; i <= N; i++) sum[i] = lower_bound(all(Vx), sum[i]) - Vx.begin();
	
	for (i = 0; i < Vx.size(); i++) {
		prv[i] = getpos(Vx[i] - K);
		nxt[i] = getpos(Vx[i] + K);
	}

	if (in[1] == K) cur++;
	cnt1[sum[0]]++;
	cnt2[sum[1]]++;

	int Q;
	scanf("%d", &Q);
	vector <pair<pii, int>> Vq;
	for (int i = 1; i <= Q; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		Vq.emplace_back(pii(t1, t2), i);
	}
	sort(all(Vq), [](auto a, auto b) {
		pii u1 = a.first, u2 = b.first;
		if (u1.first / 400 != u2.first / 400) return u1.first / 400 < u2.first / 400;
		else return u1.second < u2.second;
	});
	for (auto it : Vq) {
		update(it.first.first, it.first.second);
		ans[it.second] = cur;
	}
	for (i = 1; i <= Q; i++) printf("%lld\n", ans[i]);
	return 0;
}