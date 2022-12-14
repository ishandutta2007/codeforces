#include <cstdio>
#include <cstring>
#include <algorithm>

const double eps = 1e-9;

double dp[1024][1024];
double rr[1024][1024];

double getDP(int, int);

double x;
double om, on;

inline double evalBluf(int n, int m, double bp)
{
	double p = bp / (bp + (1.0 - bp) * om);
	double px = p * x;
	if (on > 1.0 - p && on > p * x)
		return on;
	if (1.0 - p > px)
		return 1.0 - p;
	return px;
}

double my;

inline double eval(int n, int m, double bp)
{
	double eb = 1.0 - evalBluf(n, m, bp);
	return bp * (eb) + (1.0 - bp) * om * (eb + my);
}

inline double getDP(int n, int m)
{
	//~ if (dp[n][m] == dp[n][m])
		//~ return dp[n][m];
	if (m == 0)
	{
		return (dp[n][m] = 1.0);
	}
	if (n == 0)
	{
		return (dp[n][m] = 1.0 / (m + 1));
	}
	
	x = dp[m][n - 1];
	my = m * (1.0 - dp[m - 1][n]);
	om = 1.0 / (m + 1);
	on = 1.0 / (n + 1);
	dp[n][m] = om;
	double l, r;
	if (m <= 130 || n <= 130)
		l = 0.0, r = 1.0;
	else
		l = rr[n][m-1] - 0.001, r = rr[n][m-1] + 0.001;
	if (l < 0)
		l = 0;
	if (r > 1)
		r = 1;
	double dif = r - l;
	while (dif > eps)
	{
		double st = dif / 3;
		double m1 = l + st, m2 = r - st;
		if (eval(n, m, m1) < eval(n, m, m2))
			l = m1;
		else
			r = m2;
		dif -= st;
	}
	dp[n][m] = std::max(dp[n][m], eval(n, m, r));
	rr[n][m] = r;
	//~ printf("DP %d %d %lf [%.10lf]\n", n, m, dp[n][m], r);
	return dp[n][m];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	int n, m;
	scanf("%d %d", &n, &m);
	int mx = std::max(n, m);
	for (int i = 0; i <= 2 * mx; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (i - j > mx || j > mx)
				continue;
			getDP(j, i - j);
		}
	}
	double swin = getDP(n, m);
	printf("%.11lf %.11lf\n", swin, 1.0 - swin);
	return 0;
}