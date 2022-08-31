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
int n,m,i,j,dis[3005][3005],vis[3005],rt[3005],ic[3005],x,y,qx[3005],b,e,pre[3005];
vector<int> bi[3005],cir;
double ans;
void bfs(int x)
{
	qx[b=e=1]=x;
	memset(dis[x],15,sizeof(dis[x]));
	dis[x][x]=0;
	while (b<=e)
	{
		int y=qx[b++];
		ff(bi[y],it)
		{
			if (dis[x][*it]>dis[x][y]+1)
			{
				dis[x][*it]=dis[x][y]+1;
				qx[++e]=*it;
			}
		}
	}
}
void dfs1(int x,int fa)
{
	pre[x]=fa;
	vis[x]=1;
	ff(bi[x],it)
	{
		if (*it==fa) continue;
		if (vis[*it]==0) dfs1(*it,x);
		else if (vis[*it]==1)
		{
			cir.push_back(*it);ic[*it]=1;
			int y=x;
			while (y!=*it)
			{
				cir.push_back(y);ic[y]=1;
				y=pre[y];
			}
		}
	}
	vis[x]=2;
}
void dfs2(int x,int fa,int a)
{
	rt[x]=a;
	ff(bi[x],it)
	{
		if (*it==fa||ic[*it]) continue;
		dfs2(*it,x,a);
	}
}
int main()
{
	scanf("%d",&n);
	fz1(i,n)
	{
		scanf("%d%d",&x,&y);x++;y++;
		bi[x].push_back(y);
		bi[y].push_back(x);
	}
	fz1(i,n) bfs(i);
	dfs1(1,0);
	ff(cir,it) dfs2(*it,0,*it);
	fz1(i,n) fz1(j,n) if (rt[i]==rt[j]) ans+=1.0/(dis[i][j]+1);
	else
	{
		int d1=dis[rt[i]][rt[j]];
		int d2=cir.size()-d1;
		int d3=dis[i][j]-d1;
		ans+=1.0/(d1+d3+1)+1.0/(d2+d3+1)-1.0/(d1+d2+d3);
	}
	printf("%.10f\n",ans);
	return 0;
}