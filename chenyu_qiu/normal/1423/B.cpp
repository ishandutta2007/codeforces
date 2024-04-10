#include<cstdio>
#include<cstring>
const int N=1E4+1,M=1E5+1;
int read()
{
	int a=0;char b=1,c;
	do if((c=getchar())==45)b=-1;while(!(c&16));
	do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16);
	return a*b;
}
void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	char a[10],s=0;
	do a[s++]=x%10|48;while(x/=10);
	do putchar(a[--s]);while(s); 
}
int head[N],nex[M],to[M],d[M],p[N],a[N],b[N];bool k[N];
bool dfs(int x)
{
    for(int i=head[x];i;i=nex[i])if(!k[to[i]])
    {
        k[to[i]]=true;
        if(!p[to[i]]||dfs(p[to[i]])){p[to[i]]=x;return true;}
    }
    return false;
}
int main()
{
	int n=read(),m=read(),ans=0;
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=read();
		nex[i]=head[u],head[u]=i,to[i]=v,d[i]=w;
		if(!a[u]||a[u]>w)a[u]=w;
		if(!b[v]||b[v]>w)b[v]=w;
	}
	int i=1;
	for(;i<=n&&dfs(i);++i)memset(k,0,sizeof k);
	if(i<=n){puts("-1");return 0;}
	for(i=1;i<=n;++i)
	{
		if(a[i]>ans)ans=a[i];
		if(b[i]>ans)ans=b[i];
	}
	write(ans);
	return 0;
}