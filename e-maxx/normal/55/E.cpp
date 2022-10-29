#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


const int MAXN = 110000;
const double EPS = 1E-7;

struct pt {
	int x, y;
};

int n;
pt p[MAXN];
int l[MAXN], r[MAXN];
long long r_sums[MAXN];

inline long long vec (pt a, pt b, pt c) {
	return (b.x - a.x) * 1ll * (c.y - a.y) - (b.y - a.y) * 1ll * (c.x - a.x);
}

inline bool between (pt p, pt a, pt b, pt q) {
	return vec (p, a, q) > 0 && vec (p, q, b) > 0;
}

inline long long sum_r (int lt, int rt) {
	/*
	long long res = 0;
	for (int i=lt; i<=rt; ++i)
		res += r[i];
	return res;
	*/
	long long res = r_sums[rt];
	if (lt)
		res -= r_sums[lt-1];
	return res;
}

long long solve (pt q) {
	int j = 0;
	for (int i=0; i<n; ++i) {
		j = max (j, i+1);
		while (j+1 < n && ! between (p[i], p[i+1], p[j+1], q))
			++j;
		r[i] = j;
		l[i] = j+1;
	}

	for (int i=0; i<n; ++i) {
		r_sums[i] = 0;
		if (i)  r_sums[i] += r_sums[i-1];
		r_sums[i] += r[i];
	}

	long long ans = 0;
	j = 0;
	for (int i=0; i<n; ++i) {
		while (j < n && r[j] < l[i])
			++j;

		if (l[i] < n && j < n) {
			int left = j,
				right = r[i];
			if (left > right)  continue;
			/*
			for (int k=left; k<=right; ++k)
				ans += r[k] - l[i] + 1;
			*/
			ans += sum_r (left, right);
			ans -= (right - left + 1) * 1ll * (l[i] - 1);
		}
	}
	return ans;
}


bool inside (pt q) {
	bool res = false;
	for (int i=0; i<n; ++i) {
		pt a = p[i],
			b = p[(i+1)%n];
		if (min (a.y, b.y) <= q.y && max (a.y, b.y) >= q.y) {
			if (q.y != a.y && q.y != b.y) {
				double cx = a.x + (b.x - a.x) * ((q.y - a.y) * 1. / (b.y - a.y));
				if (cx >= q.x - EPS)
					res ^= true;
			}
			else {
				if (a.y == q.y && a.x > q.x || b.y == q.y && b.x > q.x)
					if (max (a.y, b.y) > q.y)
						res ^= true;
			}
		}
	}
	return res;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; ++i)
		scanf ("%d%d", &p[i].x, &p[i].y);
	reverse (p, p+n);

	int ts;
	cin >> ts;
	for (int tt=0; tt<ts; ++tt) {
		pt q;
		scanf ("%d%d", &q.x, &q.y);
		long long ans = 0;
		if (inside (q))
			ans = solve (q);
		printf ("%I64d\n", ans);
	}

}