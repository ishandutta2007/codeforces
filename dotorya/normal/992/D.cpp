#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 10000;
const int MOD = 1000000007;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

ll mymul(ll a, ll b) {
	if (LL_INF / a < b) return LL_INF;
	return min(a*b, LL_INF);
}

ll in[200050];
ll sum[200050];
int nxt[200050];

int main() {
	int N, K, i;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
		sum[i] = sum[i - 1] + in[i];
	}
	nxt[N + 1] = N + 1;
	for (i = N; i >= 1; i--) {
		nxt[i] = nxt[i + 1];
		if (in[i] > 1) nxt[i] = i;
	}

	ll ans = 0;
	for (i = 1; i <= N; i++) {
		ll v = in[i], st = i;
		while (v < 3e18) {
			ll en = nxt[st + 1] - 1;

			if (v % K == 0) {
				ll v2 = v / K + sum[i - 1];
				int p = lower_bound(sum + 1, sum + N + 1, v2) - sum;
				if (p != N + 1 && sum[p] == v2 && st <= p && p <= en) ans++;
			}

			if (en == N) break;
			st = en + 1;
			v = mymul(v, in[st]);
		}
	}
	return !printf("%lld\n", ans);
}