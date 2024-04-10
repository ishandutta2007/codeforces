#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int o=1e6;
int n,ans,X[o],Y[o],C[o],x[o],y[o],c[o],cx,cy,p[o],z;map<int,int> mx,my;vector<int> vec[o];
struct segmenttree{
	int mx[o],mn[o],flg[o];
	void build(int id,int l,int r){
		mx[id]=mn[id]=flg[id]=0;
		if(l==r) return;
		int md=l+r>>1;
		build(id<<1,l,md);build((id<<1)|1,md+1,r);
	}
	inline void ad(int id,int val){mx[id]+=val;mn[id]+=val;flg[id]+=val;}
	inline void pushdown(int id){ad(id<<1,flg[id]);ad((id<<1)|1,flg[id]);flg[id]=0;}
	void modify(int id,int ql,int qr,int val,int l=1,int r=z){
		if(ql<=l&&r<=qr){ad(id,val);return;}
		pushdown(id);
		int md=l+r>>1;
		if(ql<=md) modify(id<<1,ql,qr,val,l,md);
		if(md<qr) modify((id<<1)|1,ql,qr,val,md+1,r);
		mx[id]=max(mx[id<<1],mx[(id<<1)|1]);mn[id]=min(mn[id<<1],mn[(id<<1)|1]);
	}
}T1,T2;
int query(int id,int l=1,int r=z){
	if(T1.mx[id]<=T2.mn[id]) return T1.mx[id];
	if(T2.mx[id]<=T1.mn[id]) return T2.mx[id];
	T1.pushdown(id);T2.pushdown(id);
	int md=l+r>>1;
	return max(query(id<<1,l,md),query((id<<1)|1,md+1,r));
}
inline void Slv(int coef){
	for(int i=1;i<=cx;++i) vec[i].clear();
	for(int i=1;i<=n;++i) vec[coef<0?cx-x[i]+1:x[i]].push_back(i);
	T1.build(1,1,z=cy);T2.build(1,1,cy);
	for(int i=1,t=n/3;i<=cx;++i){
		for(int j=vec[i].size();j--;) t-=(c[vec[i][j]]==3); 
		if(t<=ans) break;
		for(int j=vec[i].size();j--;)
			if(c[vec[i][j]]==1&&y[vec[i][j]]>1) T1.modify(1,1,y[vec[i][j]]-1,1);
			else if(c[vec[i][j]]==2) T2.modify(1,y[vec[i][j]],cy,1);
		ans=max(ans,min(t,query(1)));
	}
}
inline void sLv(){
	for(int i=1;i<=cx;++i) vec[i].clear();
	for(int i=1;i<=n;++i) vec[x[i]].push_back(i);
	T1.build(1,1,z=cx);T2.build(1,1,cx);
	for(int i=1,t=n/3,v1=0,v2=0;i<=cx;++i,v1=v2=0){
		for(int j=vec[i].size();j--;) t-=(c[vec[i][j]]==3);
		if(t<=ans) break;
		for(int j=vec[i].size();j--;) v1+=(c[vec[i][j]]==1),v2+=(c[vec[i][j]]==2);
		if(i>1&&v1) T1.modify(1,1,i-1,v1);
		if(v2) T2.modify(1,i,cx,v2);
		ans=max(ans,min(t,query(1)));
	}
}
inline void slv(){
	for(int i=1;i<=n;++i) x[i]=X[i],y[i]=Y[i],c[i]=p[C[i]];
	Slv(1);Slv(-1);sLv();swap(cx,cy);
	for(int i=1;i<=n;++i) swap(x[i],y[i]);
	Slv(1);Slv(-1);sLv();swap(cx,cy);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d%d",&X[i],&Y[i],&C[i]),x[i]=X[i],y[i]=Y[i];
	sort(x+1,x+n+1);sort(y+1,y+n+1);
	for(int i=1;i<=n;++i){
		if(i==1||x[i]-x[i-1]) mx[x[i]]=++cx;
		if(i==1||y[i]-y[i-1]) my[y[i]]=++cy;
	}
	for(int i=1;i<=n;++i) X[i]=mx[X[i]],Y[i]=my[Y[i]];
	p[1]=1;p[2]=2;p[3]=3;slv();
	p[1]=1;p[2]=3;p[3]=2;slv();
	p[1]=2;p[2]=1;p[3]=3;slv();
	p[1]=2;p[2]=3;p[3]=1;slv();
	p[1]=3;p[2]=1;p[3]=2;slv();
	p[1]=3;p[2]=2;p[3]=1;slv();
	printf("%d",ans*3);
	return 0;
}