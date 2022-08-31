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
int n,m,i,j,fa[505],a,b,sum,cnt,cnt2;
long long ans=9223372036854775807ll;
struct ii
{
	int x,y,g,s;
}bian[100005],tmp[100005];
bool cmp(ii x,ii y)
{
	return x.g<y.g;
}
bool cmp2(ii x,ii y)
{
	return x.s<y.s;
}
int fnd(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=fnd(fa[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d",&a,&b);
	fz1(i,m)
	{
		scanf("%d%d%d%d",&bian[i].x,&bian[i].y,&bian[i].g,&bian[i].s);
	}
	fz1(i,n) fa[i]=i;
	sort(bian+1,bian+m+1,cmp);
	fz1(i,m)
	{
		tmp[++cnt]=bian[i];
		inplace_merge(tmp+1,tmp+cnt,tmp+cnt+1,cmp2);
		fz1(j,n) fa[j]=j;
		cnt2=0;
		for (j=1;j<=cnt;j++)
		{
			long long fx=fnd(tmp[j].x),fy=fnd(tmp[j].y);
			if (fnd(fx)==fnd(fy)) continue;
			fa[fx]=fy;
			tmp[++cnt2]=tmp[j];
			if (cnt2==n-1) break;
		}
		cnt=cnt2;
		if (cnt==n-1)
		{
			ans=min(ans,1ll*bian[i].g*a+1ll*tmp[cnt].s*b);
		}
	}
	if (ans>=9223372036854775807ll) puts("-1"); else printf("%I64d\n",ans);
	return 0;
}