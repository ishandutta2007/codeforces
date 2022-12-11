#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MN 500
char S[MN+5][MN+5];
int f[MN*MN+5],s[MN*MN+5],u[MN*MN+5],ans,cnt;
int gf(int k){return f[k]?f[k]=gf(f[k]):k;}
inline int p(int x,int y){return (x-1)*MN+y;}
void add(int x,int y){if(!u[gf(p(x,y))]++)cnt+=s[gf(p(x,y))];}
void del(int x,int y){if(!--u[gf(p(x,y))])cnt-=s[gf(p(x,y))];}
void ADD(int x,int y){if(S[x][y]=='.')add(x,y);}
void DEL(int x,int y){if(S[x][y]=='.')del(x,y);}
int main()
{
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%s",S[i]+1);
		for(j=1;j<=n;++j)if(S[i][j]=='.')
		{
			if(S[i][j-1]=='.')if(gf(p(i,j))!=gf(p(i,j-1)))f[gf(p(i,j))]=gf(p(i,j-1));
			if(S[i-1][j]=='.')if(gf(p(i,j))!=gf(p(i-1,j)))f[gf(p(i,j))]=gf(p(i-1,j));
		}
	}
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)++s[gf(p(i,j))];
	for(i=1;i+m-1<=n;++i)
	{
		memset(u,cnt=0,sizeof(u));
		for(j=1;j<=m;++j)
		{
			ADD(i-1,j);ADD(i+m,j);ADD(i+j-1,0);ADD(i+j-1,m+1);
			for(k=1;k<=m;++k)add(i+j-1,k);
		}
		for(j=1;j+m-1<=n;++j)
		{
			ans=max(ans,cnt);
			DEL(i-1,j);DEL(i+m,j);ADD(i-1,j+m);ADD(i+m,j+m);
			for(k=1;k<=m;++k)DEL(i+k-1,j-1),DEL(i+k-1,j+m),del(i+k-1,j);
			for(k=1;k<=m;++k)ADD(i+k-1,j),ADD(i+k-1,j+m+1),add(i+k-1,j+m);
		}
	}
	printf("%d",ans);
}