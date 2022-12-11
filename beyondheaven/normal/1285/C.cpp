#include<cstdio>
#include<algorithm>
#include<vector>
typedef long long LL;
std::vector<LL>fac;
LL ansa,ansb;
LL x;
int n;
inline LL Calc(int m)
{
	LL res=1;
	for(int i=0;i<n;++i)
	if((m>>i)&1)res*=fac[i];
	#ifdef Dubug
	printf("Calc(%d)=%lld\n",m,res);
	#endif
	return res;
}
int main()
{
	scanf("%lld",&x);
	ansa=ansb=0x7fffffffffffffffLL;
	LL _x=x;
	for(LL i=2;i*i<=x;++i)
	if(_x%i==0)
	{
		LL a=1;
		while(_x%i==0)_x/=i,a*=i;
		fac.push_back(a);
	}
	if(_x!=1)fac.push_back(_x);
	std::sort(fac.begin(),fac.end());
	n=fac.size();
	int S=(1<<n)-1;
	for(int i=0;i<=S;++i)
	{
		LL a=Calc(i),b=Calc(S^i);
		#ifdef Dubug
		printf("a=%lld,b=%lld\n",a,b);
		printf("ansa=%lld,ansb=%lld\n",ansa,ansb);
		#endif
		if(std::max(a,b)<std::max(ansa,ansb))
		ansa=a,ansb=b;
	}
	printf("%lld %lld\n",ansa,ansb);
	return 0;
}