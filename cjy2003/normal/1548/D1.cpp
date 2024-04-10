#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<ctime>
#include<iostream>
using namespace std;
int n,x[6060],y[6060],d[6060][6060],cnt[1<<16];
struct Bitset
{
	unsigned long long a[94];
	inline void set(int p){a[p>>6]|=1ull<<(p&63);}
}b[6000];
inline int calc(Bitset &a,Bitset &b,int c)
{
	int res=0;
	unsigned long long tmp;
	for(int i=0;i<94;++i)
	{
		tmp=a.a[i]^b.a[i];
		res+=cnt[tmp&((1<<16)-1)]+cnt[(tmp>>16)&((1<<16)-1)]+cnt[(tmp>>32)&((1<<16)-1)]+cnt[tmp>>48];
	}
	return c==0?n-res:res;
}
int gcd(int a,int b)
{
	while(b)a%=b,swap(a,b);
	return a;
}
int main()
{
	for(int i=0;i<1<<16;++i)cnt[i]=__builtin_popcount(i);
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d %d",&x[i],&y[i]);
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
		{
			d[i][j]=gcd(abs(x[i]-x[j]),abs(y[i]-y[j]))%4;
			if(d[i][j]==2)b[i].set(j),b[j].set(i);
		}
//	cerr<<clock()<<endl;
	long long ans=0;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
		{
			int c=d[i][j]/2;
			ans+=calc(b[i],b[j],c)-2;
		}
	printf("%lld\n",ans/3);
//	cerr<<clock()<<endl;
	return 0;
}