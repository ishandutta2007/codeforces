#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXL = 2e6 + 5;
const long long INF = 4e18;
typedef long long ll;
template <typename T> T abs(T x) {if (x <= 0) return -x; else return x; }
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, l; bool vis[MAXL];
ll t[MAXN], x[MAXN], y[MAXN];
pair <ll, ll> px[MAXL], py[MAXL];
ll solve(pair <ll, ll> x, pair <ll, ll> y) {
	if ((y.first - x.first) % (y.second - x.second) == 0)
		return (y.first - x.first) / (y.second - x.second);
	puts("NO"), exit(0);
	return -1;
}
ll Ceil(ll x, ll y) {
	ll tmp = INF / y;
	return (x + tmp * y) / y - tmp + 1;
}
ll Round(ll x, ll y) {
	ll tmp = INF / y;
	return (x + tmp * y) / y - tmp;
}
pair <ll, ll> calc(pair <ll, ll> x, pair <ll, ll> y, ll k) {
	if (y.second == x.second) {
		ll delta = abs(x.first - y.first);
		if (delta <= k) return make_pair(-l, l);
		else return make_pair(INF, -INF);
	}
	if (y.second < x.second) swap(x, y);
	ll coef = y.second - x.second, delta = y.first - x.first;
	ll Min = delta - k, Max = delta + k; pair <ll, ll> ans;
	if (Min % coef == 0) ans.first = Min / coef;
	else ans.first = Ceil(Min, coef);
	if (Max % coef == 0) ans.second = Max / coef;
	else ans.second = Round(Max, coef);
	return ans;
}
int main() {
	read(n), read(l);
	pair <ll, ll> limx, limy;
	limx = limy = make_pair(-l, l);
	vis[0] = true;
	for (int i = 1; i <= n; i++) {
		read(t[i]), read(x[i]), read(y[i]);
		ll tx = x[i] + y[i], ty = x[i] - y[i];
		x[i] = tx, y[i] = ty;
		if (abs(x[i]) % 2 != t[i] % 2 || abs(y[i]) % 2 != t[i] % 2) {
			puts("NO");
			return 0;
		}
		ll Mod = t[i] % l, Div = t[i] / l;
		if (vis[Mod]) {
			chkmax(limx.first, solve(px[Mod], make_pair(x[i], Div)));
			chkmin(limx.second, solve(px[Mod], make_pair(x[i], Div)));
			chkmax(limy.first, solve(py[Mod], make_pair(y[i], Div)));
			chkmin(limy.second, solve(py[Mod], make_pair(y[i], Div)));
		} else {
			vis[Mod] = true;
			px[Mod] = make_pair(x[i], Div);
			py[Mod] = make_pair(y[i], Div);
		}
	}
	vis[l] = true, px[l] = py[l] = make_pair(0, -1);
	for (int i = 1, last = 0; i <= l; i++)
		if (vis[i]) {
			pair <ll, ll> tmp;
			tmp = calc(px[last], px[i], i - last);
			chkmax(limx.first, tmp.first);
			chkmin(limx.second, tmp.second);
			tmp = calc(py[last], py[i], i - last);
			chkmax(limy.first, tmp.first);
			chkmin(limy.second, tmp.second);
			last = i;
		}
	if (abs(limx.first) % 2 != l % 2) limx.first++;
	if (abs(limy.first) % 2 != l % 2) limy.first++;
	if (limx.first > limx.second || limy.first > limy.second) {
		puts("NO");
		return 0;
	}
	ll sumx = limx.first, sumy = limy.first;
	static bool ansx[MAXL], ansy[MAXL];
	for (int i = 1, last = 0; i <= l; i++)
		if (vis[i]) {
			ll now, goal;
			now = px[last].first - px[last].second * sumx;
			goal = px[i].first - px[i].second * sumx;
			for (int j = last + 1; j <= i; j++)
				if (now <= goal) {
					ansx[j] = true;
					now++;
				} else now--;
			assert(now == goal);
			now = py[last].first - py[last].second * sumy;
			goal = py[i].first - py[i].second * sumy;
			for (int j = last + 1; j <= i; j++)
				if (now <= goal) {
					ansy[j] = true;
					now++;
				} else now--;
			assert(now == goal);
			last = i;
		}
	for (int i = 1; i <= l; i++) {
		if (ansx[i]) {
			if (ansy[i]) putchar('R');
			else putchar('U');
		} else {
			if (ansy[i]) putchar('D');
			else putchar('L');
		}
	}
	puts("");
	return 0;
}