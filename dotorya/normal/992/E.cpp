#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int IT_MAX = 1 << 18;
const int INF = 0x3f3f3f3f;
const int MAXN = 10000;
const int MOD = 1000000007;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

int N;
ll bit[300050];
ll in[300050];
void update(int p, ll v) {
	ll dv = v - in[p];
	in[p] = v;
	for (; p <= IT_MAX; p += p & (-p)) bit[p] += dv;
}
ll getsum(int p) {
	ll rv = 0;
	for (; p; p -= p & (-p)) rv += bit[p];
	return rv;
}
int largerpos(ll v) {
	if (bit[IT_MAX] <= v) return INF;
	
	ll p = 0;
	ll s = 0;
	for (int i = 17; i >= 0; i--) {
		if (s + bit[p + (1 << i)] <= v) {
			s += bit[p + (1 << i)];
			p |= (1 << i);
		}
	}
	return p + 1;
}

int main() {
	int N, Q, i, j;
	scanf("%d %d", &N, &Q);
	for (i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		update(i, t);
	}
	while (Q--) {
		int p, v;
		scanf("%d %d", &p, &v);
		update(p, v);

		if (in[1] == 0) {
			printf("1\n");
			continue;
		}

		int ans = -1;
		ll cur = in[1];
		while (1) {
			int p = largerpos(2 * cur - 1);
			if (p == INF) break;

			ll v = getsum(p - 1);
			if (v == in[p]) {
				ans = p;
				break;
			}
			cur = v + in[p];
		}
		printf("%d\n", ans);
	}
	return 0;
}