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
#define ALL(x) (x).begin(),(x).end()
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

const int N=1005,M=N*N/2;
struct edge{
	int u,v,w;
	friend bool operator < (edge a,edge b){
		return a.w>b.w;
	}
};
vector<edge> T[M<<2],nw;
int ex[M<<2],pa[N],w[N];
int U[M],V[M],W[M];
int n,m,Q,res;

int gp(int x){
	if(pa[x]==x) return x;
	int p=gp(pa[x]);
	w[x]^=w[pa[x]];
	return pa[x]=p;
}

void doit(vector<edge> &E,int &ex,int flag=1){
	rep(i,1,n){
		pa[i]=i,w[i]=0;
	}
	vector<edge> res;
	for(auto x:E){
		int a=gp(x.u),b=gp(x.v);
		if(a!=b){
			w[a]=w[x.u]^w[x.v]^1;
			pa[a]=b;
			if(flag) res.pb(x);
			continue;
		}
		if(w[x.u]==w[x.v]) ex=max(ex,x.w);
	}
	if(flag) E=res;
}

void build(int o,int l,int r){
	if(l==r){
		T[o].pb((edge){U[l],V[l],W[l]});
		ex[o]=-1;
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	ex[o]=max(ex[lc],ex[rc]);
	T[o].resize(SZ(T[lc])+SZ(T[rc]));
	merge(ALL(T[lc]),ALL(T[rc]),T[o].begin());
	doit(T[o],ex[o]);
}

void qry(int o,int l,int r,int x,int y){
	if(l==x&&y==r){
		for(auto x:T[o]) nw.pb(x);
		res=max(res,ex[o]);
		return;
	}
	if(x<=mid) qry(lc,l,mid,x,min(y,mid));
	if(mid<y) qry(rc,mid+1,r,max(mid+1,x),y);
}

int main(){
	read(n),read(m),read(Q);
	rep(i,1,m){
		read(U[i]),read(V[i]),read(W[i]);
	}
	build(1,1,m);
	while(Q--){
		int l,r;
		read(l),read(r);
		nw.clear(),res=-1;
		qry(1,1,m,l,r);
		sort(nw.begin(),nw.end());
		doit(nw,res);
		printf("%d\n",res);
	}
	return 0;
}