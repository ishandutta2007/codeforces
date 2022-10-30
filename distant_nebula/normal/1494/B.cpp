#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 55
int T, n, u, r, d, l;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%d%d", &n, &u, &r, &d, &l);
		if((u==n||d==n)&&(!l||!r)) { puts("NO"); continue; }
		if((u==n&&d==n)&&(l<=1||r<=1)) { puts("NO"); continue; }
		if((l==n||r==n)&&(!u||!d)) { puts("NO"); continue; }
		if((l==n&&r==n)&&(u<=1||d<=1)) { puts("NO"); continue; }
		if((u>=n-1||d>=n-1)&&(!l&&!r)) { puts("NO"); continue; }
		if((l>=n-1||r>=n-1)&&(!u&&!d)) { puts("NO"); continue; }
		if((u+d)>=2*n-1&&(l+r)<3) { puts("NO"); continue; }
		if((u+d)>=2*n-2&&(l+r)<2) { puts("NO"); continue; }
		if((u+d)>=2*n-3&&(l+r)<1) { puts("NO"); continue; }
		if((l+r)>=2*n-1&&(u+d)<3) { puts("NO"); continue; }
		if((l+r)>=2*n-2&&(u+d)<2) { puts("NO"); continue; }
		if((l+r)>=2*n-3&&(u+d)<1) { puts("NO"); continue; }
		puts("YES");
	}
	return 0;
}