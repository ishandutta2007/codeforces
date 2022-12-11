#include<cstdio>
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 7000
int n,s[2],t[2][MN+5],u[MN*2+5],q[MN*2+5],l[MN*2+5],qn;
int d(int x,int y){return x*n+(y+n)%n;}
void lose(int);
void win(int p)
{
	int x=p/n,y=p%n,i,v;
	x^=1;u[p]=2;
	for(i=1;i<=s[x];++i)
	{
		v=d(x,y-t[x][i]);
		if(!u[v]&&++l[v]==s[x])lose(v);
	}
}
void lose(int p)
{
	int x=p/n,y=p%n,i,v;
	x^=u[p]=1;
	for(i=1;i<=s[x];++i)
	{
		v=d(x,y-t[x][i]);
		if(!u[v])win(v);
	}
}
int main()
{
	fread(B,1,1<<26,stdin);
	int i,x,y;
	for(n=read(),x=0;x<2;++x)for(s[x]=read(),i=1;i<=s[x];++i)t[x][i]=read();
	u[n]=1;lose(0);lose(n);
	for(i=1;i<n;++i)printf("%s ",u[i]?u[i]>1?"Win":"Lose":"Loop");puts("");
	for(i=1;i<n;++i)printf("%s ",u[i+n]?u[i+n]>1?"Win":"Lose":"Loop");
}