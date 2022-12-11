#include<cstdio>
#include<cstring>
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 100000
int a[2][1030];
int main()
{
	fread(B,1,1<<26,stdin);
	int n,k,x,i,p,q,l;
	n=read();k=read();x=read();
	for(i=1;i<=n;++i)++a[0][read()];
	for(p=1,q=0;k--;p^=1,q^=1)
	{
		memset(a[p],0,sizeof(a[p]));
		for(i=l=0;i<1024;++i)
		{
			a[p][i]+=a[q][i]+l>>1;
			a[p][i^x]+=a[q][i]+(l^1)>>1;
			l^=a[q][i]&1;
		}
	}
	for(i=1024;i--;)if(a[q][i])break;printf("%d ",i);
	for(i=0;i<1024;++i)if(a[q][i])break;printf("%d",i);
}