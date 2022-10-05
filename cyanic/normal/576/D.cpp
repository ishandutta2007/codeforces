#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 155;
struct trip{
	int a, b, d;
	bool operator < (const trip &t) const{
		return d < t.d;
	}
} x[maxn];
int n, m, ans = 2e9+1, d[maxn][maxn];
 
struct Matrix{
	bitset<maxn> mat[maxn];
	void identity() { for (int i=0; i<n; i++) mat[i].set(i); }
	Matrix operator * (const Matrix &a) const{
		Matrix res;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (mat[i][j]) res.mat[i] |= a.mat[j];
		return res;
	}
	Matrix operator ^ (const int &_p) const{
		Matrix res, pow = (*this);
		int p = _p; res.identity();
		while (p){
			if (p & 1) res = res * pow;
			pow = pow * pow; p >>= 1;
		}
		return res;
	}
} A, B, G;
 
int main(){
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++) 
		scanf("%d%d%d", &x[i].a, &x[i].b, &x[i].d);
	sort(x+1, x+m+1); x[0].d = 0;
	G.identity(); 
	memset(d, 0x3f, sizeof d);
	for (int i=1; i<=n; i++) d[i][i] = 0;
	
	for (int i=1; i<=m; i++){
		for (int u=1; u<=n; u++)
			for (int v=1; v<=n; v++)
				d[u][v] = min(d[u][v], d[u][x[i].a] + 1 + d[x[i].b][v]);
		B = A ^ (x[i].d - x[i-1].d);
		G = B * G; 
		for (int j=1; j<=n; j++)
			if (G.mat[j-1][0] && d[j][n] <= 1e9)
				ans = min(ans, x[i].d+d[j][n]);
		A.mat[x[i].b-1][x[i].a-1] = 1;
	}
	if (ans >= 2e9+1) puts("Impossible");
	else printf("%d\n", ans);
	
	return 0;
}