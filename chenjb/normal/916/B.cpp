#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define pb push_back
#define x0 fuckcjb
#define x1 fuckshb
#define y0 fucksf
#define y1 fuckjtjl
long long n;
int k,num,a[100010],ss;
bool check(int maxp,long long n)
{
	if(maxp<0&&(k/(1ll<<(-maxp))<n))return 0;
	if(maxp>=0&&(1<<maxp)<(n-1)/k+1)
	ss=0;
	if(maxp<0)
	{
		n<<=-maxp;
		ss=-maxp;
		maxp=0;
	}
	for(int i=1;i<=k;i++)
	{
		//printf("%lld %d %d\n",n,i,ss);
		for(;n<(1ll<<maxp)||n==(1ll<<maxp)&&i!=k;)
		if(maxp>0)maxp--;
		else ss++,n<<=1;
		a[i]=maxp-ss;
		n-=1ll<<maxp;
	}
	return n==0;
}
int main()
{
	scanf("%lld%d",&n,&k);
	for(long long x=n;x;x>>=1)num+=x&1;
	if(num>k){puts("No");return 0;}
	puts("Yes");
	for(int i=-20;i<=60;i++)if(check(i,n))break;
	for(int i=1;i<=k;i++)printf("%d%c",a[i],i==k?'\n':' ');
	/*double tt=0;
	for(int i=1;i<=k;i++)tt+=a[i]>=0?(1ll<<a[i]):(1.0/(1ll<<(-a[i])));
	printf("%lf\n",tt);*/
	return 0;
}