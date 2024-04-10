#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define all(x) (x).begin(), (x).end()

const int INF = 0x3f3f3f3f;
const int MAXN = 10000;

typedef long long ll;



int main() {
	ll L, R, X, Y, i, j;
	scanf("%lld %lld %lld %lld", &L, &R, &X, &Y);
	if (Y%X) return !printf("0\n");

	ll t = Y / X, t2;
	vector <ll> Vl;
	for (i = 2; i * i <= t; i++) {
		if (t % i) continue;
		
		ll v = 1;
		while (t % i == 0) {
			v *= i;
			t /= i;
		}
		Vl.push_back(v);
	}
	if (t != 1) Vl.push_back(t);

	ll ans = 0;
	for (i = 0; i < (1 << Vl.size()); i++) {
		ll v1 = X, v2 = X;
		for (j = 0; j < Vl.size(); j++) {
			if (i & (1 << j)) v1 *= Vl[j];
			else v2 *= Vl[j];
		}
		if (L <= v1 && v1 <= R && L <= v2 && v2 <= R) ans++;
	}
	return !printf("%lld\n", ans);
}