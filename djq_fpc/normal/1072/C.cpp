#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
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
#define rdst(st,len){char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
long long n,m,i,j,l,r,mid,ans,s1,s2;
vector<long long> v1,v2;
bool check(long long x)
{
	long long t=n,i,s=0;
	for	(i=x;i>=1;i--)
	{
		if (t>=i)
		{
			t-=i;
		}
		else
		{
			s+=i;
		}
	}
	return s<=m;
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	ans=l=0;r=sqrt(1e10);
	while (l<r)
	{
		mid=(l+r)/2;
		if (check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid;
	}
//	printf("%I64d\n",ans);
	long long t=n,i,s=0;
	for	(i=ans;i>=1;i--)
	{
		if (t>=i)
		{
			t-=i;
			v1.push_back(i);
		}
		else
		{
			s+=i;
			v2.push_back(i);
		}
	}
	printf("%I64d\n",(long long)v1.size());
	ff(v1,it) printf("%I64d ",*it);puts("");
	printf("%I64d\n",(long long)v2.size());
	ff(v2,it) printf("%I64d ",*it);puts("");
	return 0;
}