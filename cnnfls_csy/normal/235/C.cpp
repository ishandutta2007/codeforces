#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<iomanip>
#define sqr(x) (x)*(x)
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){char ss[len];scanf("%s",ss);(st)=ss;}
#define rdst2(st,len){char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ long long
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
int n,m,i,j,cnt=1,lst=1,c[2000005][26],f[2000005],l[2000005],sz[2000005],vis[2000005],p,q,np,nq,qx[2000005],ql,qr,x,y,ti;
string st;
vector<int> bi[2000005];
int main()
{
	rdst(st,1000005);
	fz0k(i,st.length())
	{
		p=lst;
		np=++cnt;
		lst=np;
		sz[np]=1;
		l[np]=l[p]+1;
		for (;p&&!c[p][st[i]-'a'];p=f[p]) 
		{
			c[p][st[i]-'a']=np;
		}
		if (!p)
		{
			f[np]=1;
			continue;
		}
		q=c[p][st[i]-'a'];
		if (l[p]+1==l[q])
		{
			f[np]=q;
			continue;
		}
		nq=++cnt;
		l[nq]=l[p]+1;
		memcpy(c[nq],c[q],sizeof(c[nq]));
		f[nq]=f[q];
		f[np]=nq;
		f[q]=nq;
		for (;p&&c[p][st[i]-'a']==q;p=f[p])
		{
			c[p][st[i]-'a']=nq;
		}
	}
	fz1(i,cnt)
	{
		if (i!=1)
		{
			bi[f[i]].push_back(i);
		}
	}
	ql=1;
	qr=1;
	qx[1]=1;
	while (ql<=qr)
	{
		x=qx[ql];
		ql++;
		ff(bi[x],it)
		{
			qr++;
			qx[qr]=*it;
		}
	}
	fd1(i,cnt)
	{
		x=qx[i];
		if (x!=1)
		{
			sz[f[x]]+=sz[x];
		}
	}
	scanf("%d",&n);
	while (n--)
	{
		rdst2(st,1000005);
		long long ans=0;
		x=1;
		int len=st.length(),cur=0;
		st=st+st;
		ti++;
		fz0k(i,len+len)
		{
			if (c[x][st[i]-'a'])
			{
				cur++;
				x=c[x][st[i]-'a'];
			}
			else
			{
				while (x&&!c[x][st[i]-'a'])
				{
					x=f[x];
				}
				if (c[x][st[i]-'a'])
				{
					cur=l[x]+1;
					x=c[x][st[i]-'a'];
				}
				else
				{
					x=1;
					cur=0;
				}
			}
			if (i>=len&&cur>=len)
			{
				y=x;
				while (y&&len<=l[f[y]]) y=f[y];
				if (len>l[y]) continue;
				if (y==0) y=1;
				if (vis[y]!=ti)
				{
					vis[y]=ti;
					ans+=sz[y];
				}
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}