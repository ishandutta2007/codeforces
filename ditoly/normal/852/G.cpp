#include<iostream>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bitset<5000005> vis[52];
char st[1005];
int n,m,c[5000005][5],cnt=1,val[5000005],now=0,L;

void Emp(int x,int y)
{
	if(!x) return;
	if(!vis[y][x]) return;
	vis[y][x]=0;
	if(y>L) return;	
	if(st[y]=='?') 
	{
		Emp(x,y+1);
		for(int i=0;i<5;++i) Emp(c[x][i],y+1);
		return;
	}
	Emp(c[x][st[y]-'a'],y+1);
}

int dfs(int x,int y)
{
	if(!x) return 0;
	if(vis[y][x]) return 0;
	vis[y][x]=1;
	if(y>L) return val[x];	
	if(st[y]=='?') 
	{
		int sum=dfs(x,y+1);
		for(int i=0;i<5;++i) sum+=dfs(c[x][i],y+1);
		return sum;
	}
	return dfs(c[x][st[y]-'a'],y+1);
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) 
	{
		scanf("%s",st+1);int x=1;
		for(int i=1;st[i];++i) 
		{
			int t=st[i]-'a';
			if(!c[x][t]) c[x][t]=++cnt;
			x=c[x][t];	
		}
		++val[x];
	}
	for(int i=1;i<=m;++i) 
	{
		scanf("%s",st+1);L=strlen(st+1);++now;
		printf("%d\n",dfs(1,1));Emp(1,1);	
	}
	return 0;
}