#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }

struct LIN {
	ll l, r;
	ll y;

	bool operator< (const LIN& o) const {
		if(y == o.y) return l < o.l;
		return y > o.y;
	}
}A[2020];

struct FRAC {
	ll x, y;

	FRAC(ll _x, ll _y) : x(_x), y(_y) {}

	void norm() {
		ll g = gcd(abs(x), y);
		x /= g; y /= g;
	}

	bool operator< (const FRAC& o) const {
		return x * o.y > o.x * y;
	}

	bool operator== (const FRAC& o) const {
		return x == o.x && y == o.y;
	}
};

struct EVT {
	FRAC f;
	int id1, id2;

	EVT(FRAC _f, int _id1, int _id2) : f(_f), id1(_id1), id2(_id2) {}

	bool operator< (const EVT& o) const {
		if(f == o.f) {
			if(id2 == o.id2) return id1 > o.id1;
			return id2 > o.id2;
		}
		return f < o.f;
	}
};

vector<EVT> evt;

int B[2020];
int pos[2020];

void sw(int i, int j) {
	int x = pos[i], y = pos[j];
	swap(B[x], B[y]);
	swap(pos[i], pos[j]);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld%lld%lld", &A[i].l, &A[i].r, &A[i].y);

	sort(A + 1, A + N + 1);

	// for(int i = 1; i <= N; i++) printf("%lld %lld %lld\n", A[i].l, A[i].r, A[i].y);

	for(int i = 1; i <= N; i++) {
		for(int j = i + 1; j <= N; j++) {
			FRAC f = FRAC(A[i].r - A[j].l, A[i].y - A[j].y);
			if(f.y) {
				f.norm();
				// printf("%d %d %lld %lld\n", i, j, f.x, f.y);
				evt.emplace_back(f, A[i].l - A[j].r, A[j].y - A[i].y);
			}
			f = FRAC(A[i].l - A[j].r, A[i].y - A[j].y);
			if(f.y) {
				f.norm();
				// printf("%d %d %lld %lld\n", i, j, f.x, f.y);
				evt.emplace_back(f, 0, 0);
			}

			f = FRAC(A[i].l - A[j].l, A[i].y - A[j].y);
			if(f.y) {
				f.norm();
				evt.emplace_back(f, i, j);
			}
		}
	}

	sort(evt.begin(), evt.end());

	// for(auto i : evt) printf("%lld %lld %d %d\n", i.f.x, i.f.y, i.id1, i.id2);

	for(int i = 1; i <= N; i++) B[i] = pos[i] = i;

	double ans = 1e18;

	if(evt.size() == 0) {
		ans = A[N].r - A[1].l;
	}

	FRAC mx = FRAC(1010101010, 1);
	FRAC tmx = mx;
	for(int i = 0; i < evt.size(); i++) {
		auto e = evt[i];

		// printf("evt : %lld %lld %d %d\n", e.f.x, e.f.y, e.id1, e.id2);

		if(e.id2 > 0) {
			sw(e.id1, e.id2);
		}
		else if(e.id2 < 0) {
			FRAC tmp = FRAC(e.id1, -e.id2);
			tmp.norm();
			if(tmx < tmp) tmx = tmp;
		}
		if(i + 1 < evt.size() && evt[i + 1].f == evt[i].f) continue;

		// for(int j = 1; j <= N; j++) printf("%d ", B[j]); puts("");
		// printf("mx : %lld %lld\n", mx.x, mx.y);

		if(!(e.f < mx)) {
			LIN s1 = A[B[1]], s2 = A[B[N]];
			double l = s1.l;
			l -= (double)s1.y * e.f.x / e.f.y;
			double r = s2.r;
			r -= (double)s2.y * e.f.x / e.f.y;
			ans = min(ans, r - l);
			// printf("ans : %f\n", ans);
		}

		mx = tmx;
	}
	printf("%.10f\n", ans);
	return 0;
}