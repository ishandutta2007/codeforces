#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, M;
ll K;
ll a[22][22];
map<pair<ll, pair<int, int> >, int> cs;

int main() {
	scanf("%d%d%lld", &N, &M, &K);
	repi(i, N) repi(j, M) scanf("%lld", a[i] + j);
	rep(i, 1 << (N - 1)) {
		ll val = a[1][1];
		int nx = 1, ny = 1;
		rep(j, N - 1) {
			if ((i >> j) & 1) ++nx;
			else ++ny;
			if (nx > N || ny > M) break;
			val ^= a[nx][ny];
		}
		if (nx > N || ny > M) continue;
		++cs[make_pair(val, make_pair(nx, ny))];
	}
	ll ans = 0;
	rep(i, 1 << (M - 1)) {
		ll val = 0;
		int nx = N, ny = M;
		rep(j, M - 1) {
			val ^= a[nx][ny];
			if ((i >> j) & 1) --nx;
			else --ny;
			if (nx < 1 || ny < 1) break;
		}
		if (nx < 1 || ny < 1) continue;
		ans += cs[make_pair(val ^ K, make_pair(nx, ny))];
	}
	printf("%lld\n", ans);
	return 0;
}