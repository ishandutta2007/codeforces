#include<cstdio>
int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-f;
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
#define MAXN 500000
char t[MAXN+5];
int X[MAXN+5],Y[MAXN+5],f[8];
int main()
{
	int n=read(),x,y,i;
	x=read();y=read();
	for(i=1;i<=n;i++)
	{
		do t[i]=getchar();while(t[i]!='B'&&t[i]!='R'&&t[i]!='Q');
		X[i]=read();Y[i]=read();
	}
	for(i=1;i<=n;i++)
	{
		if(X[i]==x&&Y[i]<y)if(f[0]<1||Y[i]>Y[f[0]])f[0]=i;
		if(X[i]==x&&Y[i]>y)if(f[1]<1||Y[i]<Y[f[1]])f[1]=i;
		if(X[i]<x&&Y[i]==y)if(f[2]<1||X[i]>X[f[2]])f[2]=i;
		if(X[i]>x&&Y[i]==y)if(f[3]<1||X[i]<X[f[3]])f[3]=i;
		if(X[i]-Y[i]==x-y&&X[i]<x)if(f[4]<1||X[i]>X[f[4]])f[4]=i;
		if(X[i]-Y[i]==x-y&&X[i]>x)if(f[5]<1||X[i]<X[f[5]])f[5]=i;
		if(X[i]+Y[i]==x+y&&X[i]<x)if(f[6]<1||X[i]>X[f[6]])f[6]=i;
		if(X[i]+Y[i]==x+y&&X[i]>x)if(f[7]<1||X[i]<X[f[7]])f[7]=i;
	}
	for(i=0;i<4;i++)if(f[i]&&(t[f[i]]=='R'||t[f[i]]=='Q'))return 0*puts("YES");
	for(;i<8;i++)if(f[i]&&(t[f[i]]=='B'||t[f[i]]=='Q'))return 0*puts("YES");
	puts("NO");
}