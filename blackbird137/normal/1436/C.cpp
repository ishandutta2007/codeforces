#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int mod=1e9+7;
int t,n,x,p,a,b,jc[100005];

inline int q_pow(int a,int b);
inline int C(int n,int m);

signed main()
{
	n=read();x=read();p=read();
	jc[0]=1;
	for(int i=1;i<=n-1;++i)
		jc[i]=jc[i-1]*i%mod;
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(mid>p) b++;
		else if(mid<p) a++;
		if(mid<=p)
			l=mid+1;
		else r=mid;
	}
	//printf("%lld\n",C(81,4));
	int ans=((C(x-1,a)*jc[a]%mod)*(C(n-x,b)*jc[b]%mod)%mod)*jc[n-a-b-1]%mod;
	printf("%lld\n",ans);
	return 0;
}

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%mod;
		b>>=1;a=a*a%mod;
	}
	return c;
}

inline int C(int n,int m)
{
	return n<m?0:(jc[n]*q_pow(jc[m],mod-2)%mod)*q_pow(jc[n-m],mod-2)%mod;
}