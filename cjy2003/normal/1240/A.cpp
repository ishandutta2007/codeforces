#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int q,n,p[200010],x,a,y,b;
long long k,c;
bool check(int cnt)
{
	int n1=cnt/c,n2=cnt/a-n1,n3=cnt/b-n1;
	long long sum=0;
	for(int i=1;i<=n1;++i)sum+=p[i]/100*(x+y);
	for(int i=n1+1;i<=n1+n2;++i)sum+=p[i]/100*x;
	for(int i=n1+n2+1;i<=n1+n2+n3;++i)sum+=p[i]/100*y;
//	printf("%d %lld\n",cnt,sum);
	return sum>=k;
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&p[i]);
		scanf("%d %d %d %d %lld",&x,&a,&y,&b,&k);
		if(x<y)swap(x,y),swap(a,b);
		c=1ll*a*b/gcd(a,b);
		sort(p+1,p+1+n);reverse(p+1,p+1+n);
		int l=1,r=n+1,mid;
		while(l<r)
		{
			mid=l+r>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		if(r>n)printf("-1\n");
		else printf("%d\n",r);
	}
	return 0;
}