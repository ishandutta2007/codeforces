#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main()
{
	int n;
	double a, b, x, y, v, ans = 1e9;

	cin >> a >> b >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y >> v;
		ans = min(ans, dist(a, b, x, y)/v);
	}

	cout << fixed << setprecision(7) << ans;
}