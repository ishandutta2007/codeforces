#include<cstdio>
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 1000
#define MX 1000000
int u[MN*2+5],t[MN+5],tn,d[MX*2+5],q[MX*2+5],qn;
int main()
{
	fread(B,1,1<<26,stdin);
	int n,k,i,j,x,o1=1,o2=1;
	n=read();k=read();
	for(i=1;i<=k;++i)
	{
		if(!(x=read()-n))return 0*puts("1");
		if(x<0)o1=0;
		if(x>0)o2=0;
		if(!u[x+MN])u[x+MN]=1,t[++tn]=x;
	}
	if(o1||o2)return 0*puts("-1");
	for(i=1;i<=tn;++i)d[q[++qn]=t[i]+MX]=1;
	for(i=1;i<=qn;++i)
	{
		if(q[i]==MX)return 0*printf("%d",d[MX]);
		for(j=1;j<=tn;++j)
		{
			x=q[i]+t[j];
			if(x<0||x>MX*2||d[x])continue;
			d[q[++qn]=x]=d[q[i]]+1;
		}
	}
}