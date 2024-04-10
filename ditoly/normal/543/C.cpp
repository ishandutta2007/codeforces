#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 
#define MN 20
char s[MN+5][MN+5];
int a[MN+5][MN+5],f[MN+5][26],mx[MN+5][26],S[MN+5][26],F[1<<MN];
int main()
{
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)
	{
		scanf("%d",&a[i][j]);
		f[j][s[i][j]-'a']+=a[i][j];
		mx[j][s[i][j]-'a']=max(mx[j][s[i][j]-'a'],a[i][j]);
		S[j][s[i][j]-'a']|=1<<i-1;
	}
	memset(F,40,sizeof(F));
	for(F[i=0]=0;i<(1<<n)-1;++i)
	{
		for(j=1;j<=n;++j)if(!(i&(1<<j-1)))break;
		for(k=1;k<=m;++k)
			F[i|(1<<j-1)]=min(F[i|(1<<j-1)],F[i]+a[j][k]),
			F[i|S[k][s[j][k]-'a']]=min(F[i|S[k][s[j][k]-'a']],F[i]+f[k][s[j][k]-'a']-mx[k][s[j][k]-'a']);
	}
	printf("%d",F[(1<<n)-1]);
}