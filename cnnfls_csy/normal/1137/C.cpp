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
#include<stack>
#define sqr(x) (x)*(x)
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ int
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
//struct bit_2d{T_ a[2005][2005];int lowbit(int x){return x&(-x);}void add(int x,int y,T_ z){int i,j;for (i=x;i<=2000;i+=lowbit(i)){for (j=y;j<=2000;j+=lowbit(j)){a[i][j]+=z;}}}T_ query(int x,int y){int i,j;T_ s=0;for (i=x;i;i-=lowbit(i)){for (j=y;j;j-=lowbit(j)){s+=a[i][j];}}return s;}T_ query(int x,int y,int xx,int yy){return query(xx,yy)-query(x-1,yy)-query(xx,y-1)+query(x-1,y-1);}};
int n,m,d,i,j,a[100005],f[100005][55],g[100005][55],cnt,cc[55],dfn[100005],low[100005],col[100005],ti,vis[100005],ans,dp[200005][55],x,y;
queue<int> qx,qy;
vector<int> seq[100005];
stack<int> stk;
vector<int> bi[100005],fbi[100005];
char ss[55];
string st[100005];
void tarjan(int x)
{
	dfn[x]=low[x]=++ti;
	stk.push(x);
	ff(bi[x],it)
	{
		if (!dfn[*it]) {tarjan(*it);low[x]=min(low[x],low[*it]);} else if (!col[*it]) low[x]=min(low[x],dfn[*it]);
	}
	if (low[x]==dfn[x])
	{
		cnt++;
		while (stk.top()!=x) {col[stk.top()]=cnt;seq[cnt].push_back(stk.top());stk.pop();}
		col[stk.top()]=cnt;stk.pop();seq[cnt].push_back(x);
	}
}
bool dfs1(int x,int y)
{
	if (f[x][y]!=-1) return f[x][y];
}
int dfs3(int x,int y)
{
	if (x==1+n&&y==0)
	{
		return dp[x][y]=g[col[x-n]][y];
	}
	if (dp[x][y]!=-1) return dp[x][y];
	int i;
	int t=vis[col[(x-1)%n+1]];
	dp[x][y]=(-1<<25);
	if (x<=n)
	{
		fz0k(i,d) if (f[x][i]) dp[x][y]=max(dp[x][y],dfs3(t+n,(y+d-i)%d));
	}
	else
	{
		ff(seq[col[t]],iit)
		{
			ff(fbi[*iit],it) if (col[*it]!=col[t]) fz0k(i,d) if (f[*iit][i])
			{
				dp[x][y]=max(dp[x][y],dfs3(*it,(y+d-1+i)%d));
			}
		}
		int t=0;
		fz0k(i,d) if (f[x-n][i]) t=max(t,g[col[x-n]][(y+d-i)%d]); 
		dp[x][y]+=t;
	}
	return dp[x][y];
}
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	fz1(i,m)
	{
		scanf("%d%d",&x,&y);
		bi[x].push_back(y);
		fbi[y].push_back(x);
	}
	fz1(i,n)
	{
		scanf(" %s",ss); 
		st[i]=ss;
	}
	tarjan(1);
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	memset(dp,-1,sizeof(dp));
	fz1(i,n) if (dfn[i])
	{
		if (!vis[col[i]]) {vis[col[i]]=i;f[i][0]=1;qx.push(i);qy.push(0);}
	}
	while (!qx.empty())
	{
		int x=qx.front(),y=qy.front();
		qx.pop();qy.pop();
		ff(bi[x],it) if (col[*it]==col[x])
		{
			if (!f[*it][(y+1)%d])
			{
				f[*it][(y+1)%d]=1;
				qx.push(*it);qy.push((y+1)%d);
			}
		}
	}
	fz1(i,n) if (dfn[i])
	{
		int t;memset(cc,0,sizeof(cc));
		fz0k(t,d) if (st[i][t]=='1')
		{
			fz0k(j,d) cc[(t+d-j)%d]|=dfs1(i,j);
		}
		fz0k(j,d) g[col[i]][j]+=cc[j];
	}
	fz1(i,cnt) fz0k(j,d) ans=max(ans,dfs3(vis[i],j));
	cout<<ans<<endl;
	return 0;
}