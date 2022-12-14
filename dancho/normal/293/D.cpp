#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-9;

struct point
{
	int x, y;
};

int n;
point p[100020];

double totcnt;

double sdsq()
{
	int mxx = p[0].x;
	int bi = 0;
	for (int i = 1; i < n; ++i)
	{
		if (p[i].x < p[bi].x)
			bi = i;
		mxx = max(mxx, p[i].x);
	}
	int lo, hi;
	lo = hi = bi;
	int lpr = lo - 1;
	if (lpr < 0)
		lpr += n;

	int hne = hi + 1;
	if (hne >= n)
		hne -= n;
	while (p[lpr].x == p[lo].x)
	{
		lo = lpr;
		--lpr;
		if (lpr < 0)
			lpr += n;
	}

	while (p[hne].x == p[hi].x)
	{
		hi = hne;
		++hne;
		if (hne >= n)
			hne -= n;
	}

	double ymi = min(p[hi].y, p[lo].y);
	double ymx = max(p[hi].y, p[lo].y);
	double ans = 0.0;
	double spr = 0;
	double tot = 0;

	double cx = p[hi].x;
	while (cx <= mxx)
	{
		double yx, yi;
		if (cx == p[hne].x)
		{
			hi = hne;
			++hne;
			if (hne >= n)
				hne -= n;
			while (p[hne].x == p[hi].x)
			{
				hi = hne;
				++hne;
				if (hne >= n)
					hne -= n;
			}
		}
		if (cx == p[lpr].x)
		{
			lo = lpr;
			--lpr;
			if (lpr < 0)
				lpr += n;
			while (p[lpr].x == p[lo].x)
			{
				lo = lpr;
				--lpr;
				if (lpr < 0)
					lpr += n;
			}
		}

		double a, b, c;

		a = p[hi].y - p[hne].y;
		b = p[hne].x - p[hi].x;
		c = -a * p[hi].x - b * p[hi].y;
		// Assuming OK polygon
		yx = (-c - a * cx) / b;
		
		a = p[lo].y - p[lpr].y;
		b = p[lpr].x - p[lo].x;
		c = -a * p[lo].x - b * p[lo].y;
		// Assuming OK polygon
		yi = (-c - a * cx) / b;
		ymi = (int) ceil(min(yx, yi));
		ymx = (int) floor(max(yx, yi));

		double cnt = ymx - ymi + 1;
		ans += (double) (totcnt - cnt) * cnt * cx * cx;

		ans -= 2.0 * (double) spr * cnt * cx;
		tot += cnt;
		spr += cnt * cx;

		//~ printf("OP %d %d _ %lf\n", cx, cnt, ans);

		++cx;
	}

	totcnt = tot;

	return ans;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	sdsq();
	double sm = sdsq();
	for (int i = 0; i < n; i++)
	{
		swap(p[i].x, p[i].y);
	}
	sm += sdsq();

	printf("%.10lf\n", sm / ((double) totcnt) / ((double) totcnt - 1.0));

	return 0;
}