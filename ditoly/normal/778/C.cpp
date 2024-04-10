#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 600000
int n,c[MN+5][26],f[MN+5],cnt,tn;
int merge(int x,int y)
{
	if(!x)return y;if(!y)return x;
	int r=++tn;++cnt;
	for(int i=0;i<26;++i)c[r][i]=merge(c[x][i],c[y][i]);
	return r;
}
void dfs(int x,int d)
{
	int i,rt=++(tn=n);cnt=0;
	for(i=0;i<26;++i)if(c[x][i])rt=merge(rt,c[x][i]);
	f[d]+=cnt;
	for(i=0;i<26;++i)if(c[x][i])dfs(c[x][i],d+1);
}
int main()
{
	int i,x,y;
	for(n=read(),i=1;i<n;++i)x=read(),y=read(),c[x][getchar()-'a']=y;
	dfs(1,1);
	for(i=1,x=0;i<=n;++i)if(f[i]>x)x=f[i],y=i;
	printf("%d\n%d",n-x,y);
}