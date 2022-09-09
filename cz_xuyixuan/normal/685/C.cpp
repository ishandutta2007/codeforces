#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const long long INF = 4e18;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n; ll rx, ry, rz, x[MAXN], y[MAXN], z[MAXN];
bool found(pair <ll, ll> pp, pair <ll, ll> pm, pair <ll, ll> mp, pair <ll, ll> mm, bool parity) {
	if ((pp.first % 2 == 0) ^ parity) pp.first++;
	if ((pm.first % 2 == 0) ^ parity) pm.first++;
	if ((mp.first % 2 == 0) ^ parity) mp.first++;
	if ((mm.first % 2 == 0) ^ parity) mm.first++;
	if ((pp.second % 2 == 0) ^ parity) pp.second--;
	if ((pm.second % 2 == 0) ^ parity) pm.second--;
	if ((mp.second % 2 == 0) ^ parity) mp.second--;
	if ((mm.second % 2 == 0) ^ parity) mm.second--;
	
	if (pp.first > pp.second) return false;
	if (pm.first > pm.second) return false;
	if (mp.first > mp.second) return false;
	if (mm.first > mm.second) return false;
	
	pair <ll, ll> rng = make_pair(-INF, INF);
	chkmax(rng.first, pp.first - pm.second);
	chkmin(rng.second, pp.second - pm.first);
	chkmax(rng.first, mp.first - mm.second);
	chkmin(rng.second, mp.second - mm.first);
	
	if (rng.first > rng.second) return false;
	rng.first /= 2, rng.second /= 2, rz = rng.first;
	
	pair <ll, ll> p = make_pair(-INF, INF);
	chkmax(p.first, pp.first - rz);
	chkmin(p.second, pp.second - rz);
	chkmax(p.first, pm.first + rz);
	chkmin(p.second, pm.second + rz);
	
	pair <ll, ll> m = make_pair(-INF, INF);
	chkmax(m.first, mp.first - rz);
	chkmin(m.second, mp.second - rz);
	chkmax(m.first, mm.first + rz);
	chkmin(m.second, mm.second + rz);
	
	rx = p.first / 2 + m.first / 2;
	if (p.first & 1) {
		if (p.first > 0 && m.first > 0) rx++;
		if (p.first < 0 && m.first < 0) rx--;
	}
	ry = p.first - rx;
	return true;
}
bool check(ll mid) {
	pair <ll, ll> pp = make_pair(-INF, INF), pm = make_pair(-INF, INF);
	pair <ll, ll> mp = make_pair(-INF, INF), mm = make_pair(-INF, INF);
	for (int i = 1; i <= n; i++) {
		chkmax(pp.first, x[i] + y[i] + z[i] - mid);
		chkmin(pp.second, x[i] + y[i] + z[i] + mid);
		
		chkmax(pm.first, x[i] + y[i] - z[i] - mid);
		chkmin(pm.second, x[i] + y[i] - z[i] + mid);
		
		chkmax(mp.first, x[i] - y[i] + z[i] - mid);
		chkmin(mp.second, x[i] - y[i] + z[i] + mid);
		
		chkmax(mm.first, x[i] - y[i] - z[i] - mid);
		chkmin(mm.second, x[i] - y[i] - z[i] + mid);
	}
	if (found(pp, pm, mp, mm, 0)) return true;
	if (found(pp, pm, mp, mm, 1)) return true;
	return false;
}
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++)
			read(x[i]), read(y[i]), read(z[i]);
		ll l = 0, r = 3e18;
		while (l < r) {
			ll mid = (l + r) / 2;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		check(l), printf("%lld %lld %lld\n", rx, ry, rz);
	}
	return 0;
}