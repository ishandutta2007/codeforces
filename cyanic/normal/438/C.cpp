#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;

const int maxn = 209;
const int MOD = 1e9+7;
struct point { LL x, y; } p[maxn], t[maxn], o;
LL f[maxn][maxn], n;

inline LL read(){
	char ch = getchar(); LL x = 0, f = 1;
	while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

LL cross(point p, point a, point b){
	return (a.x-p.x)*(b.y-p.y)-(a.y-p.y)*(b.x-p.x);
}

void init(){
	LL tmp = 0; o.x = 0; o.y = 0; p[n+1] = p[1]; 
	for (int i=1; i<=n; i++)
		tmp += cross(o, p[i], p[i+1]);
	if (tmp < 0){
		for (int i=1; i<=n; i++) t[i] = p[n-i+1];
		for (int i=1; i<=n; i++) p[i] = t[i];
	}
}
/*
6
0 0
1 0
1 1
0 1
-3 -1
-2 -1
*/
int main(){
	int r; n = read();
	for (int i=1; i<=n; i++) { p[i].x = read(); p[i].y = read(); }
	init(); memset(f, 0, sizeof f);
	for (int i=1; i<=n-1; i++) f[i][i+1] = 1;
	for (int len=3; len<=n; len++)
		for (int l=1; (r=l+len-1)<=n; l++){
			for (int k=l+1; k<=r-1; k++)
				if (cross(p[l], p[r], p[k]) < 0)
					f[l][r] = (f[l][r] + f[l][k] * f[k][r]) % MOD;
			//printf("%d %d  %lld\n", l, r, f[l][r]);
		}
	printf("%I64d\n", f[1][n]%MOD);
	return 0;
}