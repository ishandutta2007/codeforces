#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct point
{
	long long x,y;
	friend point operator - (point a,point b){return point{a.x-b.x,a.y-b.y};}
	friend long long operator ^ (point a,point b){return 1ll*a.x*b.y-1ll*a.y*b.x;}
};
int n,a[1000010];
long long sum[1000010];
int st[1000010],tp,p[1000010];
void print(int x)
{
	double ans=1.0*(sum[p[x]]-sum[x-1])/(p[x]-x+1);
	for(int i=x;i<=p[x];++i)printf("%.12lf\n",ans);
	if(p[x]!=n)print(p[x]+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	st[tp=1]=n;
	for(int i=n-1;i>=0;--i)
	{
		while(tp>1&&(point{st[tp]-i,sum[st[tp]]-sum[i]}^point{st[tp-1]-i,sum[st[tp-1]]-sum[i]})<=0)--tp;
		st[++tp]=i;
	//	for(int j=tp;j>=1;--j)printf("%d ",st[j]);printf("\n");
		p[i+1]=st[tp-1];
	}
	print(1);
	return 0;
}