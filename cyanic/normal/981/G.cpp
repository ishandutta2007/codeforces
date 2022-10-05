#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef bitset<10005> bits;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

namespace{
	const int mod=998244353;
	int fix(int x){
		return x>=mod?x-mod:x;
	}
	int mul(int x,int y){
		return (ll)x*y%mod;
	}
	void add(int &x,int y){
		x=(x+y>=mod?x+y-mod:x+y);
	}
}

const int N=200005;
struct node{
	int s,a,m;
}T[N<<2];
set<pii> p[N];
int n,Q,ty,l,r,c;

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
void Mul(int o,int x){
	T[o].s=mul(T[o].s,x);
	T[o].a=mul(T[o].a,x);
	T[o].m=mul(T[o].m,x);
}
void Add(int o,int l,int r,int x){
	add(T[o].s,mul(r-l+1,x));
	add(T[o].a,x);
}
void down(int o,int l,int r){
	if(T[o].m!=1){
		Mul(lc,T[o].m);
		Mul(rc,T[o].m);
		T[o].m=1;
	}
	if(T[o].a){
		Add(lc,l,mid,T[o].a);
		Add(rc,mid+1,r,T[o].a);
		T[o].a=0;
	}
}
void upd(int o,int l,int r,int x,int y,int ty,int z){
//	if(o==1) cout<<"#"<<x<<" "<<y<<" "<<ty<<" "<<z<<endl;
	if(l==x&&y==r){
		if(ty==1) Add(o,l,r,z);
		else Mul(o,z);
		return;
	}
	down(o,l,r);
	if(x<=mid) upd(lc,l,mid,x,min(y,mid),ty,z);
	if(mid<y) upd(rc,mid+1,r,max(mid+1,x),y,ty,z);
	T[o].s=fix(T[lc].s+T[rc].s);
}
int qry(int o,int l,int r,int x,int y){
//	cout<<o<<" "<<l<<" "<<r<<endl;
	if(l==x&&y==r) return T[o].s;
	down(o,l,r);
	if(y<=mid) return qry(lc,l,mid,x,y);
	if(mid<x) return qry(rc,mid+1,r,x,y);
	return fix(qry(lc,l,mid,x,mid)+qry(rc,mid+1,r,mid+1,y));
}

int main(){
	read(n),read(Q);
	rep(i,1,n<<2) T[i].m=1;
	while(Q--){
		read(ty);
		if(ty==1){
			read(l),read(r),read(c);
			auto L=p[c].lower_bound(mp(l,0));
			if(L!=p[c].begin()&&(--L)->se>=l-1);
			else L=p[c].lower_bound(mp(l,0));
			int mn=min(l,L!=p[c].end()?L->fi:N),mx=r;
			vector<pii> v;
			v.pb(mp(l-1,l-1));
			for(auto it=L;it!=p[c].end()&&it->fi<=r;it++){
				mx=max(mx,it->se);
				v.pb(*it);
			}
			v.pb(mp(r+1,r+1));
			auto it=L;
			while(it!=p[c].end()&&it->fi<=r){
				p[c].erase(it);
				it=p[c].lower_bound(mp(l,0));
			}
			int sz=v.size();
			for(int i=0;i+1<sz;i++){
				int L=max(l,v[i].se+1);
				int R=min(r,v[i+1].fi-1);
				if(L<=R) upd(1,1,n,L,R,1,1);
			}
			for(int i=1;i+1<sz;i++){
				int L=max(l,v[i].fi);
				int R=min(r,v[i].se);
				if(L<=R) upd(1,1,n,L,R,2,2);
			}
			p[c].insert(mp(mn,mx));
		}
		else{
			read(l),read(r);
			printf("%d\n",qry(1,1,n,l,r));
		}
	}
	return 0;
}