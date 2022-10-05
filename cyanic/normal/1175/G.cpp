#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
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

const int N=20005,inf=1e9;
struct pt{
	int x,y;
	friend ll cro(pt p,pt a,pt b){
		return (ll)(a.x-p.x)*(b.y-p.y)
			  -(ll)(a.y-p.y)*(b.x-p.x);
	}
};
vector<pt> T[N<<2]; int p[N<<2];
int a[N],rk[N],mx[N][18],lg[N];
int lc[N],rc[N],L[N],R[N],t[N];
int f[N],g[N],n,K,rt;

int cmp1(int x,int y){
	return a[x]>a[y];
}
int Mx(int x,int y){
	return cmp1(x,y)?x:y;
}
int getmx(int l,int r){
	int t=lg[r-l+1];
	return Mx(mx[l][t],mx[r-(1<<t)+1][t]);
}
int doit(int l,int r){
	int o=getmx(l,r);
	L[o]=l,R[o]=r;
	if(l<o) lc[o]=doit(l,o-1);
	if(o<r) rc[o]=doit(o+1,r);
	return o;
}

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
void init(){
	rep(o,1,n<<2){
		T[o].clear();
		p[o]=0;
	}
}
void build(int o,int l,int r){
	vector<pt> nw;
	int sz=0;
	REP(k,SZ(T[o])){
		while(sz>=2&&cro(nw[sz-2],nw[sz-1],T[o][k])<=0){
			nw.pop_back(),sz--;
		}
		nw.pb(T[o][k]),sz++;
	}
	T[o]=nw;
	p[o]=SZ(T[o])-1;
	if(l==r) return;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void ins(int o,int l,int r,int x,int y,pt z,int ty){
	if(ty==0) T[o].pb(z);
	if(l==x&&y==r){ if(ty==1) T[o].pb(z); return; }
	if(x<=mid) ins(lc,l,mid,x,min(y,mid),z,ty);
	if(mid<y) ins(rc,mid+1,r,max(mid+1,x),y,z,ty);
}
int result;
int F(pt &x,int y){ return x.x*y+x.y; }
void ask(int o,int v){
	while(p[o]>=1&&F(T[o][p[o]-1],v)<F(T[o][p[o]],v)) p[o]--;
	if(p[o]>=0) result=min(result,F(T[o][p[o]],v));
}
void qry(int o,int l,int r,int x,int y,int z,int ty){
	if(ty==0) ask(o,z);
	if(l==x&&y==r){ if(ty==1) ask(o,z); return; }
	if(x<=mid) qry(lc,l,mid,x,min(y,mid),z,ty);
	if(mid<y) qry(rc,mid+1,r,max(mid+1,x),y,z,ty);
}
#undef lc
#undef rc
#undef mid

int main(){
	read(n),read(K);
	lg[0]=-1;
	rep(i,1,n){
		read(a[i]);
		rk[i]=i;
		mx[i][0]=i;
		lg[i]=lg[i>>1]+1;
	}
	sort(rk+1,rk+n+1,cmp1);
	per(i,n,1){
		for(int j=1;i+(1<<j)-1<=n;j++){
			mx[i][j]=Mx(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
		}
	}
	rt=doit(1,n);
	memset(f,0x3f,sizeof f);
	f[0]=0;
	while(K--){
		memset(g,0x3f,sizeof g);
		init();
		per(i,n,0){
			ins(1,0,n,i,i,(pt){n-i,f[i]},0);
		}
		build(1,0,n);
		rep(i,1,n){
			int k=rk[n+1-i];
			result=inf,qry(1,0,n,L[k]-1,k-1,a[k],1),t[k]=result;
			t[k]-=(n-k)*a[k];
			//printf("@ %d %d\n",k,t[k]);
		}
		init();
		rep(i,1,n){
			int k=rk[n+1-i];
			ins(1,0,n,k,R[k],(pt){a[k],t[k]-a[k]*k},1);
		}
		build(1,0,n);
		rep(i,1,n){
			result=inf,qry(1,0,n,i,i,i,0),g[i]=result;
			//printf("# %d  %d\n",i,g[i]);
		}
		memcpy(f,g,sizeof f);
	}
	printf("%d\n",f[n]);
	return 0;
}