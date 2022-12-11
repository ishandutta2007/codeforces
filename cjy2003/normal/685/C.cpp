#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long inf=0x7fffffffffffffff;
int T,n;
long long x[100010],y[100010],z[100010],X,Y,Z;
bool check0(long long suml,long long sumr,long long al,long long ar,long long bl,long long br,long long cl,long long cr)
{
	if(suml&1)++suml;if(sumr&1)--sumr;
	if(al&1)++al;if(ar&1)--ar;
	if(bl&1)++bl;if(br&1)--br;
	if(cl&1)++cl;if(cr&1)--cr;
	suml/=2,sumr/=2,al/=2,ar/=2,bl/=2,br/=2,cl/=2,cr/=2;
	if(al>ar||bl>br||cl>cr||suml>sumr)return 0;
	long long a=al,b=bl,c=cl;
	if(a+b+c<suml)a=ar<suml-b-c?ar:suml-b-c;
	if(a+b+c<suml)b=br<suml-a-c?br:suml-a-c;
	if(a+b+c<suml)c=cr<suml-a-b?cr:suml-a-b;
	if(a+b+c<suml||a+b+c>sumr)return 0;
	X=a+b;Y=a+c;Z=b+c;
	return 1;
}
bool check1(long long suml,long long sumr,long long al,long long ar,long long bl,long long br,long long cl,long long cr)
{
	if(!(suml&1))++suml;if(!(sumr&1))--sumr;
	if(!(al&1))++al;if(!(ar&1))--ar;
	if(!(bl&1))++bl;if(!(br&1))--br;
	if(!(cl&1))++cl;if(!(cr&1))--cr;
	suml=(suml-3)/2;sumr=(sumr-3)/2;
	al=(al-1)/2,ar=(ar-1)/2;
	bl=(bl-1)/2,br=(br-1)/2;
	cl=(cl-1)/2,cr=(cr-1)/2;
	if(al>ar||bl>br||cl>cr||suml>sumr)return 0;
	long long a=al,b=bl,c=cl;
	if(a+b+c<suml)a=ar<suml-b-c?ar:suml-b-c;
	if(a+b+c<suml)b=br<suml-a-c?br:suml-a-c;
	if(a+b+c<suml)c=cr<suml-a-b?cr:suml-a-b;
	if(a+b+c<suml||a+b+c>sumr)return 0;
	X=a+b+1;Y=a+c+1;Z=b+c+1;
	return 1;
}
bool check(long long mid)
{
	long long suml=-inf,sumr=inf,al=-inf,ar=inf,bl=-inf,br=inf,cl=-inf,cr=inf;
	for(int i=1;i<=n;++i)
	{
		suml=max(suml,x[i]+y[i]+z[i]-mid);
		sumr=min(sumr,x[i]+y[i]+z[i]+mid);
		al=max(al,+x[i]+y[i]-z[i]-mid);
		ar=min(ar,+x[i]+y[i]-z[i]+mid);
		bl=max(bl,+x[i]-y[i]+z[i]-mid);
		br=min(br,+x[i]-y[i]+z[i]+mid);
		cl=max(cl,-x[i]+y[i]+z[i]-mid);
		cr=min(cr,-x[i]+y[i]+z[i]+mid);
	}
	if(check0(suml,sumr,al,ar,bl,br,cl,cr))return 1;
	return check1(suml,sumr,al,ar,bl,br,cl,cr);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%lld %lld %lld",&x[i],&y[i],&z[i]);
	//	check(0);
	//	return 0;
		long long l=0,r=3e18,mid;++r;
		while(l<r)
		{
			mid=l+r>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
	//	printf("%lld\n",l);
		printf("%lld %lld %lld\n",X,Y,Z);
	}
	return 0;
}