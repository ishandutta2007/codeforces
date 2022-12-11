#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
const int mod=1000000007;
bitset<63>b[1600160],now,cd[1600160];
int ans,n,q,a[400040],dy[310],su[310],sunum,t[400040][63],inv[310];
int sum[1600160],ad[1600160],len[1600160];
bool bj[310];
int kpow(int x,int b)
{
	int s=1;
	while(b)
	{
		if(b&1)s=1ll*s*x%mod;
		b>>=1;
		x=1ll*x*x%mod;
	}
	return s;
}
void pushdown(int k)
{
	ad[k<<1]=1ll*ad[k<<1]*ad[k]%mod;
	ad[k<<1|1]=1ll*ad[k<<1|1]*ad[k]%mod;
	sum[k<<1]=1ll*sum[k<<1]*kpow(ad[k],len[k<<1])%mod;
	sum[k<<1|1]=1ll*sum[k<<1|1]*kpow(ad[k],len[k<<1|1])%mod;
	b[k<<1]|=cd[k];
	b[k<<1|1]|=cd[k];
	cd[k<<1]|=cd[k];
	cd[k<<1|1]|=cd[k];
	cd[k].reset();
	ad[k]=1;
}
void build(int k,int l,int r)
{
	len[k]=r-l+1;ad[k]=1;
	if(l==r)
	{
		sum[k]=a[l];
		for(int i=1;i<=62;++i)
			if(t[l][i])b[k].set(i);
		return ;
	}
	build(k<<1,l,l+r>>1);
	build(k<<1|1,(l+r>>1)+1,r);
	sum[k]=1ll*sum[k<<1]*sum[k<<1|1]%mod;
	b[k]=b[k<<1]|b[k<<1|1];
}
void upd(int k,int l,int r,int ll,int rr,int w)
{
	if(l>=ll&&r<=rr)
	{
		sum[k]=1ll*kpow(w,len[k])*sum[k]%mod;
		ad[k]=1ll*ad[k]*w%mod;
		b[k]|=now;cd[k]|=now;
		return ;
	}
	if(ad[k]!=1)pushdown(k);
	if(ll<=(l+r>>1))upd(k<<1,l,l+r>>1,ll,rr,w);
	if(rr>(l+r>>1))upd(k<<1|1,(l+r>>1)+1,r,ll,rr,w);
	sum[k]=1ll*sum[k<<1]*sum[k<<1|1]%mod;
	b[k]=b[k<<1]|b[k<<1|1];
}
void query(int k,int l,int r,int ll,int rr)
{
	//printf("ans:%d\n",ans);
	if(l>=ll&&r<=rr)
	{
	//	printf("%d %d %d %d ",k,sum[k],l,r);
		ans=1ll*ans*sum[k]%mod;
	//	printf("%d\n",ans);
		now|=b[k];
		return ;
	}
	if(ad[k]!=1)pushdown(k);
	if(ll<=(l+r>>1))query(k<<1,l,l+r>>1,ll,rr);
	if(rr>(l+r>>1))query(k<<1|1,(l+r>>1)+1,r,ll,rr);
}
int main()
{
	bj[1]=1;inv[1]=1;
	for(int i=2;i<=300;++i)
	{
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		if(!bj[i])su[++sunum]=i,dy[i]=sunum;
		for(int j=1;j<=sunum&&su[j]*i<=300;++j)
		{
			bj[i*su[j]]=1;
			if(!(i%su[j]))break;
		}
	}
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		int cur=a[i];
		for(int j=2;j*j<=a[i];++j)
			if(cur%j==0)while(cur%j==0)++t[i][dy[j]],cur/=j;
		if(cur>1)++t[i][dy[cur]];
	}
	build(1,1,n);
	int x,y,w;char c[20];
	while(q--)
	{
		scanf("%s",c);
		now.reset();
		if(c[0]=='M')
		{
			scanf("%d %d %d",&x,&y,&w);
			int cur=w;
			for(int j=2;j*j<=w;++j)
				if(cur%j==0)
				{
					now.set(dy[j]);
					while(cur%j==0)cur/=j;
				}
			if(cur>1)now.set(dy[cur]);
			upd(1,1,n,x,y,w);
		}
		else
		{
			scanf("%d %d",&x,&y);
			ans=1;
		//	printf("ans:%d\n",ans);
			query(1,1,n,x,y);
		//	printf("%d %d\n",sum[3],ans);
			for(int i=1;i<=62;++i)
				if(now[i])ans=1ll*ans*inv[su[i]]%mod*(su[i]-1)%mod;
			printf("%d\n",ans);
		}
	}
	return 0;
}