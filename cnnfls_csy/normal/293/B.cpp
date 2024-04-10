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
//struct bit{T_ arr[1000005];long long lowbit(long long x){return x&(-x);}void add(long long x,T_ y){for (long long i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(long long x){T_ s=0;for (long long i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{long long l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(long long id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(long long id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(long long id,long long l,long long r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{long long mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(long long id,long long le,long long ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(long long id,long long le,long long ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
int n,m,i,j,k,num[20][20],col[20][20],vis[20][20],lk[20],used[20],ss[20];
long long mod=1e9+7;
long long calc()
{
	memset(ss,-1,sizeof(ss));
	memset(lk,-1,sizeof(lk));
	memset(used,0,sizeof(used));
	int i,j;
	fz0k(i,n) fz0k(j,m) used[col[i][j]]=1;
	fz0k(i,n) fz0k(j,m) if(~num[i][j])
	{
		if (lk[num[i][j]]!=-1&&lk[num[i][j]]!=col[i][j]) return 0;
		lk[num[i][j]]=col[i][j];
		if (ss[col[i][j]]!=-1&&ss[col[i][j]]!=num[i][j]) return 0;
		ss[col[i][j]]=num[i][j];
	}
	int ned=0;
	fz0k(i,k) if (used[i]) ned++;
	int emp=0,cont=0;
	fz0k(i,k)
	{
		if (used[i]&&ss[i]==-1) ++emp;
		if (ss[i]!=-1) ++cont;
	}
	long long ans=1;
	fz0k(i,emp) ans*=(k-cont-i);
	ans%=mod;
	return ans;
}
long long dfs(int x,int y,int cnt)
{
	if (y==m)
	{
		return dfs(x+1,0,cnt);
	}
	if (x==n) return calc();
	long long res=0;
	vis[x][y]=((x>0?vis[x-1][y]:0)|(y>0?vis[x][y-1]:0));
	int i;
	fz0k(i,min(cnt+1,k))
	{
		if (vis[x][y]>>i&1) continue;
		vis[x][y]|=(1<<i);
		col[x][y]=i;
		res+=dfs(x,y+1,max(cnt,i+1));
		if (res>=mod) res-=mod;
		vis[x][y]^=(1<<i);
	}
	return res;
}
int main()
{
	cin>>n>>m>>k;
	if (n+m-1>k)
	{
		cout<<0;
		return 0;
	}
	fz0k(i,n)fz0k(j,m)
	{
		cin>>num[i][j];
		num[i][j]--;
	}
	cout<<dfs(0,0,0);
	return 0;
}