#include<cstdio>
#include<algorithm>
using namespace std;
#define lb long double
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
int a[MN+5],b[MN+5];
int main()
{
	int n=read(),p=read(),t,i;long long cnt=0;
	lb l,r,mid,sum;
	for(i=1;i<=n;++i)cnt+=a[i]=read(),b[i]=read();
	if(cnt<=p)return 0*puts("-1");
	for(t=100,l=0,r=1e12;--t;)
	{
		mid=(l+r)/2;
		for(i=1,sum=0;i<=n;++i)sum+=max((lb)0,a[i]*mid-b[i]);
		(sum>p*mid?r:l)=mid;
	}
	printf("%.10lf",(double)l);
}