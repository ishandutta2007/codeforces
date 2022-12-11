#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MN 200
#define K 25
int f[MN+5][MN*K+5];
inline void rw(int&a,int b){if(b>a)a=b;}
int main()
{
	int n,k,s2,s5,l,i,j,ans=0;long long x;
	scanf("%d%d",&n,&k);
	memset(f,200,sizeof(f));f[0][0]=0;
	for(l=1;l<=n;++l)
	{
		scanf("%I64d",&x);
		for(s2=0;x%2==0;++s2)x/=2;
		for(s5=0;x%5==0;++s5)x/=5;
		for(i=min(k,l);i--;)for(j=0;j<=i*K;++j)rw(f[i+1][j+s5],f[i][j]+s2);
	}
	for(l=0;l<=k*K;++l)rw(ans,min(l,f[k][l]));
	printf("%d",ans);
}