#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

#define double long double
using pdd = pair<double, double>;
using pii = pair<int, int>;

pii P[200000];

long long CCW(pii base, pii a, pii b) { return 1LL * (a.x - base.x) * (b.y - base.y) - 1LL * (a.y - base.y) * (b.x - base.x); }

tuple<int, int, long long> get_equation(pii a, pii b) { return { a.y - b.y,b.x - a.x,1LL * a.x * b.y - 1LL * b.x * a.y }; }

pdd intersection(pii a, pii b, pii c, pii d)
{
	auto [A, B, C] = get_equation(a, b);
	auto [D, E, F] = get_equation(c, d);
	if (1LL * A * E == 1LL * B * D) {
		if (a == c || a == d) return a;
		return b;
	}
	return { 1. * (B * F - C * E) / (1LL * A * E - 1LL * B * D),1. * (A * F - C * D) / (1LL * B * D - 1LL * A * E) };
}

double get_dist(pii a, pdd b)
{
	double dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, H;
	pii l, c;
	double ans = 0;
	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		cin >> P[i].x >> P[i].y;
		c = P[i];
	}
	c.y += H; l = P[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		if (CCW(l, c, P[i]) > 0) {
			auto p = intersection(c, l, P[i], P[i + 1]);
			l = P[i]; ans += get_dist(P[i], p);
		}
		else if (CCW(l, c, P[i]) == 0 && CCW(l, c, P[i + 1]) == 0) ans += get_dist(P[i], P[i + 1]);
	}
	cout << fixed << setprecision(9) << ans << '\n';

	return 0;
}