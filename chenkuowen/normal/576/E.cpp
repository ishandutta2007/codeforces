#include<bits/stdc++.h>
using namespace std;
const int N=5+5e5;
struct TI{
	stack<pair<int*,int> > stk;
	void save(int& x){ stk.push(make_pair(&x,x)); }
	size_t size(){ return stk.size(); }
	void go_back(size_t sz){
		for(;stk.size()>sz;stk.pop())
			*stk.top().first=stk.top().second;
	}
}ti;
struct SP_DSF{
	vector<int> fa,r,val;
	SP_DSF(){}
	SP_DSF(int n){ fa=r=val=vector<int>(n); for(int i=0;i<n;++i) fa[i]=i; }
	int fs(int x){ return fa[x]!=x?fs(fa[x]):x; }
	int gk(int x){ return fa[x]!=x?val[x]^gk(fa[x]):0; }
	bool merge(int x,int y,int d){
		for(;x!=fa[x];x=fa[x]) d^=val[x];
		for(;y!=fa[y];y=fa[y]) d^=val[y];
		if(x==y) return d==0;
		if(r[x]<r[y]) swap(x,y);
		ti.save(fa[y]); ti.save(val[y]); ti.save(r[x]);
		fa[y]=x; val[y]=d; r[x]=max(r[x],r[y]+1);
		return true;
	}
}dsf[55];
struct E{ int x,y; }e[N];
struct K{ int e_id,c; };
struct K2{ int l,r; K op; };
K2 mp[N],a[N];
int col[N];
bool opera(K op){
	if(dsf[op.c].merge(e[op.e_id].x,e[op.e_id].y,1)){
		ti.save(col[op.e_id]);
		col[op.e_id]=op.c;
		return true;
	}else return false;
}
vector<K2> seg_dc(int l,int r,K2 a[],vector<K2> f){
	vector<K2> g; size_t sz=ti.size();
	for(auto x:f){
		if(x.r<l||r<x.l);
		else if(x.l<=l&&r<=x.r) assert(opera(x.op));
		else g.push_back(x);
	}
	swap(f,g);
	vector<K2> ex;
	if(l==r){
		assert(a[l].op.c!=0);
		if(opera(a[l].op)){
			ex.push_back(a[l]);
			puts("YES");
		}else{
			if(col[a[l].op.e_id]!=0){
				a[l].op.c=col[a[l].op.e_id];
				assert(opera(a[l].op));
				ex.push_back(a[l]);
			}
			puts("NO");
		}
	}else{
		int m=l+r>>1;
		vector<K2> exl=seg_dc(l,m,a,f);
		for(auto x:exl) ex.push_back(x),f.push_back(x);
		vector<K2> exr=seg_dc(m+1,r,a,f);
		for(auto x:exr) ex.push_back(x);
	}
	ti.go_back(sz);
	return ex;
}
int main(){
	int n,m,k,q; scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&e[i].x,&e[i].y);
		mp[i].op.c=0;
	}
	for(int i=1;i<=q;++i){
		K op; scanf("%d%d",&op.e_id,&op.c);
		if(mp[op.e_id].op.c!=0){
			K2 t=mp[op.e_id];
			t.r=i;
			a[t.l]=t;
		}
		mp[op.e_id]=(K2){i,(int)1e9,op};
	}
	for(int i=1;i<=m;++i){
		K2 t=mp[i];
		if(t.op.c!=0) a[t.l]=t;
	}
	for(int i=1;i<=k;++i) dsf[i]=SP_DSF(n+1);
	seg_dc(1,q,a,vector<K2>());
	return 0;
}