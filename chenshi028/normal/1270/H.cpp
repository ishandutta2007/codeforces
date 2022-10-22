#include<cstdio>
#include<set>
#include<utility>
#include<algorithm>
using namespace std;
const int o=1e6+10,inf=1e9+10;
int n,m,a[o],b[o],X[o],c[o],d[o],e[o],tot,mn[o*4],cnt[o*4],flg[o*4];set<pair<int,int> > S;
inline void ad(int id,int val){mn[id]+=val;flg[id]+=val;}
inline void pushdown(int id){ad(id<<1,flg[id]);ad((id<<1)|1,flg[id]);flg[id]=0;}
inline void update(int id)
{mn[id]=min(mn[id<<1],mn[(id<<1)|1]);cnt[id]=cnt[id<<1]*(mn[id<<1]==mn[id])+cnt[(id<<1)|1]*(mn[(id<<1)|1]==mn[id]);}
void modify1(int id,int pos,int val,int l=0,int r=tot){
	if(l==r){cnt[id]+=val;return;}
	pushdown(id);
	int md=l+r>>1;
	if(pos<=md) modify1(id<<1,pos,val,l,md);
	else modify1((id<<1)|1,pos,val,md+1,r);
	update(id);
}
void modify2(int id,int ql,int qr,int val,int l=0,int r=tot){
	if(ql<=l&&r<=qr){ad(id,val);return;}
	pushdown(id);
	int md=l+r>>1;
	if(ql<=md) modify2(id<<1,ql,qr,val,l,md);
	if(md<qr) modify2((id<<1)|1,ql,qr,val,md+1,r);
	update(id);
}
inline void ins(int x,int y,int coef){
	int a=(*--S.lower_bound(make_pair(x,y))).second,b=(*S.upper_bound(make_pair(x,y))).second;
	if(a>b) modify2(1,b,a-1,-coef);
	if(a>y) modify2(1,y,a-1,coef);
	if(y>b) modify2(1,b,y-1,coef);
	modify1(1,y,coef);
	if(coef>0) S.insert(make_pair(x,y));
	else S.erase(make_pair(x,y));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]),a[i]=i,e[++tot]=b[i];
	for(int i=1;i<=m;++i) scanf("%d%d",&X[i],&d[i]),c[i]=X[i],e[++tot]=d[i];
	sort(e+1,e+tot+1);
	for(int i=1;i<=n;++i) b[i]=lower_bound(e+1,e+tot+1,b[i])-e;
	for(int i=1;i<=m;++i) d[i]=lower_bound(e+1,e+tot+1,d[i])-e;
	S.insert(make_pair(0,tot+1));S.insert(make_pair(inf,0));
	for(int i=1;i<=n;++i) ins(a[i],b[i],1);
	for(int i=1;i<=m;++i,printf("%d\n",cnt[1])) ins(a[X[i]],b[X[i]],-1),ins(a[X[i]]=c[i],b[X[i]]=d[i],1);
	return 0;
}