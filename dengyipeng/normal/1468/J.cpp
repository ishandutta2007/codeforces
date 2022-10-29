using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cassert>
#define N 200005
#define ll long long
int n,m,k;
struct edge{int u,v,w;} ed[N];
bool cmp1(edge a,edge b){
	return a.w<b.w;
}
bool cmp2(edge a,edge b){
	return max(a.w-k,0)<max(b.w-k,0);
}
int dsu[N];
int getdsu(int x){return x==dsu[x]?x:dsu[x]=getdsu(dsu[x]);}
ll ans;
void work1(int m1){
	for (int i=1;i<=n;++i)
		dsu[i]=i;
	for (int i=m1;i>=1;--i){
		int x=getdsu(ed[i].u),y=getdsu(ed[i].v);
		if (x!=y)
			dsu[x]=y;
	}
	for (int i=2;i<=n;++i)
		if (getdsu(1)!=getdsu(i))
			return;
	ans=min(ans,(ll)k-ed[m1].w);
}
void work2(){
	for (int i=1;i<=n;++i)
		dsu[i]=i;
	sort(ed+1,ed+m+1,cmp2);
	int c=n;
	ll res=0;
	for (int i=1;i<=m;++i){
		int x=getdsu(ed[i].u),y=getdsu(ed[i].v);
		if (x!=y){
			dsu[x]=y;
			c--;
			res+=max(ed[i].w-k,0);
			if (c==1){
				ans=min(ans,res);
				return;
			}
		}
	}	
	for (int i=1;i<=n;++i)
		dsu[i]=getdsu(dsu[i]);
}
int main(){
//	freopen("in.txt","r",stdin); 
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&n,&m,&k);
		for (int i=1;i<=m;++i)
			scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].w);
		sort(ed+1,ed+m+1,cmp1);
		int i=1;
		for (i=1;i<=m;++i)
			if (ed[i].w>k)
				break;
		ans=LLONG_MAX;
		work1(i-1);
		if (ans==LLONG_MAX)
			work2();
		else if (i<=m)
			ans=min(ans,(ll)ed[i].w-k);
		printf("%lld\n",ans);
	}
	return 0;
}