#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

typedef long long ll;

const int N = 5e5 + 5;

int n, k, m, l[N], r[N], bel[N], tot;
double ans;
bool vis[N];

struct djq
{
	int u; double dis;
} w[N];

inline bool pmoc(djq a, djq b) {return a.dis > b.dis;}

struct point
{
	int x, y;
	
	friend inline ll operator * (point a, point b)
	{
		return 1ll * a.x * b.y - 1ll * a.y * b.x;
	}
	
	ll len() {return 1ll * x * x + 1ll * y * y;}
} a[N];

inline bool comp(point a, point b)
{
	bool isa = a.y > 0 || (a.y == 0 && a.x > 0),
		isb = b.y > 0 || (b.y == 0 && b.x > 0);
	if (isa != isb) return isa > isb;
	return a * b > 0 || (a * b == 0 && a.len() < b.len());
}

bool coll(point a, point b)
{
	bool isa = a.y > 0 || (a.y == 0 && a.x > 0),
		isb = b.y > 0 || (b.y == 0 && b.x > 0);
	return isa == isb && a * b == 0;
}

int main()
{
	read(n); read(k);
	for (int i = 1; i <= n; i++) read(a[i].x), read(a[i].y);
	for (int i = 1; i <= n; i++) if (!a[i].x && !a[i].y)
		{std::swap(a[i], a[1]); break;}
	std::sort(a + 2, a + n + 1, comp);
	for (int i = 2, j = 2; i <= n; i++)
		if (i == n || !coll(a[i], a[i + 1]))
		{
			l[++m] = j; r[m] = i;
			for (int k = j; k <= i; k++) bel[k] = m;
			for (int h = 1; h <= k / 2 && h <= i - j + 1; h++)
				w[++tot] = (djq) {i - h + 1, sqrt(a[i - h + 1].len())
					* (k + 1 - 2 * h)};
			j = i + 1;
		}
	std::sort(w + 1, w + tot + 1, pmoc);
	for (int i = 1; i <= tot && i <= k; i++) ans += w[i].dis, vis[w[i].u] = 1;
	if (tot < k)
	{
		double delta = -1e24;
		for (int T = 1; T <= m; T++)
		{
			int cnt = 0;
			for (int i = l[T]; i <= r[T]; i++) if (!vis[i]) cnt++;
			if (cnt < k - tot - 1) continue;
			double res = 0;
			for (int i = 1; i < k - tot; i++)
				res += sqrt(a[l[T] + (k - tot - 1) - i].len())
					* (k + 1 - 2 * (k / 2 + i));
			if (res > delta) delta = res;
			if (cnt < k - tot) continue;
			res = 0;
			for (int i = 1; i <= k - tot; i++)
				res += sqrt(a[l[T] + (k - tot) - i].len())
					* (k + 1 - 2 * (k / 2 + i));
			if (res > delta) delta = res;
		}
		ans += delta;
	}
	return printf("%.10lf\n", ans), 0;
}