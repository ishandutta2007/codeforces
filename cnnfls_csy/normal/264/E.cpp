#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
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
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ int
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
//struct bit_2d{T_ a[2005][2005];int lowbit(int x){return x&(-x);}void add(int x,int y,T_ z){int i,j;for (i=x;i<=2000;i+=lowbit(i)){for (j=y;j<=2000;j+=lowbit(j)){a[i][j]+=z;}}}T_ query(int x,int y){int i,j;T_ s=0;for (i=x;i;i-=lowbit(i)){for (j=y;j;j-=lowbit(j)){s+=a[i][j];}}return s;}T_ query(int x,int y,int xx,int yy){return query(xx,yy)-query(x-1,yy)-query(xx,y-1)+query(x-1,y-1);}};
int n,m,i,j,op,x,y,xty[500025],ytx[500025];
set<int> s;
struct seg
{
	int mx[4000005],dp[500025];
	void pushup(int x)
	{
		mx[x]=max(mx[x*2],mx[x*2+1]);
	}
	void update(int x,int tl,int tr,int y,int c)
	{
		if (tl>y||tr<y) return;
		if (tl==tr)
		{
			mx[x]=c;
			return;
		}
		update(x*2,tl,(tl+tr)/2,y,c);
		update(x*2+1,(tl+tr)/2+1,tr,y,c);
		pushup(x);
	}
	int query(int x,int tl,int tr,int ql,int qr)
	{
		if (tl>qr||tr<ql) return 0;
		if (tl>=ql&&tr<=qr) return mx[x];
		return max(query(x*2,tl,(tl+tr)/2,ql,qr),query(x*2+1,(tl+tr)/2+1,tr,ql,qr));
	}
	void upd(int x)
	{
		update(1,1,500005,x,dp[x]=(query(1,1,500005,1,x-1)+1));
	}
}t1,t2;
int main()
{
	scanf("%d%d",&n,&m);
	fz1(j,m)
	{
		scanf("%d",&op);
		if (op==1)
		{
			scanf("%d%d",&x,&y);x=n-x+1;
			y=15-y+j;ytx[y]=x;xty[x]=y;
			for (i=y+1;i<=y+10;i++) if (ytx[i])
			{
				t1.update(1,1,500005,i,0);
				t2.update(1,1,500005,ytx[i],0);
//				t1.dp[i]=t2.dp[ytx[i]]=0;
			}
			for (i=y;i<=y+10;i++) if (ytx[i])
			{
				t2.upd(ytx[i]);
				t1.dp[i]=t2.dp[ytx[i]];
				t1.update(1,1,500005,i,t1.dp[i]);
			}
			s.insert(x);
		}
		else
		{
			scanf("%d",&x);
			set<int>::iterator it;
			int cnt;
			for (cnt=1,it=--s.end();cnt<=x;cnt++)
			{
				if (cnt!=1) it--;
				t2.update(1,1,500005,*it,0);
				t1.update(1,1,500005,xty[*it],0);
//				t2.dp[*it]=t1.dp[xty[*it]]=0;
			}
			x=*it;
			for (it++;it!=s.end();it++)
			{
				t1.upd(xty[*it]);
				t2.dp[*it]=t1.dp[xty[*it]];
				t2.update(1,1,500005,*it,t2.dp[*it]);
			}
			ytx[xty[x]]=0;
			xty[x]=0;
			s.erase(x);
		}
		printf("%d\n",t2.query(1,1,500005,1,500005));
	}
	return 0;
}