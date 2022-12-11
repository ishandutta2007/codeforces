#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
#define MX 1000000
#define K 20
int a[MN+5],b[K][MX+5],c[MX+5];
int q(int l,int r)
{
	int x=c[r-l+1];
	return max(b[x][l],b[x][r-(1<<x)+1]);
}
int main()
{
	int n=read(),i,j,ans=0;
	for(i=2;i<=MX;++i)c[i]=c[i>>1]+1;
	for(i=1;i<=n;++i)a[i]=read(),b[0][a[i]]=a[i];
	for(i=1;i<K;++i)for(j=1;j<=MX;++j)b[i][j]=max(b[i-1][j],b[i-1][j+(1<<i-1)]);
	sort(a+1,a+n+1);n=unique(a+1,a+n+1)-a-1;
	for(i=1;i<=n;++i)for(j=a[i];j<=MX;j+=a[i])ans=max(ans,q(j,min(j+a[i]-1,MX))-j);
	printf("%d",ans);
}