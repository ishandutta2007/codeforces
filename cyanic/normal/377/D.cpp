#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define clr(x) memset(x,0,sizeof x)
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=300005,M=N-5;
int tag[N<<2],l[N],v[N],r[N],n,ans,ansL,ansR;
vector<pii> c[N];
pii mx[N<<2];
vi q[N],res;

void build(int o,int l,int r){
	if(l==r){
		mx[o]=mp(0,l);
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	mx[o]=max(mx[lc],mx[rc]);
}
void app(int o,int x){
	mx[o].fi+=x,tag[o]+=x;
}
void down(int o){
	if(!tag[o]) return;
	app(lc,tag[o]),app(rc,tag[o]);
	tag[o]=0;
}
void upd(int o,int l,int r,int x,int y,int z){
	if(l==x&&y==r) return app(o,z);
	down(o);
	if(x<=mid) upd(lc,l,mid,x,min(y,mid),z);
	if(mid<y) upd(rc,mid+1,r,max(mid+1,x),y,z);
	mx[o]=max(mx[lc],mx[rc]);
}
pii qry(int o,int l,int r,int x,int y){
	if(l==x&&y==r) return mx[o];
	down(o);
	if(y<=mid) return qry(lc,l,mid,x,y);
	if(mid<x) return qry(rc,mid+1,r,x,y);
	return max(qry(lc,l,mid,x,mid),qry(rc,mid+1,r,mid+1,y));
}


int main(){
	read(n);
	rep(i,1,n){
		read(l[i]),read(v[i]),read(r[i]);
		q[v[i]].pb(r[i]);
		c[l[i]].pb(mp(v[i],r[i]));
	}
	build(1,1,M);
	per(i,M,1){
		for(auto x:q[i]){
			upd(1,1,M,i,x,1);
			pii ret=qry(1,1,M,i,x);
			if(ret.fi>ans){
				ans=ret.fi;
				ansL=i,ansR=ret.se;
			}
		}
		for(auto x:c[i]){
			upd(1,1,M,x.fi,x.se,-1);
		}
	}
	printf("%d\n",ans);
	rep(i,1,n){
		if(l[i]<=ansL&&ansL<=v[i]&&v[i]<=ansR&&ansR<=r[i]){
			printf("%d ",i);
		}
	}	
	puts("");
	return 0;
}