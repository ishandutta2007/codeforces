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
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

class datax {
public:
	ll a, b, h;
	datax() {
		*this = datax(0, 0, 0);
	}
	datax(ll a, ll b, ll h) : a(a), b(b), h(h) {}
};
datax in[100050];

ll indt[600000];
void update(int p, ll v) {
	p += IT_MAX;
	for (; p; p /= 2) indt[p] = max(indt[p], v);
}
ll getmx(int p1, int p2) {
	p1 += IT_MAX;
	p2 += IT_MAX;
	ll rv = 0;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv = max(rv, indt[p1++]);
		if (p2 % 2 == 0) rv = max(rv, indt[p2--]);
	}
	return rv;
}

vector <int> Vx;
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld %lld %lld", &in[i].a, &in[i].b, &in[i].h);
	sort(in + 1, in + N + 1, [](datax a, datax b) {
		if(a.b != b.b) return a.b < b.b;
		else return a.a < b.a;
	});
	
	for (i = 1; i <= N; i++) {
		Vx.push_back(in[i].a);
		Vx.push_back(in[i].b);
	}
	sort(all(Vx));
	Vx.erase(unique(all(Vx)), Vx.end());
	for (i = 1; i <= N; i++) {
		in[i].a = lower_bound(all(Vx), in[i].a) - Vx.begin();
		in[i].b = lower_bound(all(Vx), in[i].b) - Vx.begin();
	}
	
	ll ans = 0;
	for (i = N; i >= 1; i--) {
		ll v = getmx(0, in[i].b - 1);
		v += in[i].h;
		ans = max(ans, v);
		update(in[i].a, v);
	}
	return !printf("%lld\n", ans);
}