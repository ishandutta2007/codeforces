#include <cstdio>
int k, a[5][5], b;
inline int gl(int x) { int ret=0; while(x) ++ret, x>>=1; return ret; }
int main()
{
	scanf("%d", &k);
	if(!k) return puts("1 1\n0");
	puts("3 3");
	b=1<<gl(k);
	a[1][1]=a[2][2]=a[2][3]=k|b;
	a[3][3]=a[1][2]=k;
	for(int i=1; i<=3; ++i) for(int j=1; j<=3; ++j) if(!a[i][j]) a[i][j]=b;
	for(int i=1; i<=3; ++i, puts("")) for(int j=1; j<=3; ++j) printf("%d ", a[i][j]);
	return 0;
}