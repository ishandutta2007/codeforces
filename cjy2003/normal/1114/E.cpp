#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int n,l,r,mid,mx,va,cnt,d,x[61],tot,y[1000010],ymx;
bool bj[1000010];
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
unsigned int myrand()
{
	return (rand()<<16)+rand();
}
int main()
{
	srand(time(0));
	scanf("%d",&n);
	l=0,r=1e9+1;
	while(l<=r)
	{
		mid=l+r>>1;
		printf("> %d\n",mid);
		++cnt;
		fflush(stdout);
		scanf("%d",&va);
		if(va)l=mid+1;
		else r=mid-1,mx=mid;
	}
	cnt=60-cnt;
	for(int i=1;i<=n&&i<=cnt;++i)
	{
		int wp=myrand()%n+1;
		while(bj[wp])wp=myrand()%n+1;
		bj[wp]=1;
		printf("? %d\n",wp);
		fflush(stdout);
		scanf("%d",&va);
		if(va!=mx)x[++tot]=va;
	}
	x[++tot]=mx;
	sort(x+1,x+1+tot);
	for(int i=1;i<tot;++i)
		d=gcd(x[i+1]-x[i],d);
	printf("! %d %d",mx-(n-1)*d,d);
	return 0;
}