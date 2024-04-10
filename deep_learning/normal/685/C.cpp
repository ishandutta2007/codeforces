#include <iostream>
#include <cstdio>
using namespace std; 
typedef long long ll; 
struct point
{
	ll x, y, z; 
	point()
	{
	}
	point(ll _x, ll _y, ll _z)
	{
		x = _x; 
		y = _y; 
		z = _z; 
	}
} p[100005]; 
const point INFp(3e18, 3e18, 3e18); 
struct limit
{
	ll smin, smax, amin, amax, bmin, bmax, cmin, cmax; 
	limit()
	{
		smin = amin = bmin = cmin = -3e18; 
		smax = amax = bmax = cmax = 3e18; 
	}
	limit(ll _smin, ll _smax, ll _amin, ll _amax, ll _bmin, ll _bmax, ll _cmin, ll _cmax)
	{
		smax = _smax; 
		smin = _smin; 
		amax = _amax; 
		amin = _amin; 
		bmax = _bmax; 
		bmin = _bmin; 
		cmax = _cmax; 
		cmin = _cmin;
	}
	inline limit operator +(const limit &a) const
	{
		return limit(max(smin, a.smin), min(smax, a.smax), max(amin, a.amin), min(amax, a.amax)
			, max(bmin, a.bmin), min(bmax, a.bmax), max(cmin, a.cmin), min(cmax, a.cmax)); 
	}
	inline limit operator +=(const limit &a)
	{
		return *this = *this + a; 
	}
}; 
int n; 
inline bool check(point x)
{
	return x.x != 3e18; 
}
inline ll div(const ll &x)
{
	if (x >= 0)
		return x / 2; 
	else
		return (x - 1) / 2; 
}
inline point solve(limit x)
{
	// cout << x.smin << " " << x.smax << " " << x.amin << " " << x.amax << " "
	//  << x.bmin << " " << x.bmax << " " << x.cmin << " " << x.cmax << endl; 
	if (x.smin > x.smax || x.amin > x.amax || x.bmin > x.bmax || x.cmin > x.cmax
		|| x.amin + x.bmin + x.cmin > x.smax || x.amax + x.bmax + x.cmax < x.smin)
		return INFp; 
	point res(x.amin, x.bmin, x.cmin); 
	ll goal = max(0ll, x.smax - res.x - res.y - res.z); 
	res.x += min(goal, x.amax - x.amin); 
	goal -= min(goal, x.amax - x.amin); 
	res.y += min(goal, x.bmax - x.bmin); 
	goal -= min(goal, x.bmax - x.bmin); 
	res.z += min(goal, x.cmax - x.cmin); 
	goal -= min(goal, x.cmax - x.cmin); 
	return res; 
}
inline point calc(ll dis)
{
	limit cur; 
	for (int i = 0; i < n; i++)
		cur += limit(p[i].x + p[i].y + p[i].z - dis, p[i].x + p[i].y + p[i].z + dis
			, -p[i].x + p[i].y + p[i].z - dis, -p[i].x + p[i].y + p[i].z + dis
			, p[i].x - p[i].y + p[i].z - dis, p[i].x - p[i].y + p[i].z + dis
			, p[i].x + p[i].y - p[i].z - dis, p[i].x + p[i].y - p[i].z + dis); 
	for (int i = 0; i <= 1; i++)
	{
		limit tmp(div(cur.smin - 3 * i + 1), div(cur.smax - 3 * i)
			, div(cur.amin - i + 1), div(cur.amax - i)
			, div(cur.bmin - i + 1), div(cur.bmax - i)
			, div(cur.cmin - i + 1), div(cur.cmax - i)); 
		point res = solve(tmp); 
		if (check(res))
			return point(i + res.y + res.z, i + res.x + res.z, i + res.x + res.y); 
	}
	return INFp; 
}
int main()
{
	// freopen("C.in", "r", stdin); 
	int t; 
	scanf("%d", &t); 
	while (t--)
	{
		scanf("%d", &n); 
		for (int i = 0; i < n; i++)
			scanf("%lld%lld%lld", &p[i].x, &p[i].y, &p[i].z); 
		ll l = -1, r = 3e18, ans; 
		while (l <= r)
		{
			ll m = (l + r) / 2; 
			// cout << m << endl; 
			if (check(calc(m)))
			{
				ans = m; 
				r = m - 1; 
			}
			else
				l = m + 1; 
		}
		point res = calc(ans); 
		printf("%lld %lld %lld\n", res.x, res.y, res.z);
	}
	return 0; 
}