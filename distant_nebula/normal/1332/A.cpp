#include <cstdio>
#include <algorithm>
int T, a, b, c, d, x, y, x1, y1, x2, y2;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);
		if((x1==x2&&(a||b))||(y1==y2&&(c||d))) puts("NO");
		else if(x-a+b<x1||x-a+b>x2||y-c+d<y1||y-c+d>y2) puts("NO");
		else puts("YES");
	}
	return 0;
}