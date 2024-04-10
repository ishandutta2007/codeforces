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
//#define T_ long long
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
long long n,m,i,j,a[500005],b[500005],s[500005],l,r,mid,ans1,ans2,f,ss;
int check(long long x)
{
	if ((x&1)!=ss) x++;
	if (x>n) return -1;
	memcpy(b,a,sizeof(a));
	b[n+1]=x;
	sort(b+1,b+n+2,greater<int>());
	long long l=0,i,j=n+1,r=0;
	fz1(i,n+1)
	{
		s[i]=s[i-1]+b[i];
	}
	fz1(i,n+1)
	{
		while (j>i&&b[j]<=i)
		{
			j--;
		}
		j=max(j,i);
		l+=b[i];
		if (l>i*(i-1)+s[n+1]-s[j]+(j-i)*i)
		{
			if (b[i]<=x) return -1;
			if (b[i]>x) return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%I64d",&n);
	fz1(i,n)
	{
		scanf("%I64d",&a[i]);
		ss+=a[i];
	}
//	fz0g(i,n) cerr<<check(i)<<endl;
	ss=(ss&1);
	l=0;r=n+1;f=-1;
	while (l<r)
	{
		mid=(l+r)/2;
		long long t=check(mid);
		if (t==0)
		{
			f=mid;
			break;
		}
		if (t==1) l=mid+1; else r=mid;
	}
	if (f==-1)
	{
		puts("-1");
		return 0;
	}
	if ((f&1)!=ss) f++;
	l=-1;r=f;
	while (l<r)
	{
		mid=(l+r+1)/2;
		long long t=check(mid);
		if (t==0)
		{
			ans1=mid;
			r=mid-1;
		}
		else if (t==1) l=mid; else r=mid-1;
	}
	l=f;r=n+1;
	while (l<r)
	{
		mid=(l+r)/2;
		long long t=check(mid);
		if (t==0)
		{
			ans2=mid;
			l=mid+1;
		}
		else if (t==1) l=mid+1; else r=mid;
	}
	fz(i,ans1,ans2) if ((i&1)==ss) printf("%I64d ",i);
	return 0;
}