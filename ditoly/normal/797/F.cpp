#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define MN 5000
struct hole{int p,c;}h[MN+5];
bool cmp(hole a,hole b){return a.p<b.p;}
int x[MN+5],q[MN+5],ql,qr;
ll f[MN+5][MN+5],s[MN+5];
inline int z(int x){return x<0?-x:x;}
int main()
{
	int n,m,i,j;ll cnt=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&x[i]);
	for(i=1;i<=m;++i)scanf("%d%d",&h[i].p,&h[i].c),cnt+=h[i].c;
	if(cnt<n)return 0*puts("-1");
	sort(x+1,x+n+1);sort(h+1,h+m+1,cmp);
	memset(f,42,sizeof(f));f[0][0]=0;
	for(i=1;i<=m;++i)for(q[ql=1,qr=0]=j=0;j<=n;++j)
	{
		s[j]=s[j-1]+z(h[i].p-x[j]);
		while(ql<=qr&&f[i-1][j]-s[j]<=f[i-1][q[qr]]-s[q[qr]])--qr;q[++qr]=j;
		while(j-q[ql]>h[i].c)++ql;
		f[i][j]=f[i-1][q[ql]]+s[j]-s[q[ql]];
	}
	printf("%I64d",f[m][n]);
}