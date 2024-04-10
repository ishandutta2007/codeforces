#include <bits/stdc++.h>
#define N 135

using namespace std;

struct matrix{
	int x,y;
	double a[N][N];
	matrix(){}
	matrix(int _x,int _y):x(_x),y(_y){
		memset(a,0,sizeof(a));
	}
	matrix(int _sz):x(_sz),y(_sz){
		memset(a,0,sizeof(a));
		for (int i=0;i<=_sz;++i) a[i][i]=1;
	}
} A;
inline matrix operator *(const matrix &u,const matrix &v){
	matrix ret=matrix(u.x,v.y);
	int z=u.y;
	for (int i=0;i<=ret.x;++i)
		for (int j=0;j<=ret.y;++j)
			for (int k=0;k<=z;++k)
				ret.a[i][j]+=u.a[i][k]*v.a[k][j];
	return ret;
}
matrix fast_pow(matrix x,int y){
	matrix ret=matrix(x.x);
	while (y){
		if (y&1) ret=ret*x;
		x=x*x;
		y=y>>1;
	}
	return ret;
}


double p[N];
int l,n;

int main(){
	scanf("%d%d",&l,&n);
	memset(p,0,sizeof(p));
	for (int i=0;i<=n;++i) scanf("%lf",&p[i]);
	n=127;
	A=matrix(n,n);
	for (int i=0;i<=n;++i)
		for (int j=0;j<=n;++j)
			A.a[i^j][i]=p[j];
	A=fast_pow(A,l);
	printf("%.8f\n",1.0-A.a[0][0]);
	return 0;
}