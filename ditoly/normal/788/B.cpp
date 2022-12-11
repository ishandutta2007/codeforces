#include<cstdio>
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 1000000
int f[MN+5],r[MN+5],u[MN+5];
int gf(int k){return f[k]?f[k]=gf(f[k]):k;}
int main()
{
	fread(B,1,1<<26,stdin);
	int n,m,x,y,i,cnt=1,s=0;long long ans=0;
	n=read();m=read();
	for(i=1;i<=m;++i)
	{
		x=read();y=read();
		if(x==y)++s,u[x]=1;
		else ++r[x],++r[y];
		if(gf(x)!=gf(y))++cnt,f[gf(x)]=gf(y);
	}
	for(i=1;i<=n;++i)if(!u[i]&&!r[i])++cnt;
	if(cnt<n)return 0*puts("0");
	for(i=1;i<=n;++i)ans+=1LL*r[i]*(r[i]-1)>>1;
	ans+=1LL*s*(m-s)+(1LL*s*(s-1)>>1);
	printf("%I64d",ans);
}