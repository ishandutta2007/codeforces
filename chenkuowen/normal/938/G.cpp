#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
struct TI{
	stack<pair<int*,int> > stk;
	void save(int& x){ stk.push(make_pair(&x,x)); }
	size_t size(){ return stk.size(); }
	void go_back(size_t sz){ 
		for(;stk.size()>sz;stk.pop()) 
			*stk.top().first=stk.top().second;
	}
}ti;
struct BL{
	int a[30];
	BL(){memset(a,0,sizeof(a)); }
	inline bool insert(int x){
		if(x==0) return false;
		for(int i=29;i>=0;--i)
			if((x>>i)&1){
				if(a[i]) x^=a[i];
				else{
					ti.save(a[i]);
					a[i]=x;
					return true;
				}
			}
		return false;
	}
	inline int query_min(int x){
		for(int i=29;i>=0;--i)
			if((x>>i)&1) x^=a[i];
		return x;
	}
}bl;
struct SP_DSF{
	vector<int> fa,r,val;
	SP_DSF(){}
	SP_DSF(int n){ fa=r=val=vector<int>(n); for(int i=0;i<n;++i) fa[i]=i; }
	int fs(int x){ return fa[x]!=x?fs(fa[x]):x; }
	int gk(int x){ return fa[x]!=x?val[x]^gk(fa[x]):0; }
	int merge(int x,int y,int d){
		for(;x!=fa[x];x=fa[x]) d^=val[x]; 
		for(;y!=fa[y];y=fa[y]) d^=val[y];
		if(x==y) return d;
		if(r[x]<r[y]) swap(x,y);
		ti.save(fa[y]); ti.save(val[y]); ti.save(r[x]);
		fa[y]=x; val[y]=d; r[x]=max(r[x],r[y]+1);
		return 0;
	}
}dsf;
struct K{ int x,y,d; };
struct K2{ int l,r; K op; };
K a[N];
int ans[N];
void seg_dc(vector<K2> f,int l,int r,K a[],int ans[]){
	vector<K2> g; size_t sz=ti.size();
	for(auto x:f){
		if(x.r<l||r<x.l);
		else if(x.l<=l&&r<=x.r) bl.insert(dsf.merge(x.op.x,x.op.y,x.op.d));
		else g.push_back(x);
	}
	swap(f,g);
	if(l==r){
		assert(dsf.fs(a[l].x)==dsf.fs(a[l].y));
		ans[l]=bl.query_min(dsf.gk(a[l].x)^dsf.gk(a[l].y));
		ti.go_back(sz);
		return;
	}
	int m=l+r>>1; 
	seg_dc(f,l,m,a,ans);
	seg_dc(f,m+1,r,a,ans);
	ti.go_back(sz);
}
map<int,K2> mp[N];
int main(){
	int n,m; scanf("%d%d",&n,&m);
	dsf=SP_DSF(n+1);
	for(int i=1;i<=m;++i){
		int x,y,d; scanf("%d%d%d",&x,&y,&d);
		if(x>y) swap(x,y);
		mp[x][y]=(K2){1,(int)1e9,(K){x,y,d}};
	}
	int q; scanf("%d",&q);
	int top=0;
	vector<K2> f;
	while(q--){
		int op,x,y; scanf("%d%d%d",&op,&x,&y);
		if(x>y) swap(x,y);
		if(op==1){
			int d; scanf("%d",&d);
			mp[x][y]=(K2){top+1,(int)1e9,(K){x,y,d}};
		}else if(op==2){
			K2 t=mp[x][y]; t.r=top;
			f.push_back(t);
			mp[x].erase(y);
		}else{
			a[++top]=(K){x,y};
		}
	}
	for(int x=1;x<=n;++x)
		for(auto y:mp[x]) f.push_back(y.second);
//	for(auto x:f) printf("<%d %d(%d %d %d)>",x.l,x.r,x.op.x,x.op.y,x.op.d);
	seg_dc(f,1,top,a,ans);
	for(int i=1;i<=top;++i) printf("%d\n",ans[i]);
	return 0;
}