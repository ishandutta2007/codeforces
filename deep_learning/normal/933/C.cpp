#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define pb push_back
typedef long double decimal; 
const decimal eps = 1e-12; 
struct point
{
	decimal x, y; 
	point(decimal _x = 0, decimal _y = 0)
	{
		x = _x; 
		y = _y; 
	}
	inline void input()
	{
		std::cin >> x >> y; 
	}
	friend inline decimal dis(const point &a, const point &b)
	{
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); 
	}
	inline bool operator <(const point &a) const
	{
		if (std::abs(x - a.x) <= eps)
			return y < a.y; 
		return x < a.x; 
	}
	inline bool operator ==(const point &a) const
	{
		return std::abs(x - a.x) <= eps && std::abs(y - a.y) <= eps; 
	}
}; 
typedef std::vector<point> vp; 
struct circle
{
	point o; 
	decimal r; 
	inline void input()
	{
		o.input(); 
		std::cin >> r; 
	}
	friend inline vp operator &(const circle &a, const circle &b)
	{
		decimal d = dis(a.o, b.o); 
		if (d > a.r + b.r + eps || d < std::abs(a.r - b.r) - eps)
			return vp(); 
		decimal alpha = atan2(b.o.y - a.o.y, b.o.x - a.o.x); 
		decimal delta = (a.r * a.r + d * d - b.r * b.r) / (a.r * d * 2); 
		delta = acos(std::max((decimal)-1.0, std::min(delta, (decimal)1.0))); 
		return vp({point(a.o.x + cos(alpha + delta) * a.r, a.o.y + sin(alpha + delta) * a.r)
				, point(a.o.x + cos(alpha - delta) * a.r, a.o.y + sin(alpha - delta) * a.r)}); 
	}
} cyc[2005]; 
struct DSU
{
	int fa[2005]; 
	inline void init(int n)
	{
		for (int i = 0; i < n; i++)
			fa[i] = i; 
	}
	int getfa(int u)
	{
		if (u == fa[u])
			return u; 
		return fa[u] = getfa(fa[u]); 
	}
	inline void unite(int u, int v)
	{
		fa[getfa(u)] = getfa(v); 
	}
} dsu; 
int main()
{
	// freopen("933C.in", "r", stdin); 
	std::ios::sync_with_stdio(false); 
	std::cin.tie(0); 
	std::cout.tie(0); 
	int n; 
	std::cin >> n; 
	for (int i = 0; i < n; i++)
		cyc[i].input(); 
	vp app; 
	dsu.init(n); 
	int v = 0, e = 0, c = 0; 
	for (int i = 0; i < n; i++)
	{
		vp vec; 
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue; 
			vp res = cyc[i] & cyc[j]; 
			if (res.size())
				dsu.unite(i, j); 
			for (auto &x : res)
			{
				vec.pb(x); 
				app.pb(x); 
			}
		}
		std::sort(vec.begin(), vec.end()); 
		e += std::unique(vec.begin(), vec.end()) - vec.begin(); 
	}
	std::sort(app.begin(), app.end()); 
	v = std::unique(app.begin(), app.end()) - app.begin(); 
	for (int i = 0; i < n; i++)
		c += dsu.fa[i] == i; 
	std::cout << e - v + c + 1 << std::endl; 
	return 0; 
}