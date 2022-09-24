#include <bits/stdc++.h>

using namespace std;

double dp[2020][2020];
bool chk[2020][2020];
int R[2020], C[2020];
int n, m;

double f(int x, int y)
{
	if(x < 0 || y < 0 || x + y == 0) return 0;
	if(chk[x][y]) return dp[x][y];
	
	chk[x][y] = 1;
	
	double ret, a, b, c, d;
	
	a = (double)((n - x) * (n - y)) / (n * n);
	b = (double)((n - x) * y) / (n * n);
	c = (double)(x * (n - y)) / (n * n);
	d = (double)(x * y) / (n * n);
	
	ret = 1 / (1 - a) + (b * f(x, y - 1) + c * f(x - 1, y) + d * f(x - 1, y - 1)) / (b + c + d);
	
	return dp[x][y] = ret;
}

int main()
{
	int i, a, b, r, c;

	scanf("%d%d", &n, &m);
	
	for(i=1; i<=m; i++){
		scanf("%d%d", &a, &b);
		R[a] = 1;
		C[b] = 1;
	}
	
	r = 0, c = 0;
	
	for(i=1; i<=n; i++){
		if(R[i] == 0) r ++;
		if(C[i] == 0) c ++;
	}
	
	printf("%.12lf\n", f(r, c));
	
	return 0;
}