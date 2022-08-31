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
//struct bit{int arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,int y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}int query(int x){int s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
struct seg{struct treedot{int l,r;int sum,add;void update(int x){sum+=x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=min(c[id*2].sum,c[id*2+1].sum);}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,int x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}};
seg tr;
int n,m,k,i,j,x,b[150005],a[150005],ans;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	fz1(i,m)
	{
		scanf("%d",&b[i]);
		b[i]=k-b[i];
	}
	sort(b+1,b+m+1);
	fz1(i,n) scanf("%d",&a[i]);
	tr.build(1,1,m);
	fz1(i,m) tr.update(1,i,i,i-m-1);
	fz1(i,n)
	{
		a[i]=upper_bound(b+1,b+m+1,a[i])-b-1;
	}
	fz1(i,m)
	{
		tr.update(1,1,a[i],1);
	}
	ans+=(tr.c[1].sum>=0);
	fz(i,m+1,n)
	{
		tr.update(1,1,a[i-m],-1);
		tr.update(1,1,a[i],1);
		ans+=(tr.c[1].sum>=0);
	}
	cout<<ans<<endl;
	return 0;
}