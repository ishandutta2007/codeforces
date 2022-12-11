#include<cstdio>
#define MOD 1000000007
#define MN 75
char s[MN+5];
int z[MN+5][MN+5],f[MN+5][1<<20];
inline void add(int&a,int b){a+=b;if(a>=MOD)a-=MOD;}
int main()
{
	int n,ans=0;register int i,j,k;
	scanf("%d%s",&n,s);
	for(i=0;i<n;++i)for(j=i,k=0;j<n;++j)
		if((k=(k<<1)+s[j]-'0')>20)break;else z[i][j]=k;
	for(i=0;i<n;++i)
	{
		++f[i][0];
		for(j=0;j<1<<20;++j)if(f[i][j])
			for(k=i;k<n;++k)if(z[i][k])add(f[k+1][j|(1<<z[i][k]-1)],f[i][j]);
	}
	for(i=1;i<=n;++i)for(j=1;j<=20;++j)add(ans,f[i][(1<<j)-1]);
	printf("%d",ans);
}