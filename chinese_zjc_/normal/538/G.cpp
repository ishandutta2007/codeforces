#define Fail prints("NO"), exit(0)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
const ll inf = 4e18;
int n, l;
ll lx = -inf, rx = inf, ly = -inf, ry = inf;
void rd(int &x) { std::cin >> x; }
void rd(ll &x) { std::cin >> x; }
void prints(char *x) { puts(x); }
struct P
{
	ll t, x, y, k;
	int w;
	inline void in()
	{
		ll p, q;
		rd(t), rd(p), rd(q);
		if ((t ^ p ^ q) & 1)
			Fail;
		k = t / l, w = t % l;
		x = (p + q + t) / 2, y = (q - p + t) / 2;
	}
	inline bool operator<(const P &o) const { return w < o.w; }
} p[N];

int main()
{
	rd(n), rd(l);
	for (int i = 1; i <= n; i++)
		p[i].in();
	sort(p + 1, p + n + 1);
	p[++n].k = -1, p[n].w = l;
	for (int i = 1; i <= n; i++)
	{
		ll k = p[i].k - p[i - 1].k;
		int w = p[i].w - p[i - 1].w;
		if (!k)
		{
			if (p[i].x - p[i - 1].x - w > 0 || p[i].x - p[i - 1].x < 0)
				Fail;
			if (p[i].y - p[i - 1].y - w > 0 || p[i].y - p[i - 1].y < 0)
				Fail;
		}
		else if (k > 0)
		{
			lx = max(lx, (ll)ceil(1.0L * (p[i].x - p[i - 1].x - w) / k));
			rx = min(rx, (ll)floor(1.0L * (p[i].x - p[i - 1].x) / k));
			ly = max(ly, (ll)ceil(1.0L * (p[i].y - p[i - 1].y - w) / k));
			ry = min(ry, (ll)floor(1.0L * (p[i].y - p[i - 1].y) / k));
		}
		else
		{
			lx = max(lx, (ll)ceil(1.0L * (p[i].x - p[i - 1].x) / k));
			rx = min(rx, (ll)floor(1.0L * (p[i].x - p[i - 1].x - w) / k));
			ly = max(ly, (ll)ceil(1.0L * (p[i].y - p[i - 1].y) / k));
			ry = min(ry, (ll)floor(1.0L * (p[i].y - p[i - 1].y - w) / k));
		}
	}
	if (lx > rx || ly > ry)
		Fail;
	for (int i = 1; i <= n; i++)
	{
		int dx = (p[i].x - p[i].k * lx) - (p[i - 1].x - p[i - 1].k * lx);
		int dy = (p[i].y - p[i].k * ly) - (p[i - 1].y - p[i - 1].k * ly);
		int t = p[i].w - p[i - 1].w, x = 0, y = 0;
		while (t--)
			if (x < dx)
			{
				++x;
				if (y < dy)
					putchar('U'), ++y;
				else
					putchar('R');
			}
			else
			{
				if (y < dy)
					putchar('L'), ++y;
				else
					putchar('D');
			}
	}
	return 0;
}