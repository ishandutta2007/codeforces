#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct pt {
	ll x, y;
	pt(ll a=0, ll b=0) :x(a), y(b) {}
	pt operator+ (const pt& o) const { return {x+o.x, y+o.y}; }
	pt operator- (const pt& o) const { return {x-o.x, y-o.y}; }
	pt operator* (const ll& o) const { return {x*o, y*o}; }
	pt operator/ (const ll& o) const { return {x/o, y/o}; }
	pt normalize() const {
		ll g = __gcd(x, y);
		pt q = {x, y};
		q.x /= g;
		q.y /= g;
		if (q.x < 0 || (q.x==0 && q.y < 0)) {
			q.x *= -1;
			q.y *= -1;
		}
		return q;
	};
	bool operator== (const pt& o) const {
		return x==o.x && y==o.y;
	}
	bool operator< (const pt& o) const {
		return x<o.x || (x==o.x && y<o.y);
	}
};

ll cp(const pt& a, const pt& b) { return a.x*b.y - a.y*b.x; }
ll dp(const pt& a, const pt& b) { return a.x*b.x + a.y*b.y; }
ll sgn(const ll& x) { return (x == 0 ? 0 : (x > 0 ? 1 : -1)); }
bool cmp_lex(const pt& a, const pt& b) {
	return a.x<b.x || (a.x==b.x && a.y < b.y);
}

bool seg_x_seg(pt a1, pt a2, pt b1, pt b2) {
	int s1 = sgn(cp(a2-a1, b1-a1)), s2 = sgn(cp(a2-a1, b2-a1));
	int s3 = sgn(cp(b2-b1, a1-b1)), s4 = sgn(cp(b2-b1, a2-b1));
	if (!s1 && !s2 && !s3) {
		if (cmp_lex(a2, a1)) swap(a1, a2);
		if (cmp_lex(b2, b1)) swap(b1, b2);
		return !cmp_lex(b2, a1) && !cmp_lex(a2, b1);
	}
	return s1*s2 <= 0 && s3*s4 <= 0;
}

pt line_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
	if (a == c) return a;
	if (a == d) return a;
	if (b == c) return b;
	if (b == d) return b;
	return a + (b-a) * cp(c-a, d-c) / cp(b-a, d-c);
}

bool is_on_line(const pt& a, const pt& b, const pt& p) {
	if (p == a || p == b) return true;
	return cp(p-a, b-a) == 0 && dp(p-a, b-a) > 0 && dp(p-b, a-b) > 0;
}

pair<pt, pt> segs[1010];

set<pt> seen;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	ll ans = 0;
	for (int i=1; i<=n; ++i) {
		seen.clear();
		pt a1, a2;
		cin >> a1.x >> a1.y >> a2.x >> a2.y;
		segs[i].first = a1;
		segs[i].second = a2;

		{
			pt d = a2-a1;
			pt norm = d.normalize();
			ans += ((abs(d.x)+abs(d.y))/(abs(norm.x)+abs(norm.y)) + 1);
		}

		for (int j=1; j<i; ++j) {
			pt b1 = segs[j].first;
			pt b2 = segs[j].second;
			if (!seg_x_seg(a1, a2, b1, b2)) {
				continue;
			}
			pt isec = line_inter(a1, a2, b1, b2);
			if (!is_on_line(a1, a2, isec) || !is_on_line(b1, b2, isec)) {
				continue;
			}
			if (seen.count(isec)) {
				continue;
			}
			--ans;
			seen.insert(isec);
		}
	}

	cout << ans << "\n";

	return 0;
}