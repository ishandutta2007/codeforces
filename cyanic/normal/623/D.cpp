/*
n(100)
pi%pi%=1


10e6


fi,jij

gii 
gi=nj=1fi,j.

Ans=+i=1i(gigi1) 
igigi1

fi,jfi1,j 
1)fi,j=fi1,j,ij. 
2)fi,j=fi1,j+(1fi1,j)pj,ij.

gi=gi1fi,j/fi1,j 
fi,j/fi1,j

3105106
*/
#include<bits/stdc++.h>
using namespace std;
typedef long double LD;

const int maxn = 102;
const int limit = 300009;
const LD eps = 1e-15;
LD f[2][maxn], g[2], p[maxn], ans, best, t;
int n, last = 0, now = 1, w;

int main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		cin >> p[i]; p[i] /= 100;
	}
	for (int i=1; i<=limit; i++){
		best = t = 0;
		for (int j=1; j<=n; j++){
			t = (1-f[last][j]) * p[j] / f[last][j];
			if (t > best) { best = t; w = j; }
		}
		for (int j=1; j<=n; j++)
			if (j == w) f[now][j] = f[last][j] + (1-f[last][j]) * p[j];
			else f[now][j] = f[last][j];
		if (f[last][w] < eps){
			g[now] = 1;
			for (int j=1; j<=n; j++)
				g[now] = g[now] * f[now][j];
		}
		else g[now] = g[last] * f[now][w] / f[last][w];
		ans = ans + (g[now] - g[last]) * i;
		last ^= 1; now ^= 1;			
	}
	double res = ans;
	printf("%.16lf\n", res);
	return 0;
}