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

map <ll, ll> Mx;
ll cur = 0;
void update(int p, int q) {
	auto it = Mx.lower_bound(p + 2);
	it--;
	Mx[p + 1] = it->second;

	int lst = p + 1;
	while (1) {
		auto it = Mx.lower_bound(lst);
		if (it == Mx.begin()) break;
		it--;
		if (it->second >= q + 1) break;
		
		auto it2 = it;
		it2++;
		cur -= (ll)(it2->first - it->first) * (q + 1 - it->second);
		it->second = q+1;
		if (it2->second == it->second) Mx.erase(it2);
		lst = it->first;
	}
}
pair<int, pii> in[500050];
int main() {
	int N, P, Q, R, i;
	scanf("%d %d %d %d", &N, &P, &Q, &R);
	for (i = 1; i <= N; i++) scanf("%d %d %d", &in[i].first, &in[i].second.first, &in[i].second.second);
	sort(in + 1, in + N + 1);

	Mx[1] = 1;
	Mx[Q + 1] = 0;
	cur = (ll)Q*R;

	for (i = 1; i <= N; i++) update(in[i].second.first, in[i].second.second);
	ll ans = 0;
	int p = N;

	for (i = P; i >= 1; i--) {
		while (p) {
			if (in[p].first < i) break;
			update(in[p].second.first, R);
			update(Q, in[p].second.second);
			p--;
		}
		ans += cur;
	}
	return !printf("%lld\n", ans);
}