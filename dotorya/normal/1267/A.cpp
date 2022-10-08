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
int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <ll> Vx;
ll val[400050];
ll mn[400050];

pair<ll, pll> in[200050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		ll t1, t2, t3;
		scanf("%lld %lld %lld", &t1, &t2, &t3);
		in[i].first = t3;
		in[i].second = pll(t1, t2 - t3 + 1);

		Vx.push_back(in[i].second.first);
		Vx.push_back(in[i].second.second);
	}
	sort(in + 1, in + N + 1);

	sort(all(Vx));
	Vx.erase(unique(all(Vx)), Vx.end());

	int X = Vx.size();
	set <int> Sx;
	for (i = 0; i < X; i++) Sx.insert(i);
	for (i = 0; i < X; i++) val[i] = LL_INF;
	for (i = 1; i <= N; i++) {
		int p1 = lower_bound(all(Vx), in[i].second.first) - Vx.begin();
		int p2 = lower_bound(all(Vx), in[i].second.second) - Vx.begin();

		while (!Sx.empty()) {
			auto it = Sx.lower_bound(p1);
			if (it != Sx.end() && *it < p2) {
				val[*it] = in[i].first;
				Sx.erase(it);
			}
			else break;
		}
	}

	mn[X] = LL_INF;
	for (i = X - 1; i >= 0; i--) mn[i] = min(mn[i+1], Vx[i] + val[i]);

	ll ans = 0;
	ll cur = Vx[0];
	for (i = 0; i <= X - 2; i++) {
		if (cur > Vx[i + 1]) continue;
		ll c = (Vx[i + 1] - cur) / val[i];
		ans += c;
		cur += val[i] * c;

		if (cur == Vx[i+1] || cur + val[i] > mn[i+1]) {
			cur = Vx[i + 1];
			continue;
		}
		else {
			ans++;
			cur += val[i];
		}
	}
	return !printf("%lld\n", ans);
}