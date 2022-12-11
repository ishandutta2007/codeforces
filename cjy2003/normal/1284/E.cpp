#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct point
{
	long long x,y;
	friend long long operator ^ (point a,point b){return a.x*b.y-a.y*b.x;}
	friend bool operator < (point a,point b)
	{
		bool f1=a.y>0||(a.y==0&&a.x>0),f2=b.y>0||(b.y==0&&b.x>0);
		if(f1!=f2)return f1>f2;
		return (a^b)>0;
	}
	friend point operator - (point a,point b){return point{a.x-b.x,a.y-b.y};}
}p[2520],q[5050];
int n,cnt;
long long a,b,c;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld %lld",&p[i].x,&p[i].y);
	for(int i=1;i<=n;++i)
	{
		cnt=0;
		for(int j=1;j<=n;++j)if(j!=i)q[++cnt]=p[j]-p[i];
		sort(q+1,q+1+cnt);
		for(int j=1;j<=cnt;++j)q[j+cnt]=q[j];
//		for(int j=1;j<=cnt;++j)printf("%lld %lld\n",q[j].x,q[j].y);printf("\n");
		for(int j=1,r=1;j<=cnt;++j)
		{
			if(r<j)r=j;
			while(r<j+cnt-1&&(q[j]^q[r+1])>0)++r;
			int le=r-j,re=cnt-1-le;
//			printf("%d %d %d %d\n",j,r,le,re);
			a+=le*re;
			b+=le*(le-1)/2+re*(re-1)/2;
		}
	}
	c=1ll*n*(n-1)*(n-2)*(n-3)*(n-4)/120;
	a/=2,b/=2;
//	printf("%lld %lld %lld\n",a,b,c);
//	long long x=(30*c-a-b)/10,y=(a-10*c-2*x)/4;
	printf("%lld",(a*(n-4)-10*c)/2);
	return 0;
}