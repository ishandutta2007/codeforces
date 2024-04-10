#include<cstdio>
using namespace std;
const int o=3e6+10;
int n,c[o],h[o],cnt,mx[o],ls[o],rs[o],rt[o];long long s[o],ans[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
inline void update(int id){
	if(mx[ls[id]]<mx[rs[id]]) mx[id]=mx[rs[id]],s[id]=s[rs[id]];
	else if(mx[ls[id]]>mx[rs[id]]) mx[id]=mx[ls[id]],s[id]=s[ls[id]];
	else mx[id]=mx[ls[id]],s[id]=s[ls[id]]+s[rs[id]];
}
void merge(int&id1,int id2,int l=1,int r=n){
	if(!id1||!id2){id1=id1|id2;return;}
	if(l==r){mx[id1]+=mx[id2];return;}
	int md=l+r>>1;
	merge(ls[id1],ls[id2],l,md);merge(rs[id1],rs[id2],md+1,r);
	update(id1);
}
void modify(int&id,int pos,int l=1,int r=n){
	if(!id) id=++cnt;
	if(l==r){++mx[id];s[id]=l;return;}
	int md=l+r>>1;
	if(pos<=md) modify(ls[id],pos,l,md);
	else modify(rs[id],pos,md+1,r);
	update(id);
}
void dfs(int nw,int fa){
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa)
		dfs(e[i].v,nw),merge(rt[nw],rt[e[i].v]);
	modify(rt[nw],c[nw]);ans[nw]=s[rt[nw]];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&c[i]);
	for(int i=1,j,k;i<n;++i) scanf("%d%d",&j,&k),ad(j,k),ad(k,j);
	dfs(1,cnt=0);
	for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
	return 0;
}