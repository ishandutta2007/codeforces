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
#define rdst(st,len){char ss[len];scanf("%s",ss);(st)=ss;}w
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;avoid update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[iwwwwwwwd].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
int n,m,q,i,j,fa[100005][18],x,y,z,a[100005],dep[100005];
vector<int> bi[100005],mi[100005][18];
void dfs1(int x,int p)
{
	fa[x][0]=p;
	ff(bi[x],it) if (*it!=p)
	{
		dep[*it]=dep[x]+1;
		dfs1(*it,x);
	}
}
vector<int> mrg(vector<int> x,vector<int> y)
{
	vector<int> ans;ans.clear();
	int i=0,j=0,k=0;
//	ff(x,it) cerr<<*it<<' ';cerr<<endl;
//	ff(y,it) cerr<<*it<<' ';cerr<<endl;
	while (i<x.size()&&j<y.size()&&k<10)
	{
		k++;
		if (x[i]<y[j]) ans.push_back(x[i++]); else ans.push_back(y[j++]);
	}
	while (i<x.size()&&k<10)
	{
		k++;
		ans.push_back(x[i++]);
	}
	while (j<y.size()&&k<10)
	{
		k++;
		ans.push_back(y[j++]);
	}
//	ff(ans,it) cerr<<*it<<' ';cerr<<endl;
	return ans;
}
void solve(int x,int y,int z)
{
	if (dep[x]>dep[y]) swap(x,y);
	int i,t=dep[y]-dep[x];
	vector<int> ans;ans.clear();
	for (i=17;i>=0;i--) if ((t>>i)&1)
	{
		ans=mrg(ans,mi[y][i]);
		y=fa[y][i];
	}
	if (x==y)
	{
		ans=mrg(ans,mi[x][0]);
		while (ans.size()>z) ans.pop_back();
		printf("%d ",ans.size());
		ff(ans,it) printf("%d ",*it);
		puts("");
		return;
	}
	for (i=17;i>=0;i--) if (fa[x][i]!=fa[y][i]) 
	{
		ans=mrg(ans,mi[x][i]);
		x=fa[x][i];
		ans=mrg(ans,mi[y][i]);
		y=fa[y][i];
	}
	ans=mrg(ans,mi[x][0]);
	ans=mrg(ans,mi[y][0]);
	ans=mrg(ans,mi[fa[x][0]][0]);
	while (ans.size()>z) ans.pop_back();
	printf("%d ",ans.size());
	ff(ans,it) printf("%d ",*it);
	puts("");
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	fz1(i,n-1)
	{
		scanf("%d%d",&x,&y);
		bi[x].push_back(y);bi[y].push_back(x);
	}
	fz1(i,m)
	{
		scanf("%d",&x);
		mi[x][0].push_back(i);
	}
	fz1(i,n)
	{
		sort(mi[x][0].begin(),mi[x][0].end());
		while (mi[x][0].size()>10) mi[x][0].pop_back();
	}
	dfs1(1,0);
//	ff(mi[5][0],it) cerr<<*it<<' ';cerr<<endl;
	fz1(j,17)
	{
		fz1(i,n)
		{
			fa[i][j]=fa[fa[i][j-1]][j-1];
			mi[i][j]=mrg(mi[i][j-1],mi[fa[i][j-1]][j-1]);
		}
	}
//	ff(mi[5][0],it) cerr<<*it<<' ';cerr<<endl;
	while (q--)
	{
		scanf("%d%d%d",&x,&y,&z);
		solve(x,y,z);
	}
	return 0;
}