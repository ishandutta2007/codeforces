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
long long n,m,k,i,j,lim[9][9],lim2[9][9],a[9][9],s,mod=1e9+7;
vector<long long> v;
long long dfs(long long x,long long y,long long cnt)
{
	if (x>n) return 1;
	if (y>m) return dfs(x+1,1,cnt);
	long long ans=0,i;
	lim[x][y]=lim[x-1][y]|lim[x][y-1];
	for (i=0;i<k;i++)
	{
		if (a[x][y]!=-1&&a[x][y]!=i) continue;
		if (lim[x][y]&(1<<i)) continue;
		if (lim2[x][y]&(1<<i)) continue;
		if (!((1<<i)&s))
		{
			if (a[x][y]==-1&&v[cnt]<i) continue;
		}
		lim[x][y]^=(1<<i);
		long long s=dfs(x,y+1,min((long long)((int)v.size()-1),cnt+(v[cnt]==i)));
		if (i==v[cnt]&&a[x][y]==-1) (ans+=s*(v.size()-cnt))%=mod; else (ans+=s)%=mod;
		lim[x][y]^=(1<<i);
	}
	return ans;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	if (n+m>11||n+m-1>k)
	{
		cout<<0;
		return 0;
	}
	fz1(i,n)
	{
		fz1(j,m)
		{
			scanf("%I64d",&a[i][j]);
			a[i][j]--;
			if (a[i][j]>=0) s|=(1<<a[i][j]);
			if (a[i][j]>=0) lim2[i-1][j]|=(1<<a[i][j]);
			if (a[i][j]>=0) lim2[i][j-1]|=(1<<a[i][j]);
		}
	}
	fd1(i,n)
	{
		fd1(j,m)
		{
			if (a[i][j]>=0&&((lim2[i][j]>>a[i][j])&1))
			{
				cout<<0;
				return 0;
			}
			lim2[i][j]|=lim2[i+1][j]|lim2[i][j+1];
		}
	}
	fz0k(i,k) if ((s>>i)%2==0) v.push_back(i);
	if (v.size()==0)
	{
		cout<<1;
		return 0;
	}
//	ff(v,it) cerr<<*it<<endl;
	cout<<dfs(1,1,0);
	return 0;
}