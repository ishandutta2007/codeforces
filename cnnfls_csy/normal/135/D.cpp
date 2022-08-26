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
int n,m,i,j,id[1005][1005],cnt,vis[1005][1005],ans,ti;
int dx[9]={0,-1,1,0,0,-1,-1,1,1};
int dy[9]={0,0,0,-1,1,-1,1,-1,1}; 
char c;
vector<pair<int,int> > seq;
bool dfs(int x,int y,int ti)
{
	if (x<1||x>n||y<1||y>m) return 0;
	if (id[x][y])
	{
		if (vis[x][y]==ti) return 1;
		vis[x][y]=ti;
		seq.push_back(make_pair(x,y));
		return 1;
	}
	if (vis[x][y]) return 1;
	vis[x][y]=ti;
	int i,f=1;
	fz1(i,8)
	{
		if (!dfs(x+dx[i],y+dy[i],ti)) f=0;
	}
	return f;
}
bool check()
{
	if (seq.empty()) return 0;
	int i,j,s=0;
	queue<int> qx,qy;
	qx.push(seq[0].first);qy.push(seq[0].second);
	s=1;vis[qx.front()][qy.front()]=-ti;
	while (!qx.empty())
	{
		int x=qx.front(),y=qy.front();
		qx.pop();qy.pop();
		int deg=0;
		fz1(i,4)
		{
			if (id[x+dx[i]][y+dy[i]]&&vis[x+dx[i]][y+dy[i]]==ti)
			{
				vis[x+dx[i]][y+dy[i]]=-ti;
				s++;
				qx.push(x+dx[i]);
				qy.push(y+dy[i]);
			}
			if (id[x+dx[i]][y+dy[i]]&&vis[x+dx[i]][y+dy[i]]==-ti) deg++;
		}
		if (deg!=2) return 0;
	}
	return s==seq.size();
}
int main()
{
	scanf("%d%d",&n,&m);
	fz1(i,n)
	{
		scanf(" ");
		fz1(j,m)
		{
			scanf("%c",&c);
			if (c=='1')
			{
				id[i][j]=++cnt;
			}
		}
	}
	fz1(i,n-1)
	{
		fz1(j,m-1)
		{
			if (id[i][j]&&id[i][j+1]&&id[i+1][j]&&id[i+1][j+1]) ans=4;
		}
	}
	fz1(i,n) fz1(j,m) if (!id[i][j]&&!vis[i][j])
	{
		seq.clear();
		if (dfs(i,j,++ti)&&check()) ans=max(ans,(int)seq.size());
	}
	cout<<ans<<endl;
	return 0;
}