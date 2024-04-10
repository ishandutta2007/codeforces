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
const db ERR = 1e-10;

vector <pair<int, pii>> Vq;
ll in[1000050];
void vpush(int st, int en, ll v) {
	if (st > en) return;
	if (st >= v) {
		Vq.emplace_back(st, pll(1, -v));
		Vq.emplace_back(en + 1, pll(-1, v));
	}
	else if (en <= v) {
		Vq.emplace_back(st, pll(-1, v));
		Vq.emplace_back(en + 1, pll(1, -v));
	}
	else {
		Vq.emplace_back(st, pll(-1, v));
		Vq.emplace_back(v, pll(2, -2 * v));
		Vq.emplace_back(en + 1, pll(-1, v));
	}
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%lld", &in[i]);
		in[i]--;
	}

	for (i = 0; i < N; i++) {
		vpush(0, N - i - 1, in[i] - i);
		vpush(N - i, N - 1, in[i] + N - i);
	}
	sort(all(Vq));
	
	ll ans = LL_INF, s1 = 0, s2 = 0, p = 0, aid = 0;
	for (i = 0; i < N; i++) {
		while (p < Vq.size()) {
			if (Vq[p].first != i) break;
			s1 += Vq[p].second.first, s2 += Vq[p].second.second;
			p++;
		}
		if (ans > i * s1 + s2) {
			aid = i;
			ans = i*s1 + s2;
		}
	}
	return !printf("%lld %lld\n", ans, aid);
}