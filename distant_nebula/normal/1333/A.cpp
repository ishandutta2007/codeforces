#include <cstdio>
#include <algorithm>
#define N 105
int T, n, m, a[N][N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		if(n==2&&m==2) { puts("BB\nBW"); continue; }
		if(n&m&1) for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) a[i][j]=(i+j)&1;
		else
		{
			for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) a[i][j]=0;
			if((!(n&1))&&m!=2)
			{
				for(int i=1; i<n-1; i+=2) for(int j=1; j<=m; ++j) a[i][j]=1;
				a[n-1][2]=a[n][1]=1;
			} else if(!(m&1))
			{
				for(int i=1; i<=n; ++i) for(int j=1; j<m-1; j+=2) a[i][j]=1;
				a[2][m-1]=a[1][m]=1;
			}
		}
		for(int i=1; i<=n; ++i, puts("")) for(int j=1; j<=m; ++j) putchar(a[i][j]?'W':'B');
	}
	return 0;
}