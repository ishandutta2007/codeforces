#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define qwq(x) cerr<<"# "<<#x<<" = "<<x<<endl;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define lc (o<<1)
#define rc (o<<1|1)
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

const int N=150005;
int tag[N<<2],a[N],n,m,p;
vector<pii> T[N<<2];

vector<pii> merge(vector<pii> a,vector<pii> b){
	vector<pii> res=a;
	for(auto x:b){
		int k=-1;
		REP(i,res.size())
			if(res[i].fi==x.fi)k=i;
		if(k>=0){
			res[k].se+=x.se;
			continue;
		}
		res.pb(x);
		if(res.size()<p) continue;
		k=N;
		REP(i,p) k=min(k,res[i].se);
		REP(i,p) res[i].se-=k;
		k=0;
		REP(i,p) if(res[i].se)res[k++]=res[i];
		res.resize(k);
	}
	return res;
}

void app(int o,int l,int r,int x){
	T[o].clear();
	T[o].pb(mp(x,r-l+1));
	tag[o]=x;
}

void down(int o,int l,int r){
	if(tag[o]){
		app(lc,l,mid,tag[o]);
		app(rc,mid+1,r,tag[o]);
		tag[o]=0;
	}
}

void build(int o,int l,int r){
	if(l==r){
		T[o].pb(mp(a[l],1));
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	T[o]=merge(T[lc],T[rc]);
}

void upd(int o,int l,int r,int x,int y,int z){
	if(l==x&&y==r){
		app(o,l,r,z);
		return;
	}
	down(o,l,r);
	if(x<=mid) upd(lc,l,mid,x,min(y,mid),z);
	if(mid<y) upd(rc,mid+1,r,max(mid+1,x),y,z);
	T[o]=merge(T[lc],T[rc]);
}

vector<pii> qry(int o,int l,int r,int x,int y){
	if(l==x&&y==r) return T[o];
	down(o,l,r);
	if(y<=mid) return qry(lc,l,mid,x,y);
	if(mid<x) return qry(rc,mid+1,r,x,y);
	return merge(qry(lc,l,mid,x,mid),qry(rc,mid+1,r,mid+1,y));
}

int main(){
	read(n),read(m);
	read(p),p=100/p+1;
	rep(i,1,n)read(a[i]);
	build(1,1,n);
	while(m--){
		int op,l,r,x;
		read(op),read(l),read(r);
		if(op==1){
			read(x);
			upd(1,1,n,l,r,x);
		}
		else{
			vector<pii> res=qry(1,1,n,l,r);
			printf("%d ",res.size());
			for(auto x:res)
				printf("%d ",x.fi);
			puts("");
		}
	}
	return 0;
}