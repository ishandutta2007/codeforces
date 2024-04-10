#include<cstdio>
using namespace std;
inline long long Abs(long long x){return x>0?x:-x;}
inline long long Max(long long a,long long b){return a>b?a:b;}
const int o=2e5+10;
int n,q,h[o],cnt=1,dfn[o],ed[o];long long w,z,val[o],ans;
struct Edge{int v,p;long long w;}e[o];
inline void ad(int U,int V,long long W){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].w=W;}
struct segmenttree{int l,r;long long rb,lb,mx,f1,f2,f3,f4;}nod[o*5];
#define ls id<<1
#define rs (id<<1)|1
inline void update(int id){
	nod[id].rb=nod[ls].rb+Max(0,nod[rs].rb-nod[ls].lb);
	nod[id].lb=nod[rs].lb+Max(0,nod[ls].lb-nod[rs].rb);
	nod[id].mx=Max(Max(nod[ls].mx,nod[rs].mx),Max(nod[ls].f1+nod[rs].f4,nod[ls].f2+nod[rs].f3));
	nod[id].f1=Max(nod[rs].f1,Max(nod[ls].f1-nod[rs].rb+nod[rs].lb,nod[ls].f2+nod[rs].rb+nod[rs].lb));
	nod[id].f2=Max(nod[rs].f2,nod[ls].f2+nod[rs].rb-nod[rs].lb);
	nod[id].f3=Max(nod[ls].f3,Max(nod[rs].f3+nod[ls].rb-nod[ls].lb,nod[rs].f4+nod[ls].rb+nod[ls].lb));
	nod[id].f4=Max(nod[ls].f4,nod[rs].f4+nod[ls].lb-nod[ls].rb);
}
void build(int id,int l,int r){
	nod[id].l=l;nod[id].r=r;
	if(l==r){
		nod[id].mx=nod[id].f1=nod[id].f3=Abs(val[l]);
		if(val[l]>0) nod[id].lb=nod[id].f4=val[l];else nod[id].rb=nod[id].f2=-val[l];
		return;
	}
	int md=l+r>>1;
	build(ls,l,md);build(rs,md+1,r);
	update(id);
}
void modify(int id,int pos,long long vl){
	if(nod[id].l==nod[id].r){
		nod[id].mx=nod[id].f1=nod[id].f3=Abs(vl);
		if(vl>0) nod[id].lb=nod[id].f4=vl,nod[id].rb=nod[id].f2=0;
		else nod[id].rb=nod[id].f2=-vl,nod[id].lb=nod[id].f4=0;
		return;
	}
	if(pos<=(nod[id].l+nod[id].r>>1)) modify(ls,pos,vl);
	else modify(rs,pos,vl);
	update(id);
}
void dfs(int nw,int fa){
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa)
		val[dfn[i>>1]=++cnt]=e[i].w,dfs(e[i].v,nw),val[ed[i>>1]=++cnt]=-e[i].w;
}
int main(){
	scanf("%d%d%lld",&n,&q,&w);
	for(int i=1,j,k;i<n;++i) scanf("%d%d%lld",&j,&k,&z),ad(j,k,z),ad(k,j,z);
	dfs(2,cnt=0);build(1,1,2*n-2);
	for(int x;q--;printf("%lld\n",ans=nod[1].mx))
		scanf("%d%lld",&x,&z),x=(x+ans)%(n-1)+1,z=(z+ans)%w,modify(1,dfn[x],z),modify(1,ed[x],-z);
	return 0;
}