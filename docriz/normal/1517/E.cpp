#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll T,n,a[200005],sum[2][200005],tot[2],seq[2][200005],vr[200005];
ll alt[200005],ans=0,gl;
const ll mod=998244353;
ll solve(int p,ll gl)
{
	ll summ=0;
	int tmp=p&1,r;
	int pos=upper_bound(sum[tmp]+1,sum[tmp]+vr[p]+1,sum[tmp][vr[p]]-gl)-sum[tmp];
	pos--;
	if(tmp==0)r=1;
	else 
	{
		if(p==-1)r=1;
		else r=2;
	}
	//("1:%d %d %d %d %lld %lld\n",r,pos,p,vr[p],sum[tmp][vr[p]]-gl,gl);
	summ+=max(0,pos-r+1);
	if(p==0)return summ;
	gl-=a[1];
	pos=upper_bound(sum[tmp]+1,sum[tmp]+vr[p]+1,sum[tmp][vr[p]]-gl)-sum[tmp];
	pos--;
	if(tmp==0)
	{
		if(vr[p]<=1)r=1;
		else r=2;
	}
	else 
	{
		if(p==-1)r=1;
		else r=2;
	}
	//printf("2:%d %d %d\n",r,pos,p);
	summ+=max(0,pos-r+1);
	return summ;
}
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		tot[0]=tot[1]=0;vr[0]=1;
		tot[0]++;
		seq[0][1]=0;sum[0][1]=0;
		tot[1]++;
		seq[1][1]=-1;sum[1][1]=0;
		for(int i=1;i<=n;i++)
		{
			int tmp=i&1;
			tot[tmp]++;
			seq[tmp][tot[tmp]]=i;
			sum[tmp][tot[tmp]]=a[i]+sum[tmp][tot[tmp]-1];
			vr[i]=tot[tmp];
		}
		for(int i=1;i<=n;i++)alt[i]=a[i]+=alt[i-1];
		gl=alt[n]/2+1;
		for(int i=n;i>1;i--)
		{
			if(i<n)ans+=solve(i-2,gl-(alt[n-1]-alt[i-1]));
			//printf("%d %lld\n",i,ans);
			ans+=solve(i-2,gl-(alt[n]-alt[i-1]));
			ans%=mod;
			//printf("%d %lld\n",i,ans);
		}
		for(int i=1;i<=n;i++)if(alt[i]>=gl)ans++;
		ans%=mod;
		printf("%lld\n",ans);
	}
	return 0;
}