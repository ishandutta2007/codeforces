#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int n;
long long x[500050],y[500050];
long long S,cur;
long long sumx1,sumy1,sumx2,sumy2,cnt1,cnt2,sums,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld %lld",&x[i],&y[i]);
	reverse(x+1,x+1+n);
	reverse(y+1,y+1+n);
	x[n+1]=x[1],y[n+1]=y[1];
	for(int i=3;i<=n;++i)S+=(x[i-1]-x[1])*(y[i]-y[1])-(x[i]-x[1])*(y[i-1]-y[1]);
//	printf("%lld\n",S);
	for(int i=3;i<=n;++i)
	{
		cur+=(x[i-1]-x[1])*(y[i]-y[1])-(x[i]-x[1])*(y[i-1]-y[1]);
//		printf("%lld ",cur);
		sums=(sums+2*(cur%mod)-(S%mod))%mod;
		++cnt2,(sumx2+=x[i])%=mod,(sumy2+=y[i])%=mod;
	}
//	printf("%lld\n",sums);
	cur=0;
	for(int i=1,r=2;i<n;++i)
	{
		while(r<n&&cur+(x[r]-x[i])*(y[r+1]-y[i])-(y[r]-y[i])*(x[r+1]-x[i])<=S/2)
		{
			cur+=(x[r]-x[i])*(y[r+1]-y[i])-(y[r]-y[i])*(x[r+1]-x[i]);
	//		printf("%lld\n",cur);
			++r;
			sums=(sums+2*(S%mod)-4*(cur%mod))%mod;
			++cnt1,--cnt2;
			(sumx1+=x[r])%=mod,(sumy1+=y[r])%=mod;
			(sumx2-=x[r])%=mod,(sumy2-=y[r])%=mod;
		}
	//	printf("%d %d %lld %lld %lld %lld %lld %lld %lld\n",i,r,cnt1,sumx1,sumy1,cnt2,sumx2,sumy2,sums);
	//	printf("%lld\n",sums);
		ans=(ans+sums)%mod;
		cur-=(x[i+1]-x[i])*(y[r]-y[i])-(x[r]-x[i])*(y[i+1]-y[i]);
		sums=(sums+2*((x[i+1]-x[i])%mod)*((sumy1-cnt1*y[i])%mod)-2*((sumx1-cnt1*x[i])%mod)*((y[i+1]-y[i])%mod))%mod;
	//	printf("%ld\n",sums);
		sums=(sums-2*((x[i+1]-x[i])%mod)*((sumy2-cnt2*y[i])%mod)+2*((sumx2-cnt2*x[i])%mod)*((y[i+1]-y[i])%mod))%mod;
		if(cnt1)--cnt1,(sumx1-=x[i+2])%=mod,(sumy1-=y[i+2])%=mod;
		else --cnt2,(sumx2-=x[i+2])%=mod,(sumy2-=y[i+2])%=mod;
		sums=(sums-S%mod)%mod;
	//	printf("%d %d %lld %lld %lld %lld %lld %lld %lld %lld\n",i,r,cnt1,sumx1,sumy1,cnt2,sumx2,sumy2,sums,cur);
	//	printf("%d %d %d %d %d %d %d %d %d\n",i,r,cnt1,sumx1,sumy1,cnt2,sumx2,sumy2,sums);
	}
	ans=(ans-S%mod)%mod;
	if(ans<0)ans+=mod;
	printf("%lld",ans);
	return 0;
}