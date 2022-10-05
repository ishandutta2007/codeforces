#include<bits/stdc++.h>
using namespace std;
typedef long double LD;

const int maxn = 1009;
const LD eps = 1e-10;
struct point { 
	LD x, y; 
} p[maxn];
int n, l, r;
LD L, R, Y, k, b;

int fcmp(LD x) 
{
	if (fabs(x) < eps) return 0;
	return x > 0 ? 1 : -1;
}

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%Lf%Lf", &p[i].x, &p[i].y);
	p[n + 1] = p[1];
	L = p[1].x; 
	R = p[2].x;
	Y = p[1].y;
	if (p[3].y > Y) 
	{
		swap(p[1], p[2]);
		for (int i = 3; i <= n; i++)
			if (p[i].y > Y) p[i].y = 2 * Y - p[i].y;
		for (int i = 3; i < n + 3 - i; i++)
			swap(p[i], p[n + 3 - i]);
		L = p[1].x; R = p[2].x;
		p[n + 1] = p[1];
	}
	for (int i = 2; i <= n; i++)
		if (fcmp(p[i + 1].x - p[i].x) == 0) 
		{
			if (fcmp(p[i + 1].y - p[i].y) < 0)
				R = min(R, p[i].x);
			else
				L = max(L, p[i].x);
		}
		else if (fcmp(p[i + 1].y - p[i].y) < 0) 
			R = min(R, (Y - p[i].y + (p[i + 1].y - p[i].y) * p[i].x / (p[i + 1].x - p[i].x)) * (p[i + 1].x - p[i].x) / (p[i + 1].y - p[i].y));
		else if (fcmp(p[i + 1].y - p[i].y) > 0) 
			L = max(L, (Y - p[i].y + (p[i + 1].y - p[i].y) * p[i].x / (p[i + 1].x - p[i].x)) * (p[i + 1].x - p[i].x) / (p[i + 1].y - p[i].y));
		else if (fcmp(p[i + 1].x - p[i].x) > 0)
			L = R + 1;
	l = ceil(L - eps); 
	r = floor(R + eps);
	printf("%d\n", max(r - l + 1, 0));
	return 0;
}