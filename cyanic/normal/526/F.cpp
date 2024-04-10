#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

//mx - mn + l = r

const int N=300005;
namespace{
	#define lc (o<<1)
	#define rc (o<<1|1)
	#define mid ((l+r)>>1)
	int tag[N<<2]; pii T[N<<2];
	pii operator + (pii a,pii b){
		if(a.fi==b.fi)return mp(a.fi,a.se+b.se);
		return a.fi<b.fi?a:b;
	}
	void down(int o){
		if(tag[o]){
			T[lc].fi+=tag[o],tag[lc]+=tag[o];
			T[rc].fi+=tag[o],tag[rc]+=tag[o];
			tag[o]=0;
		}
	}
	void upd(int o,int l,int r,int x,int y,int z){
		if(l==x&&y==r){
			T[o].fi+=z,tag[o]+=z;
			return;
		}
		down(o);
		if(x<=mid)upd(lc,l,mid,x,min(y,mid),z);
		if(mid<y)upd(rc,mid+1,r,max(mid+1,x),y,z);
		T[o]=T[lc]+T[rc];
	}
	pii qry(int o,int l,int r,int x,int y){
		if(l==x&&y==r) return T[o];
		if(y<=mid) return qry(lc,l,mid,x,y);
		if(mid<x) return qry(rc,mid+1,r,x,y);
		return qry(lc,l,mid,x,mid)+qry(rc,mid+1,r,mid+1,y);
	}
	void build(int o,int l,int r){
		if(l==r){
			T[o]=mp(l,1);
			return;
		}
		build(lc,l,mid),build(rc,mid+1,r);
		T[o]=T[lc]+T[rc];
	}
}

int p[N],mx[N],mn[N];
int Mx,Mn,n,a,b;
ll ans;

int main(){
	read(n);
	rep(i,1,n){
		read(a),read(b);
		p[a]=b;
	}
	build(1,1,n);
	rep(i,1,n){
		while(Mx&&p[i]>p[mx[Mx]]){
			upd(1,1,n,mx[Mx-1]+1,mx[Mx],p[i]-p[mx[Mx]]);
			Mx--;
		}
		upd(1,1,n,i,i,p[i]),mx[++Mx]=i;
		while(Mn&&p[i]<p[mn[Mn]]){
			upd(1,1,n,mn[Mn-1]+1,mn[Mn],p[mn[Mn]]-p[i]);
			Mn--;
		}
		upd(1,1,n,i,i,-p[i]),mn[++Mn]=i;
		pii res=qry(1,1,n,1,i);
		if(res.fi==i)ans+=res.se;
	}
	cout<<ans<<endl;
	return 0;
}