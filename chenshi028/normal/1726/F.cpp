#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;const long long inf=1e18;
int n,T,g[o],c[o],d[o],ls[o*60],rs[o*60],rt,cnt;long long ans=inf,v,sm,flg[o*60];
void ad(int&id,long long b){if(!id) id=++cnt;flg[id]=b;}
inline void pushdown(int id){if(flg[id]+1) ad(ls[id],flg[id]),ad(rs[id],flg[id]),flg[id]=-1;}
void modify(int&id,int ql,int qr,long long val,int l=0,int r=T-1){
	if(ql<=l&&r<=qr){ad(id,val);return;}
	if(!id) id=++cnt,flg[id]=-1;
	pushdown(id);
	int md=l+r>>1;
	if(ql<=md) modify(ls[id],ql,qr,val,l,md);
	if(md<qr) modify(rs[id],ql,qr,val,md+1,r);
}
long long query(int id,int pos,int l=0,int r=T-1){
	if(!id) return 0;
	if(flg[id]+1) return flg[id]-pos;
	int md=l+r>>1;
	if(pos<=md) return query(ls[id],pos,l,md);
	return query(rs[id],pos,md+1,r);
}
void dfs(int id,int l,int r){
	if(!id){ans=min(ans,0ll);return;}
	if(flg[id]+1){ans=min(ans,flg[id]-r);return;}
	int md=l+r>>1;
	dfs(ls[id],l,md);dfs(rs[id],md+1,r);
}
int main(){
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;++i) scanf("%d%d",&g[i],&c[i]);
	for(int i=1,sd=0;i<n;++i) scanf("%d",&d[i]),sm+=d[i],sd=(sd+d[i])%T,c[i+1]=(c[i+1]+sd)%T;
	for(int i=n;i;--i)
		if(g[i]>=c[i]) modify(rt,g[i]-c[i],T-1-c[i],query(rt,(T-c[i])%T)+T-c[i]);
		else v=query(rt,(T-c[i])%T),modify(rt,g[i]-c[i]+T,T-1,v+2*T-c[i]),modify(rt,0,T-1-c[i],v+T-c[i]);
	dfs(rt,0,T-1);
	printf("%lld",ans+sm);
	return 0;
}