#include<cstdio>
#include<algorithm>
using namespace std;
#define MN 100000
#define MK 30
#define MOD 998244353
#define ll unsigned long long
int n,m,f[MN+5][MK+5];
char a[MN+5],b[MN+5];
ll ha[MN+5],hb[MN+5],p[MN+5];
inline void rw(int&a,int b){if(b>a)a=b;}
int lcp(int x,int y)
{
	int l=1,r=min(n-x+1,m-y+1),mid,res=0;
	while(l<=r)
	{
		mid=l+r>>1;
		if((ha[x+mid-1]+hb[y-1]*p[mid])%MOD!=(hb[y+mid-1]+ha[x-1]*p[mid])%MOD)r=mid-1;
		else res=mid,l=mid+1;
	}
	return res;
}
int main()
{
	int k,i,j;
	scanf("%d%s%d%s%d",&n,a+1,&m,b+1,&k);
	for(p[0]=i=1;i<=n;++i)ha[i]=(ha[i-1]*233+a[i])%MOD,p[i]=p[i-1]*233%MOD;
	for(i=1;i<=m;++i)hb[i]=(hb[i-1]*233+b[i])%MOD;
	f[0][0]=1;
	for(i=0;i<n;++i)for(j=0;j<=k;++j)if(f[i][j])
	{
		rw(f[i+1][j],f[i][j]);
		int p=lcp(i+1,f[i][j]);
		rw(f[i+p][j+1],f[i][j]+p);
	}
	for(i=1;i<=k;++i)if(f[n][i]>m)return 0*puts("YES");
	puts("NO");
}