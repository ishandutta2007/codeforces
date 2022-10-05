#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
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

const int N=100005;
int T[N<<2],ans[N],n,m,Q,x,y;
vector<pii> q[N];
vi v[N];

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
void down(int o){
	T[lc]=min(T[lc],T[o]);
	T[rc]=min(T[rc],T[o]);
}
void up(int o){
	T[o]=max(T[lc],T[rc]);
}
void build(int o,int l,int r){
	T[o]=1e9;
	if(l==r) return;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void upd(int o,int l,int r,int x,int y,int z){
	if(l==x&&y==r){
		T[o]=min(T[o],z);
		return;
	}
	down(o);
	if(x<=mid) upd(lc,l,mid,x,min(y,mid),z);
	if(mid<y) upd(rc,mid+1,r,max(mid+1,x),y,z);
	up(o);
}
int ask(int o,int l,int r,int p,int lim){
	if(T[o]<=lim) return -1;
	if(p<=l){
		for(;l<r;){
			if(T[lc]<=lim) l=mid+1,o=rc;
			else r=mid,o=lc;
		}
		return l;
	}
	int tmp=-1;
	if(p<=mid) tmp=ask(lc,l,mid,p,lim);
	if(tmp!=-1) return tmp;
	return ask(rc,mid+1,r,p,lim);
}

int main(){
	read(n),n++,read(m);
	rep(i,1,m){
		read(x),read(y);
		if(x<y) v[x].pb(y);
	}
	read(Q);
	rep(i,1,Q){
		read(x),read(y);
		q[x].pb(mp(y,i));
	}
	build(1,1,n);
	per(i,n-1,1){
		for(auto x:v[i]) upd(1,1,n,i,x-1,x);
		for(auto x:q[i]) ans[x.se]=ask(1,1,n,i,x.fi);
	}
	rep(i,1,Q) printf("%d\n",ans[i]);
	return 0;
}