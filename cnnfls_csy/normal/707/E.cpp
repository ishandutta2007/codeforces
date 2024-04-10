#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x)(x)*(x)
#define fz1(i,n) for (i=1;i<=n;i++)
#define fd1(i,n) for (i=n;i>=1;i--)
#define fz0g(i,n) for (i=0;i<=n;i++)
#define fd0g(i,n) for (i=n;i>=0;i--)
#define fz0k(i,n) for (i=0;i<n;i++)
#define fd0k(i,n) for (i=(long long)(n-1);i>=0;i--)
#define fz(i,x,y) for (i=x;i<=y;i++)
#define fd(i,y,x) for (i=y;i>=x;i--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
long long n,m,k,q,i,j,ans[1000005],x,y,px[1000005],py[1000005],qx[1000005],qy[1000005];
struct TBIT
{
	long long arr[2005][2005];
	int lowbit(int x) {return x&(-x);}
	void add(long long x,long long y,long long z)
	{
		for (int i=x;i<=n;i+=lowbit(i))
		{
			for (int j=y;j<=m;j+=lowbit(j))
			{
				arr[i][j]+=z;
			}
		}
	}
	long long query(long long x,long long y)
	{
		long long s=0;
		for (int i=x;i>0;i-=lowbit(i)) 
		{
			for (int j=y;j>0;j-=lowbit(j))
			{
				s+=arr[i][j];
			}
		} 
		return s;
	}
}c;
vector<pair<pair<long long,long long>,long long> > pnt[2005];
vector<long long> op[2005];
int main()
{
	scanf("%I64d",&n);
	scanf("%I64d",&m);
	scanf("%I64d",&k);
	fz1(i,k)
	{
		long long len;
		scanf("%I64d",&len);
		while (len--)
		{
			long long z;
			scanf("%I64d%I64d%I64d",&x,&y,&z);
			pnt[i].push_back(make_pair(make_pair(x,y),z));
		}
	}
	scanf("%I64d",&q);
	fz1(i,q)
	{
		string st;
		rdst(st,7);
		if (st=="SWITCH")
		{
			scanf("%I64d",&x);
			op[x].push_back(0);
		}
		else
		{
			scanf("%I64d%I64d%I64d%I64d",&px[i],&py[i],&qx[i],&qy[i]);
			fz1(j,k) op[j].push_back(i);
		}
	}
	fz1(i,k)
	{
		ff(pnt[i],it) c.add(it->first.first,it->first.second,it->second);
		long long t=1;
		ff(op[i],it)
		{
			if (*it==0) t^=1; else if (t) ans[*it]+=c.query(qx[*it],qy[*it])-c.query(px[*it]-1,qy[*it])-c.query(qx[*it],py[*it]-1)+c.query(px[*it]-1,py[*it]-1);
		}
		ff(pnt[i],it) c.add(it->first.first,it->first.second,-(it->second));
	}
	fz1(i,q) if (px[i]) printf("%I64d\n",ans[i]);
	return 0;
}