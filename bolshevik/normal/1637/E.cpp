#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
const int o=3e5+10;
int T,n,m,a[o],b[o],cnt,Cnt[o],tp,z;pair<int,long long> p[o],st[o];long long ans;vector<int> ask[o*4],ban[o];
void build(int id,int l,int r){
	ask[id].clear();
	if(l==r) return;
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
}
void modify(int id,int ql,int qr,int val,int l=1,int r=cnt){
	if(ql<=l&&r<=qr){ask[id].push_back(val);return;}
	int md=l+r>>1;
	if(ql<=md) modify(id<<1,ql,qr,val,l,md);
	if(md<qr) modify((id<<1)|1,ql,qr,val,md+1,r);
}
inline long long calc(pair<int,long long> pr){return (pr.first+Cnt[z])*(pr.second/pr.first+b[z]);}
void dfs(int id,int l,int r){
	if(!ask[id].empty()){
		for(int i=l;i<=r;++i) p[i]=make_pair(Cnt[i],Cnt[i]*1ll*b[i]);
		sort(p+l,p+r+1);st[tp=1]=p[l];
		for(int i=l+1;i<=r;st[++tp]=p[i++]){
			for(;tp&&st[tp].second<=p[i].second;--tp);
			for(;tp>1&&(st[tp-1].second-st[tp].second)*(__int128)(p[i].first-st[tp].first)>=
			(st[tp].second-p[i].second)*(__int128)(st[tp].first-st[tp-1].first);--tp);
		}
		for(int i=ask[id].size(),l,r,md;i--;ans=max(ans,calc(st[l]))) for(l=1,r=tp,z=ask[id][i];l<r;){
			md=l+r>>1;
			if(calc(st[md])>calc(st[md+1])) r=md;
			else l=md+1;
		}
	}
	if(l==r) return;
	int md=l+r>>1;
	dfs(id<<1,l,md);dfs((id<<1)|1,md+1,r);
}
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=0){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),b[i]=a[i];
		sort(b+1,b+n+1);cnt=unique(b+1,b+n+1)-b-1;
		build(1,1,cnt);
		for(int i=1;i<=cnt;++i) ban[i].clear(),ban[i].push_back(Cnt[i]=0),ban[i].push_back(i);
		for(int i=1;i<=n;++i) ++Cnt[lower_bound(b+1,b+cnt+1,a[i])-b];
		for(int i=1,x,y;i<=m;++i){
			scanf("%d%d",&x,&y);
			if(x>y) swap(x,y);
			ban[lower_bound(b+1,b+cnt+1,y)-b].push_back(lower_bound(b+1,b+cnt+1,x)-b);
		}
		for(int i=1,j;i<=cnt;++i) for(sort(ban[i].begin(),ban[i].end()),j=ban[i].size();--j;)
			if(ban[i][j-1]+1<ban[i][j]) modify(1,ban[i][j-1]+1,ban[i][j]-1,i);
		dfs(1,1,cnt);
	}
	return 0;
}