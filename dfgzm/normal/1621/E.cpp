#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define mid (l+r>>1)
using namespace std;
const int maxn=400005,maxt=maxn<<2;
int T,n,m,tot;
int a[maxn],val[maxn];
long long sum[maxn];
pair<long long,int>num[maxn],rec[maxn];
vector<int>v[maxn];
vector< pair<long long,int> >w[maxn];
map<pair<long long,int>,int>mp;
int mn[maxt],lazy[maxt];
inline int cmp(pair<long long,int>a,pair<long long,int>b){
	return 1ll*a.first*b.second<1ll*b.first*a.second;
}
long long gcd(long long a,long long b){
	return b==0? a:gcd(b,a%b);
}
inline void pushup(int now){
	mn[now]=min(mn[lc(now)],mn[rc(now)]);
}
inline void getlazy(int now,int v){
	lazy[now]+=v,mn[now]+=v;
}
inline void pushdown(int now){
	if(lazy[now])
		getlazy(lc(now),lazy[now]),getlazy(rc(now),lazy[now]),lazy[now]=0;
}
void build(int l,int r,int now){
	mn[now]=lazy[now]=0;
	if(l==r)
		return ;
	build(l,mid,lc(now)),build(mid+1,r,rc(now));
}
void update(int l,int r,int now,int L,int R,int v){
	if(L<=l&&r<=R){
		getlazy(now,v);
		return ;
	}
	pushdown(now);
	if(L<=mid)
		update(l,mid,lc(now),L,R,v);
	if(mid<R)
		update(mid+1,r,rc(now),L,R,v);
	pushup(now);
}
int main(){
	scanf("%d",&T);
	while(T--){
		tot=0,mp.clear(),scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),num[++tot]=make_pair(a[i],1);
		long long g;
		for(int i=1,k;i<=m;i++){
			scanf("%d",&k),v[i].resize(k),w[i].resize(k);
			for(int j=0;j<k;j++)
				scanf("%d",&v[i][j]),sum[i]+=v[i][j];
			g=gcd(sum[i],1ll*k),rec[i]=make_pair(sum[i]/g,k/g),num[++tot]=rec[i];
			for(int j=0;j<k;j++)
				g=gcd(sum[i]-v[i][j],1ll*max(k-1,1)),w[i][j]=make_pair((sum[i]-v[i][j])/g,max(k-1,1)/g),num[++tot]=w[i][j];
		}
		sort(num+1,num+1+tot,cmp);
		tot=unique(num+1,num+1+tot)-num-1;
		for(int i=1;i<=tot;i++)
			mp[num[i]]=i;
		build(1,tot,1);
		for(int i=1;i<=n;i++)
			update(1,tot,1,1,mp[make_pair(a[i],1)],1);
		for(int i=1;i<=m;i++)
			val[i]=mp[rec[i]],update(1,tot,1,1,val[i],-1);
		for(int i=1;i<=m;i++)
			for(int j=0;j<v[i].size();j++){
				int p=mp[w[i][j]];
				update(1,tot,1,1,val[i],1),update(1,tot,1,1,p,-1),putchar(mn[1]<0? '0':'1'),update(1,tot,1,1,val[i],-1),update(1,tot,1,1,p,1);
			}
		puts("");
		for(int i=1;i<=m;i++)
			sum[i]=0,v[i].clear(),w[i].clear();
	}
	return 0;
}