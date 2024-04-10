#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
#define mp make_pair
using namespace std;

const int mo = 1e9 + 7;
const int N = 105;

int move[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int r, td, tot; ll p[4];
int d[7851][7851];
ll ans[8005];
map<pair<int, int>, int> bz;

ll ksm(ll x, ll y) {
	ll s = 1;
	for(; y; y /= 2, x = x * x % mo)
		if(y & 1) s = s * x % mo;
	return s;
}


int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d", &r);
	ll sum = 0;
	fo(i, 0, 3) scanf("%I64d", &p[i]), sum += p[i];
	sum = ksm(sum, mo - 2);
	fo(i, 0, 3) p[i] = p[i] * sum % mo;
	fo(i, -r, r) fo(j, -r, r) {
		if(i * i + j * j > r * r) continue;
		bz[mp(i, j)] = ++ td;
	}
	tot = 0;
	fo(i, -r, r) fo(j, -r, r) {
		if(i * i + j * j > r * r) continue;
		d[++ tot][0] = 1;
		d[tot][bz[mp(i, j)]] = -1;
		fo(k, 0, 3) {
			int x = i + move[k][0], y = j + move[k][1];
			if(bz[mp(x, y)]) d[tot][bz[mp(x, y)]] = p[k];
		}
	}
	fo(i, 1, td) {
		fo(j, i + 1, td) {
			if(j - i > 2 * r) continue;
			ll t = ksm(d[j][i], mo - 2) * d[i][i] % mo;
			if(t == 0) continue;
			int u = min(tot, j + 2 * r);
			fo(k, i, u) d[j][k] = ((ll) d[j][k] * t - d[i][k]) % mo;
			d[j][0] = ((ll)d[j][0] * t - d[i][0]) % mo;
		}
	}
	fd(i, td, 1) {
		ll v = 0;
		ans[i] = (ll) -d[i][0] * ksm(d[i][i] % mo, mo - 2);
		ans[i] = (ans[i] % mo + mo) % mo;
		fo(j, max(1, i - 2 * r), i - 1)
			d[j][0] = (d[j][0] + (ll) d[j][i] * ans[i] % mo) % mo;
	}
	printf("%I64d\n", ans[bz[mp(0, 0)]]);
}