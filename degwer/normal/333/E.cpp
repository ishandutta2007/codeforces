#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef pair<double, double>pdd;
double getd(pdd a, pdd b)
{
	return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}
int ccw(pdd a, pdd b, pdd c)
{
	if ((b.first - a.first)*(c.second - b.second) - (b.second - a.second)*(c.first - b.first) < 0)return 1;
	else return -1;
}
pdd d[3000];
double dist[3000][3000];
int v1[3000], v2[3000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%lf%lf", &d[i].first, &d[i].second);
	sort(d, d + num);
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)dist[i][j] = getd(d[i], d[j]);
	double beg = 0.0, end = 100000.0;
	for (int p = 0; p < 35; p++)
	{
		double med = (beg + end) / 2;
		bool flag = false;
		for (int q = 0; q < num; q++)
		{
			int pt1 = 0, pt2 = 0;
			for (int i = 0; i < num; i++)
			{
				if (dist[q][i] < med)continue;
				for (;;)
				{
					if (pt1 <= 1)break;
					pdd a = d[v1[pt1 - 2]], b = d[v1[pt1 - 1]];
					if (ccw(a, b, d[i]) != 1)pt1--;
					else break;
				}
				v1[pt1++] = i;
			}
			for (int i = 0; i < num; i++)
			{
				if (dist[q][i] < med)continue;
				for (;;)
				{
					if (pt2 <= 1)break;
					pdd a = d[v2[pt2 - 2]], b = d[v2[pt2 - 1]];
					if (ccw(a, b, d[i]) != -1)pt2--;
					else break;
				}
				v2[pt2++] = i;
			}
			for (int i = pt2 - 2; i >= 1; i--)v1[pt1++] = v2[i];
			int zn = pt1;
			if (zn <= 1)continue;
			double maxi = 0.0;
			int pt = 1;
			for (int i = 0; i < zn; i++)
			{
				for (;;)
				{
					if (pt == zn)pt = 0;
					int n = pt + 1;
					if (n == zn)n = 0;
					if (dist[v1[i]][v1[pt]] < dist[v1[i]][v1[n]])pt++;
					else break;
				}
				maxi = max(maxi, dist[v1[i]][v1[pt]]);
			}
			if (maxi > med)
			{
				flag = true;
				break;
			}
		}
		if (flag)beg = med;
		else end = med;
	}
	printf("%.10lf\n", beg / 2);
}