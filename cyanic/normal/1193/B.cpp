#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define ct __builtin_popcount
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
mt19937 ran(time(NULL));
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef double ld;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=100005;
struct node{
	ll mn,mx,add;
	int lc,rc;
}T[N<<7];
int fa[N],rt[N],d[N],w[N];
int n,m,D,a,b,c,sz;

#define mid ((l+r)>>1)
inline void up(const int &o){
	T[o].mn=T[T[o].lc].mn,T[o].mx=T[T[o].rc].mx;
}
inline void down(const int &o){
	if(T[o].add){
		T[++sz]=T[T[o].lc];
		T[sz].mn+=T[o].add;
		T[sz].mx+=T[o].add;
		T[sz].add+=T[o].add;
		T[o].lc=sz;
		T[++sz]=T[T[o].rc];
		T[sz].mn+=T[o].add;
		T[sz].mx+=T[o].add;
		T[sz].add+=T[o].add;
		T[o].rc=sz;
		T[o].add=0;
	}
	if(T[o].mn>T[T[o].lc].mn){
		T[++sz]=T[T[o].lc];
		T[sz].mn=T[o].mn;
		T[sz].mx=max(T[sz].mn,T[sz].mx);
		T[o].lc=sz;
	}
	if(T[o].mn>T[T[o].rc].mn){
		T[++sz]=T[T[o].rc];
		T[sz].mn=T[o].mn;
		T[sz].mx=max(T[sz].mn,T[sz].mx);
		T[o].rc=sz;
	}
}
int merge(int x,int y,int l,int r){
	if(!x||!y)return x|y;
	if(!T[y].lc&&!T[y].rc)swap(x,y);
//	cerr<<"@"<<l<<" "<<r<<endl;
	if(!T[x].lc&&!T[x].rc){
		T[++sz]=T[y];
//		assert(T[x].mn==T[x].mx);
//		cerr<<"val: "<<T[x].mn<<endl;
		T[sz].mn+=T[x].mn;
		T[sz].mx+=T[x].mn;
		T[sz].add+=T[x].mn;
		return sz;
	}
	down(x),down(y);
	int o=++sz;
	T[o].mn=T[x].mn+T[y].mn;
	T[o].mx=T[x].mx+T[y].mx;
	T[o].lc=merge(T[x].lc,T[y].lc,l,mid);
	T[o].rc=merge(T[x].rc,T[y].rc,mid+1,r);
	return o;
}
void upd(int &o,int l,int r,int x,ll y){
	if(T[o].mn>=y)return;
	T[++sz]=T[o],o=sz;
	if(x<=l&&T[o].mx<=y){
		T[o].mn=T[o].mx=y,T[o].add=0;
		return;
	}
	down(o);
	if(x<=mid)upd(T[o].lc,l,mid,x,y);
	upd(T[o].rc,mid+1,r,x,y);
	up(o);
}
ll qry(int o,int l,int r,int x){
	if(!o||l==r)return T[o].mn;down(o);
	return x<=mid?qry(T[o].lc,l,mid,x):qry(T[o].rc,mid+1,r,x);
}

int main(){
	read(n),read(m),read(D);
	rep(i,2,n)read(fa[i]);
	rep(i,1,m){
		read(a),read(b),read(c);
		d[a]=b,w[a]=c;
	}
	per(i,n,1){
		if(d[i]){
			ll dp=qry(rt[i],1,D,d[i])+w[i];
			//cerr<<i<<" "<<d[i]<<" "<<dp<<endl;
			upd(rt[i],1,D,d[i],dp);
			//cerr<<"@"<<qry(rt[i],1,D,D-1)<<endl;
		}
		rt[fa[i]]=merge(rt[fa[i]],rt[i],1,D);
		//cerr<<"#"<<qry(rt[fa[i]],1,D,D)<<endl;
	}
	cout<<qry(rt[1],1,D,D)<<endl;
	return 0;
}