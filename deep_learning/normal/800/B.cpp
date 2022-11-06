#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std; 
struct Point
{
	double x, y; 
	Point()
	{
	}
	Point(double _x, double _y)
	{
		x = _x; 
		y = _y; 
	}
} point[1005]; 
struct Vector
{
	double x, y; 
	Vector()
	{
	}
	Vector(Point a, Point b)
	{
		x = a.x - b.x; 
		y = a.y - b.y; 
	}
	inline double operator *(const Vector &a) const
	{
		return x * a.y - y * a.x; 
	}
}; 
inline double dist(const Point &a, const Point &b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); 
}
int main()
{
	// freopen("800B.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		int x, y; 
		scanf("%d%d", &x, &y); 
		point[i] = Point(x, y); 
	}
	double ans = 1e18; 
	for (int i = 0; i < n; i++)
		ans = min(ans, (Vector(point[(i + 1) % n], point[i]) * Vector(point[(i + 1) % n], point[(i + 2) % n])
		 / dist(point[i], point[(i + 2) % n])) / 2); 
	printf("%.8lf\n", ans);
	return 0; 
}