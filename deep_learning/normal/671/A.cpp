#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std; 
double x[100005], y[100005], dis[100005][5]; 
inline double calc(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); 
}
int main()
{
	// freopen("A.in", "r", stdin); 
	double xa, ya, xb, yb, xt, yt; 
	scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xt, &yt); 
	double tot = 0, mna = 1e18, mna2 = 1e18, mnb = 1e18, mnb2 = 1e18; 
	int n, pa = 0, pa2 = 0, pb = 0, pb2 = 0; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf", x + i, y + i); 
		dis[i][0] = calc(x[i], y[i], xt, yt) * 2; 
		tot += dis[i][0]; 
		dis[i][1] = calc(x[i], y[i], xa, ya) - calc(x[i], y[i], xt, yt); 
		dis[i][2] = calc(x[i], y[i], xb, yb) - calc(x[i], y[i], xt, yt); 
		if (dis[i][1] < mna)
		{
			mna2 = mna; 
			pa2 = pa; 
			mna = dis[i][1]; 
			pa = i; 
		}
		else if (dis[i][1] < mna2)
		{
			mna2 = dis[i][1]; 
			pa2 = i; 
		}
		if (dis[i][2] < mnb)
		{
			mnb2 = mnb; 
			pb2 = pb; 
			mnb = dis[i][2]; 
			pb = i; 
		}
		else if (dis[i][2] < mnb2)
		{
			mnb2 = dis[i][2]; 
			pb2 = i; 
		}
	}
	double ans = min(tot + mna, tot + mnb); 
	for (int i = 0; i < n; i++)
	{
		ans = min(ans, tot + dis[i][1] + (pb == i ? mnb2 : mnb)); 
		ans = min(ans, tot + dis[i][2] + (pa == i ? mna2 : mna)); 
	}
	printf("%.12lf\n", ans);
	return 0; 
}