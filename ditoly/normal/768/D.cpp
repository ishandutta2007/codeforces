#include<cstdio>
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 1000
double f[MN*10+5][MN+5];
int main()
{
	fread(B,1,1<<26,stdin);
	int k=read(),q,i,j,x;
	for(f[1][1]=i=1;i<=10000;++i)for(j=1;j<=i&&j<=k;++j)
	{
		f[i+1][j]+=f[i][j]*j/k;
		f[i+1][j+1]+=f[i][j]*(k-j)/k;
	}
	for(q=read();q--;)
	{
		x=read();
		for(i=1;i<=10000;++i)if(f[i][k]>=(x-1e-7)/2000)break;
		printf("%d\n",i);
	}
}