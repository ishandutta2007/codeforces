#include<cstdio>
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 100
int u[MN+5];
int main()
{
	fread(B,1,1<<26,stdin);
	int n,k,i,x,s=0;
	n=read();k=read();
	for(i=0;i<k;++i)
	{
		for(x=read()%(n-i)+1;x--;)while(u[++s>n?s=1:s]);
		u[s]=1;printf("%d ",s);
	}
}