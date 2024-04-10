#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
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
long long n,m,len,s,t,i,j,dis[1005],dis2[1005],px[10005],py[10005],pz[10005],vis[1005],pre[1005],cd[10005];
vector<pair<pair<long long,long long>,long long> > bi[1005];
vector<pair<pair<long long,long long>,long long> > seq;
void print()
{
	long long i;
	puts("YES");
	fz1(i,m) printf("%I64d %I64d %I64d\n",px[i]-1,py[i]-1,max(pz[i],1ll));
	exit(0);
}
void dij1()
{
	memset(dis,15,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<pair<long long,long long> > pq;
	pq.push(make_pair(0,s));
	dis[s]=0;
	while (!pq.empty())
	{
		long long x=pq.top().second;pq.pop();if (vis[x]) continue;vis[x]=1;
		ff(bi[x],it)
		{
			long long y=it->first.first,z=dis[x]+max(1ll,it->first.second);
			if (dis[y]>z)
			{
				pre[y]=it->second;
				dis[y]=z;
				pq.push(make_pair(-z,y));
			}
		}
	}
}
int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&len,&s,&t);s++;t++;
	fz1(i,m)
	{
		scanf("%I64d%I64d%I64d",&px[i],&py[i],&pz[i]);px[i]++;py[i]++;if (!pz[i]) {pz[i]=1;cd[i]=1;}
		bi[px[i]].push_back(make_pair(make_pair(py[i],pz[i]),i));
		bi[py[i]].push_back(make_pair(make_pair(px[i],pz[i]),i));
	}
	dij1();
	if (dis[t]>len){puts("NO");return 0;}
	while (dis[t]<len)
	{
		long long tt=t;
		while (tt!=s)
		{
			if (cd[pre[tt]])
			{
				pz[pre[tt]]+=len-dis[t];
				break;
			}
			tt=(tt^px[pre[tt]]^py[pre[tt]]);
		}
		if (tt==s) {puts("NO");return 0;}
		fz1(i,n) bi[i].clear();
		fz1(i,m)
		{
			bi[px[i]].push_back(make_pair(make_pair(py[i],pz[i]),i));
			bi[py[i]].push_back(make_pair(make_pair(px[i],pz[i]),i));
		}
		dij1();
	}
	print();
	return 0;
}