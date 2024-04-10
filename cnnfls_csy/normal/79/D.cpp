#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<iomanip>
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
#define rdst(st,len){char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ int
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
//struct bit_2d{T_ a[2005][2005];int lowbit(int x){return x&(-x);}void add(int x,int y,T_ z){int i,j;for (i=x;i<=2000;i+=lowbit(i)){for (j=y;j<=2000;j+=lowbit(j)){a[i][j]+=z;}}}T_ query(int x,int y){int i,j;T_ s=0;for (i=x;i;i-=lowbit(i)){for (j=y;j;j-=lowbit(j)){s+=a[i][j];}}return s;}T_ query(int x,int y,int xx,int yy){return query(xx,yy)-query(x-1,yy)-query(xx,y-1)+query(x-1,y-1);}};
int n,m,k,seq[105],i,j,a[10005],b[10005],dis[10005],f[20][20],dp[(1<<20)+5],x,y,lg[(1<<20)+5];
vector<int> pos;
queue<int> qx;
void upd(int x,int y){if (1<=x&&x<=n) if (dis[x]>y){dis[x]=y;qx.push(x);}}
int main()
{
	lg[1]=0;
	fz(i,2,(1<<20)) lg[i]=lg[i/2]+1;
	scanf("%d%d%d",&n,&m,&k);
	fz1(i,m)
	{
		scanf("%d",&x);
		a[x]=1;
	}
	n++;
	fz1(i,n) b[i]=(a[i]!=a[i-1]);
	fz1(i,n) if (b[i]) pos.push_back(i);
	fz1(i,k) scanf("%d",&seq[i]);
	fz0k(i,pos.size())
	{
		memset(dis,0x15,sizeof(dis));
		dis[pos[i]]=0;
		qx.push(pos[i]);
		while (!qx.empty())
		{
			x=qx.front();
			qx.pop();
			fz1(j,k){upd(x+seq[j],dis[x]+1);upd(x-seq[j],dis[x]+1);}
		}
		fz0k(j,pos.size()) f[i][j]=dis[pos[j]];
	}
	if (pos.size()&1)
	{
		puts("-1");
		return 0;
	}
	memset(dp,0x15,sizeof(dp));
	dp[(1<<pos.size())-1]=0;
	fd0k(i,(1<<pos.size())) if (dp[i]<0x15151515)
	{
		int t=lg[i&(-i)];
		fz(j,t+1,pos.size()-1) if ((i>>j)&1)
		{
			dp[i^(1<<t)^(1<<j)]=min(dp[i^(1<<t)^(1<<j)],dp[i]+f[t][j]);
		}
	}
	if (dp[0]<0x15151515) printf("%d\n",dp[0]); else puts("-1");
	return 0;
}