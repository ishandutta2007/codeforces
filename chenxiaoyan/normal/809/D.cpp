/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
const int inf=0x3f3f3f3f;
mt19937 rng(20060617);
const int N=300000;
int n;
int l[N+1],r[N+1];
struct fhq_treap{
	int sz,root;
	struct node{unsigned key;int lson,rson,sz,v,lz;}nd[N+2];
	#define key(p) nd[p].key
	#define lson(p) nd[p].lson
	#define rson(p) nd[p].rson
	#define sz(p) nd[p].sz
	#define v(p) nd[p].v
	#define lz(p) nd[p].lz
	stack<int> rub;
	void recyc(int p){rub.push(p);}
	int nwnd(int v){
		int p;
		if(rub.size())p=rub.top(),rub.pop();
		else p=++sz;
		return nd[p]=node({rng(),0,0,1,v,0}),p;
	}
	void sprup(int p){sz(p)=sz(lson(p))+1+sz(rson(p));}
	void sprdwn(int p){
		if(lz(p)){
			v(lson(p))+=lz(p);v(rson(p))+=lz(p);
			lz(lson(p))+=lz(p);lz(rson(p))+=lz(p);
			lz(p)=0;
		}
	}
	int bld(int l=0,int r=n){
		int mid=l+r>>1,p=nwnd(mid?inf:0);
		if(l<=mid-1)lson(p)=bld(l,mid-1);
		if(mid+1<=r)rson(p)=bld(mid+1,r);
		return sprup(p),p;
	}
	void init(){
		nd[sz=0]=node({0,0,0,0,0,0});
		root=bld();
	}
	pair<int,int> split(int x,int p=-1){~p||(p=root);
		if(!x)return mp(0,p);
		pair<int,int> sp;
		sprdwn(p);
		if(x<=sz(lson(p)))return sp=split(x,lson(p)),lson(p)=sp.Y,sprup(p),mp(sp.X,p);
		return sp=split(x-sz(lson(p))-1,rson(p)),rson(p)=sp.X,sprup(p),mp(p,sp.Y);
	}
	int mrg(int p,int q){
		if(!p||!q)return p|q;
		sprdwn(p);sprdwn(q);
		if(key(p)<key(q))return rson(p)=mrg(rson(p),q),sprup(p),p;
		return lson(q)=mrg(p,lson(q)),sprup(q),q;
	}
	int lss(int v,int p=-1){~p||(p=root);
		if(!p)return 0;
		sprdwn(p);
		if(v(p)<v)return sz(lson(p))+1+lss(v,rson(p));
		return lss(v,lson(p));
	}
	void trs(int x){
		pair<int,int> sp=split(lss(l[x]));
		if(!sp.Y)return;
		pair<int,int> sp0=split(lss(r[x],sp.Y),sp.Y);
		if(sp0.Y){
			pair<int,int> sp1=split(1,sp0.Y);
			recyc(sp1.X);
			v(sp0.X)++;lz(sp0.X)++;
			root=mrg(mrg(mrg(sp.X,nwnd(l[x])),sp0.X),sp1.Y);
		}
		else{
			pair<int,int> sp1=split(sz(sp0.X)-1,sp0.X);
			recyc(sp1.Y);
			v(sp1.X)++;lz(sp1.X)++;
			root=mrg(mrg(sp.X,nwnd(l[x])),sp1.X);
		}
	}
	int at(int x,int p=-1){~p||(p=root);
		sprdwn(p);
		if(sz(lson(p))+1==x+1)return v(p);
		if(sz(lson(p))>=x+1)return at(x,lson(p));
		return at(x-sz(lson(p))-1,rson(p));
	}
	void dfs(int p=-1){~p||(p=root);
		if(!p)return;
		sprdwn(p);
		dfs(lson(p));
		cout<<v(p)<<" ";
		dfs(rson(p));
	}
}dp;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
	dp.init();
	for(int i=1;i<=n;i++)dp.trs(i)/*,dp.dfs(),puts("")*/;
//	for(int i=0;i<=n;i++)cout<<dp.at(i)<<" ";puts("");
	for(int i=n;;i--)if(dp.at(i)<inf)return cout<<i,0;
	return 0;
}