#include<cstdio>
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 100000
#define MV 200000
struct edge{int nx,t;}e[MV*2+5];
int r[MN+5],a[MN+5],b[MN+5];
int h[MV+5],en,l[MV+5],d[MV+5],cnt,z[MV+5],zn,inz[MV+5],f[MV+5],fn;
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void tj(int x)
{
	l[x]=d[x]=++cnt;inz[z[zn++]=x]=1;
	for(int i=h[x];i;i=e[i].nx)
	{
		if(!d[e[i].t])tj(e[i].t);
		if(inz[e[i].t]&&l[e[i].t]<l[x])l[x]=l[e[i].t];
	}
	if(l[x]==d[x])for(++fn;z[zn]!=x;inz[z[zn]]=0)f[z[--zn]]=fn;
}
int main()
{
	fread(B,1,1<<26,stdin);
	int n,m,i,j,k;
	n=read();m=read();
	for(i=1;i<=n;++i)r[i]=read();
	for(i=1;i<=m;++i)for(j=read();j--;)(a[k=read()]?b[k]:a[k])=i;
	for(i=1;i<=n;++i)
		if(r[i])ins(a[i],b[i]),ins(a[i]+m,b[i]+m);
		else ins(a[i],b[i]+m),ins(a[i]+m,b[i]);
	for(i=1;i<=m<<1;++i)if(!d[i])tj(i);
	for(i=1;i<=m;++i)if(f[i]==f[i+m])return puts("NO"),0;
	puts("YES");
}