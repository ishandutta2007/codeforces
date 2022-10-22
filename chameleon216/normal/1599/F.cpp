#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2; 
	}
	return ans;
}
struct qt
{
	int l,r,d,id;
	bool operator<(const qt q) const
	{
		return r<q.r;
	}
}q[1000005];
struct pt
{
	int v[5];
	pt(){memset(v,0,sizeof(v));}
}sum[1000005];
int m=3;
pt operator+(const pt x,const pt y)
{
	pt ans;
	for(int i=0;i<=m;i++)
		ans.v[i]=addmod(x.v[i]+y.v[i]);
	return ans;
}
pt operator-(const pt x)
{
	pt ans;
	for(int i=0;i<=m;i++)
		ans.v[i]=submod(-x.v[i]);
	return ans;
}
void pushup(int x)
{
	sum[x]=sum[x*2]+sum[x*2+1];
}
void modify(int x,int l,int r,int qx,pt v)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		sum[x]=sum[x]+v;
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,v);
	modify(x*2+1,mid+1,r,qx,v);
	pushup(x);
}
pt query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return pt();
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2;
	return query(x*2,l,mid,ql,qr)+query(x*2+1,mid+1,r,ql,qr);
}
int inv6;
inline int F(int n,int k)
{
	if(k==0) return n;
	if(k==1) return 1ll*n*(n+1)/2%mod;
	if(k==2) return 1ll*n*(n+1)%mod*(2*n+1)%mod*inv6%mod;
	if(k==3)
	{
		int t=1ll*n*(n+1)/2%mod;
		return 1ll*t*t%mod;
	}
	return -1;
}
int n,qt,a[1000005],pre[1000005],c[5][5],qans[1000005];
pt p[1000005];
map<int,int> mp;
int main()
{
	inv6=fpow(6,mod-2);
	for(int i=0;i<=m;i++)
		c[i][0]=1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	scanf("%d%d",&n,&qt);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		pre[i]=mp[a[i]];
		mp[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		p[i].v[0]=1;
		for(int j=1;j<=m;j++)
			p[i].v[j]=1ll*p[i].v[j-1]*a[i]%mod;
	}
	for(int i=1;i<=qt;i++)
		scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].d),q[i].id=i;
	sort(q+1,q+qt+1);
	int nw=1;
	for(int i=1;i<=n;i++)
	{
		if(pre[i])
		{
			modify(1,1,n,pre[i],-p[i]);
		}
		modify(1,1,n,i,p[i]);
		while(nw<=qt&&q[nw].r==i)
		{
			pt w=query(1,1,n,q[nw].l,q[nw].r);
			int len=w.v[0],s=w.v[1],x;
			x=submod(s-1ll*len*(len-1)/2%mod*q[nw].d%mod);
			x=1ll*fpow(len,mod-2)*x%mod;
			int ans[5],u[5],fl=1;
			for(int j=1;j<=m;j++)
				u[j]=1ll*F(len-1,j)*fpow(q[nw].d,j)%mod;
			u[0]=len;
			for(int k=0;k<=m;k++)
			{
				ans[k]=0;
				for(int j=0;j<=k;j++)
					ans[k]=(ans[k]+1ll*c[k][j]*fpow(x,k-j)%mod*u[j])%mod;
			//	printf("id=%d,k=%d,len=%d,s=%d,ans=%d,w=%d\n",q[nw].id,k,len,s,ans[k],w.v[k]);
				if(ans[k]!=w.v[k])
				{
					fl=0;
					break;
				}
			}
			qans[q[nw].id]=fl;
			nw++;
		}
	}
	for(int i=1;i<=qt;i++)
		if(qans[i]) printf("Yes\n");
		else printf("No\n");
	return 0;
}