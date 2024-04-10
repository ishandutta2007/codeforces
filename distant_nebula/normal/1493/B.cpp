#include <cstdio>
#include <algorithm>
int T, h, m, sx, sy, tab[10]={0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
char tmp;
inline int decomp(int x, int d)
{
	int ret=0;
	for(int i=0; i<d; ++i)
	{
		if(tab[x%10]<0) return -1;
		ret=ret*10+tab[x%10];
		x/=10;
	}
	return ret;
//	if(x<10) return tab[x]<0?-1:(d>1?tab[x]*10:tab[x]);
//	return (tab[x%10]<0||tab[x/10]<0)?-1:tab[x/10]+tab[x%10]*10;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%c%d", &h, &m, &sx, &tmp, &sy);
		int cur=sx*m+sy;
		for(int t=0; t<=h*m; ++t, ++cur)
		{
			if(cur>=h*m) cur-=h*m;
			int i=cur/m, j=cur%m;
			int x=decomp(j, 2), y=decomp(i, 2);
			if(x<0||y<0||x>=h||y>=m) continue;
				if(i<10) printf("0%d", i);
				else printf("%d", i);
			putchar(':');
				if(j<10) printf("0%d", j);
				else printf("%d", j);
			puts("");
			goto out;
		}
		out:;
	}
	return 0;
}