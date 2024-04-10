#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
unsigned n,p,q,ans,s[150];
unsigned kpow(unsigned a,unsigned b)
{
	unsigned s=1;
	for(;b;b>>=1,a=a*a)if(b&1)s=s*a;
	return s;
}
void init()
{
	unsigned s1=1,cnt=0,x;
	s[0]=1;
	for(unsigned i=n,j=1;j<=p&&j<n;--i,++j)
	{
		x=i;
		while(!(x&1))++cnt,x>>=1;
		s1*=x;
		x=j;
		while(!(x&1))--cnt,x>>=1;
		s1=s1*kpow(x,(1u<<31)-1);
		s[j]=s1<<cnt;
	}
}
inline unsigned calc(unsigned x)
{
	unsigned po=1,res=0;
	for(unsigned i=0;i<=p&&i<n;++i)res+=s[i]*po,po*=x;
	return res;
}
int main()
{
	scanf("%u %u %u",&n,&p,&q);
	init();
	for(unsigned i=1;i<=q;++i)ans^=calc(i)*i;
	printf("%u",ans);
	return 0;
}