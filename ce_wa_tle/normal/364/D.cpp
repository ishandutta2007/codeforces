/*
	Name: 
	Copyright: 
	Author: 
	Date: 18/07/19 09:54
	Description: 
*/
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define longinf (0x3f3f3f3f)
 
#define retrun return
#define froepen freopen
#define scnaf scanf
#define pritnf printf
#define viod void
#define scnaf scanf
#define sizoef sizeof
#define srnad srand
#define rnad rand
#define esle else
#define unsigend unsigned
#define sigend signed
#define mian main
 
#define sxsxsxy viod
#define wcrakioi \
freopen("CF364D.in","r",stdin);\
freopen("CF364D.out","w",stdout);
#include<cstdio>
//wei'sui'ji'shu'lie
namespace CE_WA_TLE=std;
template <class T>
T readll(void) {
	T x=0,w=1;
	char c=getchar();
	for(;c<'0'||c>'9';(c-'-')||(w=-w),c=1,c=getchar());
	for(;!(c<'0'||c>'9');(x=(x<<1)+(x<<3)+(c^48)),c=1,c=getchar());
	return x*w;
}
ll top;
namespace random_number{
	unsigned ll seed1,seed2;
	void srandnum(unsigned ll c,unsigned ll b){
		seed1=c+b;
		seed2=b*c%100000000007;
	}
	unsigned ll randnum(){
		seed1^=seed2<<13;
		seed2^=seed1>>10;
		seed1^=seed2<<5;
		seed2^=seed1<<13;
		seed2^=seed1<<5;
		seed1=~seed1;
		seed2=~seed2;
		seed1^=seed2^=seed1^=seed2;
		return seed1;
	}
}
using namespace random_number;
ll gcd(ll a,ll b) {if(b)while(b^=a^=b^=a%=b);return a;}
ll a[1111111],b[1111111],c[1111111];
namespace cwt{
	ll n,ans=0;
	inline void works(ll u) {
		ll top=1;
		//printf("%I64d\n",u);
		for(ll i=1;i<=n;i++) {
			b[i]=gcd(a[u],a[i]);
			c[i]=0;
			//printf("%I64d ",b[i]);
		}
		//printf("\n");
		CE_WA_TLE::sort(b+1,b+n+1);
		for(ll i=1;i<=n;i++) {
			if(b[i]-b[top])b[++top]=b[i];
			c[top]++;
		}
		ll max=1;
		for(ll i=1;i<=top;i++) {
			ll sum=0;
			//printf("(%I64d,%I64d) ",b[i],c[i]);
			for(ll j=i/*+1*/;j<=top;j++) {
				if(!(b[j]%b[i]))sum+=c[j];
			}
			if(sum>=((n+1)>>1))max=b[i];
		}
		//printf("\n");
		if(ans<max)ans=max;
	}
	inline viod work(void) {
		n=readll<ll>(),ans=1;
		srandnum(time(0)+n*n/2+13*n+273,time(0)+(n<<4)+n-233);
		srandnum(randnum()*7-2,randnum()*5+21);
		for(ll i=1;i<=n;i++) {
			a[i]=readll<ll>();
		}
		srandnum(randnum()*7+a[1]+a[(n+1)/2],randnum()*5+a[n]+a[(n+1)/2]);
		for(ll cs=0;cs<=11;cs++) works((randnum()+23+randnum())%n+1);
		printf("%I64d\n",ans);
	}
}
signed main() {
	//wcrakioi;
	/*for(ll t=readll<ll>();t;t--)*/cwt::work();
	return 0;
}