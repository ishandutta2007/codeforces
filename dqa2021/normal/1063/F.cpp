#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
char s[500010];
namespace SA
{
	int sa[500010],ht[500010][19],rk[500010],t1[500010],t2[500010],c[500010],bt[500010];
	void getsa()
	{
		int *x=t1,*y=t2,p,m=30; bt[0]=-1;
		for (int i=1;i<=n;i++) c[s[i]-'a'+1]++,bt[i]=bt[i>>1]+1;
		for (int i=1;i<=m;i++) c[i]+=c[i-1];
		for (int i=n;i;i--) sa[c[s[i]-'a'+1]--]=i;
		p=x[sa[1]]=1;
		for (int i=1;i<=n;i++)
		{
			if (s[sa[i]]!=s[sa[i-1]]) p++;
			x[sa[i]]=p;
		}
		for (int i=1;p<n;m=p,i<<=1)
		{
			p=0;
			for (int j=n-i+1;j<=n;j++) y[++p]=j;
			for (int j=1;j<=n;j++) if (sa[j]>i) y[++p]=sa[j]-i;
			memset(c+1,0,m*sizeof(int));
			for (int j=1;j<=n;j++) c[x[y[j]]]++;
			for (int j=1;j<=m;j++) c[j]+=c[j-1];
			for (int j=n;j;j--) sa[c[x[y[j]]]--]=y[j];
			swap(x,y); p=x[sa[1]]=1;
			for (int j=2;j<=n;j++)
			{
				if (y[sa[j]]!=y[sa[j-1]]||(sa[j]+i<=n?y[sa[j]+i]:0)!=(sa[j-1]+i<=n?y[sa[j-1]+i]:0)) p++;
				x[sa[j]]=p;
			}
		}
		for (int i=1;i<=n;i++) rk[sa[i]]=i;
		p=0;
		for (int i=1;i<=n;i++)
		{
			if (p) p--;
			if (rk[i]==1) continue;
			int t=sa[rk[i]-1];
			while (t+p<=n&&i+p<=n&&s[t+p]==s[i+p]) p++;
			ht[rk[i]][0]=p;
		}
		for (int j=1;j<19;j++)
			for (int i=1;i+(1<<j)-1<=n;i++)
				ht[i][j]=min(ht[i][j-1],ht[i+(1<<j-1)][j-1]);
	}
	int getlcp(int x,int y)
	{
		if (x==y) return n-x+1;   //right? yes
		x=rk[x],y=rk[y]; if (x>y) swap(x,y); x++;
		int tmp=bt[y-x+1];
		return min(ht[x][tmp],ht[y-(1<<tmp)+1][tmp]);
	}
}
using namespace SA;  //ok? ok
namespace Seg
{
	#define mid (l+r>>1)
	struct Node{
		int lson,rson,val;
	}node[500000*20+10];
	int idtot,rt[500010];
	void update(int &u,int v,int l,int r,int pos,int val)
	{
		node[u=++idtot]=node[v];
		if (l==r) return node[u].val=val,void();
		if (pos<=mid) update(node[u].lson,node[v].lson,l,mid,pos,val);
		else update(node[u].rson,node[v].rson,mid+1,r,pos,val);
		node[u].val=max(node[node[u].lson].val,node[node[u].rson].val);
	}
	int query(int cur,int l,int r,int ql,int qr)
	{
		if (!cur) return 0;  //ok? ok
		if (l==ql&&r==qr) return node[cur].val;
		if (qr<=mid) return query(node[cur].lson,l,mid,ql,qr);
		if (ql>mid) return query(node[cur].rson,mid+1,r,ql,qr);
		return max(query(node[cur].lson,l,mid,ql,mid),query(node[cur].rson,mid+1,r,mid+1,qr));
	}
	#undef mid
}
using namespace Seg;  //ok? ok
int dp[500010],ans=1;

int main()
{
	scanf("%d%s",&n,s+1);
	getsa();
//	for (int i=1;i<=n;i++) printf("%d ",sa[i]); puts("");
//	for (int i=1;i<=n;i++) printf("%d ",rk[i]); puts("");
//	for (int i=1;i<=n;i++) printf("%d ",ht[i][0]); puts("");
	dp[n]=1; update(rt[n],rt[n+1],1,n,rk[n],dp[n]);
	for (int i=n-1;i;i--)
	{
		for (int j=dp[i+1]+1;;j--)   //caution j=1  ok
		{
//			printf("pos %d try %d\n",i,j);
			int maxl,maxr,l=1,r=rk[i],mid;
			while (l<r)
			{
				mid=l+r>>1;
				if (getlcp(sa[mid],i)>=j-1) r=mid;
				else l=mid+1;
			}
			maxl=l;
			l=rk[i],r=n;
			while (l<r)
			{
				mid=l+r+1>>1;
				if (getlcp(i,sa[mid])>=j-1) l=mid;
				else r=mid-1;
			}
			maxr=l;
//			printf("maxl %d maxr %d query %d\n",maxl,maxr,query(rt[i+j],1,n,maxl,maxr));
			if (query(rt[i+j],1,n,maxl,maxr)>=j-1){dp[i]=j;break;}
			l=1,r=rk[i+1];
			while (l<r)
			{
				mid=l+r>>1;
				if (getlcp(sa[mid],i+1)>=j-1) r=mid;
				else l=mid+1;
			}
			maxl=l;
			l=rk[i+1],r=n;
			while (l<r)
			{
				mid=l+r+1>>1;
				if (getlcp(i+1,sa[mid])>=j-1) l=mid;
				else r=mid-1;
			}
			maxr=l;
//			printf("maxl %d maxr %d query %d\n",maxl,maxr,query(rt[i+j],1,n,maxl,maxr));
			if (query(rt[i+j],1,n,maxl,maxr)>=j-1){dp[i]=j;break;}
		}
		update(rt[i],rt[i+1],1,n,rk[i],dp[i]);
		ans=max(ans,dp[i]);
//		printf("dp %d = %d\n",i,dp[i]);   //!!!
//		printf("add rk %d\n",rk[i]);
	}
	printf("%d\n",ans);
	return 0;
}