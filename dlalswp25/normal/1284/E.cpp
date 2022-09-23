#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

ll px, py;

struct PNT {
	ll x, y;
	bool operator< (const PNT& o) const{
		ll x1 = x, y1 = y;
		ll x2 = o.x, y2 = o.y;

		if(y1 == 0) {
			if(x1 > 0) return true;
			else return y2 < 0;
		}
		if(y2 == 0) {
			if(x2 > 0) return false;
			else return y1 > 0;
		}

		if(y1 > 0 && y2 < 0) return true;
		if(y1 < 0 && y2 > 0) return false;

		return x1 * y2 > x2 * y1;
	}
};

PNT A[2525];
PNT B[2525];

vector<int> v;
vector<int> l, r;

ll nc2(ll x) {
	if(x < 0) return 0;
	return x * (x - 1) / 2;
}

ll nc3(ll x) {
	return x * (x - 1) * (x - 2) / 6;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld%lld", &A[i].x, &A[i].y);

	ll ans = 0;

	for(int i = 1; i <= N; i++) {
		int z = 0;
		for(int j = 1; j <= N; j++) {
			if(i == j) continue;
			z++; B[z] = A[j];
			B[z].x -= A[i].x;
			B[z].y -= A[i].y;
		}

		sort(B + 1, B + N);

		int u = 0, d = 0;
		for(int j = 1; j < N; j++) {
			if(B[j].y > 0) u++;
			else if(B[j].y < 0) d++;
			else if(B[j].x > 0) u++;
			else d++;
		}
		if(!u || !d) continue;

		// printf("*************%d\n", i);
		// for(int j = 1; j < N; j++) printf("%lld %lld\n", B[j].x, B[j].y);

		int p = u + 1;
		for(int j = 1; j < N; j++) {
			if(j > u) break;
			while(p < N) {
				if(B[p].x * B[j].y < B[j].x * B[p].y) p++;
				else break;
			}
			int tmp = p - (u + 1);
			ans += nc3(d);
			ans -= nc3(tmp);
			ans -= nc3(d - tmp);
		}

		p = 1;
		for(int j = u + 1; j < N; j++) {
			while(p <= u) {
				if(B[p].x * B[j].y < B[j].x * B[p].y) p++;
				else break;
			}
			int tmp = p - 1;
			ans += nc3(u);
			ans -= nc3(tmp);
			ans -= nc3(u - tmp);
		}

		p = u + 1;
		for(int j = 1; j <= u; j++) {
			while(p < N) {
				if(B[p].x * B[j].y < B[j].x * B[p].y) p++;
				else break;
			}
			v.push_back(p - (u + 1));
		}
		v.push_back(N - (u + 1));
		// for(int j : v) printf("a%d ", j); puts("");

		for(int j = (int)v.size() - 1; j > 0; j--) {
			v[j] -= v[j - 1];
		}

		// for(int j : v) printf("a%d ", j); puts("");

		l.push_back(v[0]);
		for(int j = 1; j < v.size(); j++) {
			l.push_back(l.back() + v[j]);
		}

		r.push_back(v.back());
		for(int j = (int)v.size() - 2; j >= 0; j--) {
			r.push_back(r.back() + v[j]);
		}
		reverse(r.begin(), r.end());

		// for(int j : l) printf("l%d ", j); puts("");
		// for(int j : r) printf("r%d ", j); puts("");

		ans += nc2(d) * nc2(u);

		int sum = 0;
		for(int i = 0; i < l.size(); i++) {
			// printf("%d %d\n", l[i], u - (i + 1));
			if(u - (i + 1) <= 0) break;
			ans -= nc2(l[i]) * (u - (i + 1));
			// printf("%lld\n", ans);
		}

		for(int i = (int)r.size() - 1; i >= 0; i--) {
			// printf("%d %d\n", r[i], u - ((int)r.size() - i));
			if(u - ((int)r.size() - i) <= 0) break;
			ans -= nc2(r[i]) * (u - ((int)r.size() - i));
			// printf("%lld\n", ans);
		}

		v.clear();
		l.clear();
		r.clear();
		// printf("ans : %lld\n", ans);
	}
	printf("%lld\n", ans);

	return 0;
}

/*
6
1 0
-1 0
2 1
-2 1
-2 -1
2 -1
*/