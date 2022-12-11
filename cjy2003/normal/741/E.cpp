#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int lg[200020];
namespace SA
{
	int n,sa[200020],rk[200020],xx[200020],yy[200020],t[200020],st[18][200020];
	void getsa(char a[])
	{
		int *x=xx,*y=yy,m=200;
		for(int i=1;i<=n;++i)++t[x[i]=a[i]];
		for(int i=2;i<=m;++i)t[i]+=t[i-1];
		for(int i=n;i;--i)sa[t[x[i]]--]=i;
		memset(t+1,0,m<<2);
		for(int len=1;;len<<=1)
		{
			int tot=0;
			for(int i=n-len+1;i<=n;++i)y[++tot]=i;
			for(int i=1;i<=n;++i)if(sa[i]>len)y[++tot]=sa[i]-len;
			for(int i=1;i<=n;++i)++t[x[i]];
			for(int i=2;i<=m;++i)t[i]+=t[i-1];
			for(int i=n;i;--i)sa[t[x[y[i]]]--]=y[i];
			memset(t+1,0,m<<2);
			swap(x,y);
			x[sa[1]]=1,m=1;
			for(int i=2;i<=n;++i)x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+len]==y[sa[i-1]+len]?m:++m;
			if(m==n)break;
		}
		for(int i=1;i<=n;++i)rk[sa[i]]=i;
		for(int i=1,k=0;i<=n;++i)
		{
			if(rk[i]==1)continue;
			if(k)--k;
			while(a[i+k]==a[sa[rk[i]-1]+k])++k;
			st[0][rk[i]]=k;
		}
		for(int i=1;(1<<i)<=n;++i)
			for(int j=1;j<=n-(1<<i)+1;++j)
				st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	}
	int qlcp(int x,int y)
	{
		if(x==y)return n-x+1;
		x=rk[x],y=rk[y];
		if(x>y)swap(x,y);
		int len=lg[y-x];
		return min(st[len][x+1],st[len][y-(1<<len)+1]);
	}
}
const int siz=300;
char s[200020],t[100010];
int n,m,qnum;
int rk[100010];
int p[100010];
struct query
{
	int l,r,k,x,y,id;
	friend bool operator < (query a,query b){return a.k<b.k;}
}q[100010];
int ans[100010];
void getrk()
{
	for(int i=0;i<=n;++i)p[i]=i;
	sort(p,p+1+n,[&](int x,int y)
		{
			int f=0;
			if(x>y)swap(x,y),f=1;
			if(x+m<=y)
			{
				int l=SA::qlcp(n+1,x+1);
				if(l<m)return (s[n+l+1]<s[x+l+1])^f;
				l=SA::qlcp(x+1,x+m+1);
				if(l<y-x-m)return (s[x+l+1]<s[x+l+m+1])^f;
				l=SA::qlcp(y-m+1,n+1);
				if(l<m)return (s[y-m+1+l]<s[n+1+l])^f;
				return (x<y)^f;
			}
			else
			{
				int l=SA::qlcp(n+1,x+1);
				if(l<y-x)return (s[n+1+l]<s[x+1+l])^f;
				l=SA::qlcp(n+1+y-x,n+1);
				if(l<m-(y-x))return (s[n+1+y-x+l]<s[n+1+l])^f;
				l=SA::qlcp(x+1,n+m-(y-x)+1);
				if(l<y-x)return (s[x+1+l]<s[n+m-(y-x)+1+l])^f;
				return (x<y)^f;
			}
		});
	for(int i=0;i<=n;++i)rk[p[i]]=i;
}
struct Data
{
	vector<vector<int> >st;
	void build(int n,int a[])
	{
		st.resize(lg[n+1]+1);
		for(int i=0;i<=lg[n+1];++i)st[i].resize(n+1);
		for(int i=0;i<=n;++i)st[0][i]=a[i];
		for(int i=1;i<=lg[n+1];++i)
			for(int j=0;j<=n-(1<<i)+1;++j)st[i][j]=rk[st[i-1][j]]<=rk[st[i-1][j+(1<<(i-1))]]?st[i-1][j]:st[i-1][j+(1<<(i-1))];
	}
	int query(int l,int r)
	{
		int len=lg[r-l+1];
		return rk[st[len][l]]<=rk[st[len][r-(1<<len)+1]]?st[len][l]:st[len][r-(1<<len)+1];
	}
}b[310];
int main()
{
	for(int i=2;i<=200000;++i)lg[i]=lg[i>>1]+1;
	scanf("%s %s %d",s+1,t+1,&qnum);
	n=strlen(s+1),m=strlen(t+1);
	SA::n=n+m;
	for(int i=1;i<=m;++i)s[i+n]=t[i];
	SA::getsa(s);
	getrk();
	for(int i=0;i<=n;++i)p[i]=i;
	for(int i=1;i<=qnum;++i)ans[i]=-1;
	for(int i=1;i<=qnum;++i)scanf("%d %d %d %d %d",&q[i].l,&q[i].r,&q[i].k,&q[i].x,&q[i].y),q[i].id=i;
	sort(q+1,q+1+qnum);
	int last=1;
	for(int k=1;k<=siz;++k)
	{
		for(int i=0;i<k;++i)
		{
			for(int j=0;k*j+i<=n;++j)p[j]=k*j+i;
			if(i<=n)b[i].build((n-i)/k,p);
		}
		while(q[last].k==k)
		{
			int x=q[last].x,y=q[last].y,l=q[last].l,r=q[last].r,id=q[last].id;
			for(int i=x;i<=y;++i)
				if(i<=r)
				{
					int nl=(l-i+k-1)/k,nr=(r-i)/k,cur;
					if(nl<=nr)
					{
						cur=b[i].query(nl,nr);
						if(ans[id]<0||rk[cur]<rk[ans[id]]||(rk[cur]==rk[ans[id]]&&cur<ans[id]))ans[id]=cur;
					}
				}
			++last;
		}
	}
	for(int i=0;i<=n;++i)p[i]=i;
	b[0].build(n,p);
	while(last<=qnum)
	{
		int x=q[last].x,y=q[last].y,l=q[last].l,r=q[last].r,id=q[last].id,k=q[last].k;
		for(int i=0;i<=n;i+=k)
		{
			int nl=i+x,nr=i+y;
			if(nr<l||nl>r)continue;
			nl=max(nl,l);nr=min(nr,r);
			int cur=b[0].query(nl,nr);
			if(ans[id]<0||rk[cur]<rk[ans[id]]||(rk[cur]==rk[ans[id]]&&cur<ans[id]))ans[id]=cur;
		}
		++last;
	}
	for(int i=1;i<=qnum;++i)printf("%d ",ans[i]);
	return 0;
}