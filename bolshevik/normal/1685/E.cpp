#include<cstdio>
#include<utility>
#include<iostream>
using namespace std;
const int o=2e5+10;
int n,m,a[o],b[o],flg[o*4],p[o];long long s1,s2;pair<int,int> mn[o*4];
inline int d(int x,int y){if((x-=y)<0) x+=2*n+1;return x;}
void build(int id,int l,int r){
	if(l==r){mn[id]=make_pair(b[l],l);return;}
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
	mn[id]=min(mn[id<<1],mn[(id<<1)|1]);
}
inline void ad(int id,int val){mn[id].first+=val;flg[id]+=val;}
inline void pushdown(int id){ad(id<<1,flg[id]);ad((id<<1)|1,flg[id]);flg[id]=0;}
void modify(int id,int ql,int qr,int val,int l=0,int r=2*n+1){
	if(ql<=l&&r<=qr){ad(id,val);return;}
	pushdown(id);
	int md=l+r>>1;
	if(ql<=md) modify(id<<1,ql,qr,val,l,md);
	if(md<qr) modify((id<<1)|1,ql,qr,val,md+1,r);
	mn[id]=min(mn[id<<1],mn[(id<<1)|1]);
}
int query(int id,int pos,int l=0,int r=2*n+1){
	if(l==r) return mn[id].first;
	pushdown(id);
	int md=l+r>>1;
	return pos<=md?query(id<<1,pos,l,md):query((id<<1)|1,pos,md+1,r);
}
inline void ass(int val,int pos){
	if(val<=n)
		s1-=d(p[val+1],p[val])+d(p[val],p[(val+n-1)%(n+1)+1]),modify(1,p[val],2*n+1,1),p[val]=pos,
		s1+=d(p[val+1],p[val])+d(p[val],p[(val+n-1)%(n+1)+1]),modify(1,p[val],2*n+1,-1);
	else if(val>n+1)
		s2-=d(p[val],p[val-1])+d(p[(val-n)%(n+1)+n+1],p[val]),modify(1,p[val],2*n+1,-1),p[val]=pos,
		s2+=d(p[val],p[val-1])+d(p[(val-n)%(n+1)+n+1],p[val]),modify(1,p[val],2*n+1,1);
	else
		s1-=d(p[1],p[n+1])+d(p[n+1],p[n]),s2-=d(p[n+1],p[2*n+1])+d(p[n+2],p[n+1]),p[val]=pos,
		s1+=d(p[1],p[n+1])+d(p[n+1],p[n]),s2+=d(p[n+1],p[2*n+1])+d(p[n+2],p[n+1]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=2*n+1;++i) scanf("%d",&a[i]),b[p[a[i]]=i]=b[i-1]+(a[i]<=n?-1:a[i]>n+1?1:0);
	build(1,0,2*n+1);
	s1=d(p[1],p[n+1]);s2=d(p[n+1],p[2*n+1]);
	for(int i=1;i<=n;++i) s1+=d(p[i+1],p[i]);
	for(int i=n+1;i<=2*n;++i) s2+=d(p[i+1],p[i]);
	for(int u,v;m--;){
		scanf("%d%d",&u,&v);
		ass(a[u],v);ass(a[v],u);swap(a[u],a[v]);
		if(query(1,p[n+1])>mn[1].first) printf("%d\n",mn[1].second);
		else if(s1>2*n+1) printf("%d\n",p[n+1]%(2*n+1));
		else if(s2>2*n+1) printf("%d\n",p[n+1]-1);
		else printf("-1\n");
	}
	return 0;
}