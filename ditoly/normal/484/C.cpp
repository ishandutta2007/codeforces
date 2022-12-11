#include<cstdio>
#include<cstring>
#define MN 1000000
#define K 20
char s[MN+5],ss[MN+5];
int t[K][MN+5],tn;
int p(int x,int y)
{
	for(int i=0;y;y>>=1,++i)if(y&1)x=t[i][x];
	return x;
}
int main()
{
	int n,m,k,d,i,j;
	scanf("%s",s+1);n=strlen(s+1);
	for(scanf("%d",&m);m--;)
	{
		scanf("%d%d",&k,&d);
		for(tn=0,i=1;i<=d;++i)for(j=i;j<=k;j+=d)t[0][++tn]=j+1;
		for(i=k;++i<=n;)t[0][i]=i+1;
		for(i=1;i<K;++i)for(j=1;j<=n;++j)t[i][j]=t[i-1][t[i-1][j]];
		for(i=1;i<=n-k;++i)ss[i]=s[p(1,i)-1];
		for(;i<=n;++i)ss[i]=s[p(i-n+k,n-k+1)-1];
		for(i=1;i<=n;++i)s[i]=ss[i];
		puts(s+1);
	}
}