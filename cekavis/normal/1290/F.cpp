#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 5, M = 1<<N, K = 31, S = N*4+1, P = 998244353;
int n, m, s, mm, x[N], y[N], a[M], b[M], c[M], d[M], f[K][S][S][S][S][2][2];
void upd(int &x, int y){ (x+=y)%=P;}
int main() {
	scanf("%d%d", &n, &m), mm=__lg(m), s=(1<<n)-1;
	for(int i=0; i<n; ++i) scanf("%d%d", x+i, y+i);
	for(int i=0; i<1<<n; ++i) for(int j=0; j<n; ++j) if(i>>j&1)
		(x[j]<0?a:b)[i]+=abs(x[j]), (y[j]<0?c:d)[i]+=abs(y[j]);
	f[0][0][0][0][0][0][0]=1;
	for(int i=0; i<=mm; ++i)
		for(int x=0; x<=a[s]; ++x) for(int X=0; X<=b[s]; ++X)
			for(int y=0; y<=c[s]; ++y) for(int Y=0; Y<=d[s]; ++Y)
				for(int j=0; j<2; ++j) for(int k=0; k<2; ++k)
					for(int t=0; t<1<<n; ++t){
						int xx=x+a[t], XX=X+b[t], yy=y+c[t], YY=Y+d[t];
						if(!((xx^XX)&1) && !((yy^YY)&1))
							upd(f[i+1][xx/2][XX/2][yy/2][YY/2][(xx&1)+j>(m>>i&1)][(yy&1)+k>(m>>i&1)], f[i][x][X][y][Y][j][k]);
					}
	printf("%d\n", (f[mm+1][0][0][0][0][0][0]+P-1)%P);
	return 0;
}