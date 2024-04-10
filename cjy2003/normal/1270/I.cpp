#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int K,t,x[110],y[110],ans,n;
long long a[1<<9][1<<9],b[1<<9][1<<9];
int main()
{
	scanf("%d",&K);n=1<<K;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			scanf("%lld",&a[i][j]);
	scanf("%d",&t);
	for(int i=1;i<=t;++i)scanf("%d %d",&x[i],&y[i]),--x[i],--y[i];
	for(int i=0;i<K;++i)
	{
		memset(b,0,sizeof(b));
		for(int j=1;j<=t;++j)
			for(int c=0;c<n;++c)
				for(int d=0;d<n;++d)
					b[(c+x[j])%n][(d+y[j])%n]^=a[c][d];
		memcpy(a,b,sizeof(b));
		for(int j=1;j<=t;++j)x[j]=2*x[j]%n,y[j]=2*y[j]%n;
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			ans+=a[i][j]!=0;
	printf("%d",ans);
	return 0;
}