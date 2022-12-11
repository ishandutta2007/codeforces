#include<cstdio>
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
int f[61];
int main()
{
	fread(B,1,1<<26,stdin);
	int n=read(),i,j,k,ans=0;
	for(i=1;i<=10;++i)
		for(j=i*(i+1)/2;j<=60&&j<(i+1)*(i+2)/2;++j)f[j]=i;
	for(i=1;i<=n;++i)ans^=f[read()];
	puts(ans?"NO":"YES");
}