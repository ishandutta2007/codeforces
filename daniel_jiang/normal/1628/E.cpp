// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[40]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=6e5+5;
int n,tot,hd[N],Q,f[N<<1][22],dep[N],dfn[N],rk[N],qwq;
struct edge{int t,nxt;}es[N<<1];
int fa[N],siz[N];
inline int found(int x){return fa[x]==x?x:fa[x]=found(fa[x]);}
inline void merge(int x,int y){
	int fx=found(x),fy=found(y);
	if(siz[fx]<siz[fy]) swap(fx,fy);
	fa[fy]=fx;siz[fx]+=siz[fy];siz[fy]=0;
}

int cnte,cnt,val[N<<1];
struct Edge{int u,v,w;}e[N<<1];
struct EDGE{int t,nxt;}E[N<<3];
inline void add(int x,int y,int z){es[++tot]=(edge){y,hd[x]};hd[x]=tot;e[tot]=(Edge){x,y,z};}
inline void Add(int x,int y){E[++cnte]=(EDGE){y,hd[x]};hd[x]=cnte;}
inline bool cmp(Edge x,Edge y){return x.w<y.w;}
inline void kruscal(){
	cnt=n;
	for(re i=1;i<=(n<<1);++i) fa[i]=i,siz[i]=1,hd[i]=0;
	sort(e+1,e+tot+1,cmp);
	for(re i=1;i<=tot;++i)
		if(found(e[i].u)^found(e[i].v)){
			val[++cnt]=e[i].w;
			Add(found(e[i].u),cnt);Add(cnt,found(e[i].u));Add(found(e[i].v),cnt);Add(cnt,found(e[i].v));
//			cout<<"edge "<<cnt<<' '<<found(e[i].u)<<' '<<found(e[i].v)<<endl;
			fa[found(e[i].u)]=fa[found(e[i].v)]=cnt;
		}
}

inline void dfs(int x,int fa){
	f[x][0]=fa;dep[x]=dep[fa]+1;dfn[x]=++qwq;rk[qwq]=x;
	for(re i=hd[x];i;i=E[i].nxt)
		if(E[i].t^fa) dfs(E[i].t,x);
}

inline int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(re i=21;i>=0;--i)
		if(f[x][i]&&dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(re i=21;i>=0;--i)
		if(f[x][i]&&f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

struct SGT{
	#define xl (x<<1)
	#define xr (x<<1|1)
	#define mid ((l+r)>>1)
	const int INF=1e9;
	int mx[N<<2],mn[N<<2],Mx[N<<2],Mn[N<<2],tag[N<<2],fl[N<<2];
	inline void pushup(int x){mx[x]=max(mx[xl],mx[xr]);mn[x]=min(mn[xl],mn[xr]);}
	inline void pushdown(int x){if(fl[x]){tag[xl]=tag[xr]=tag[x];mx[xl]=(tag[xl]?Mx[xl]:0);mn[xl]=(tag[xl]?Mn[xl]:INF);mx[xr]=(tag[xr]?Mx[xr]:0);mn[xr]=(tag[xr]?Mn[xr]:INF);fl[xl]=fl[xr]=1;fl[x]=0;}}
	inline void build(int x,int l,int r){
		mx[x]=tag[x]=0;mn[x]=INF;
		if(l==r){Mx[x]=Mn[x]=dfn[l];return ;}
		build(xl,l,mid);build(xr,mid+1,r);
		Mx[x]=max(Mx[xl],Mx[xr]);Mn[x]=min(Mn[xl],Mn[xr]);
	}
	inline void modify(int x,int l,int r,int L,int R,int k){
		if(L<=l&&r<=R){
			tag[x]=k;fl[x]=1;mx[x]=(k?Mx[x]:0);mn[x]=(k?Mn[x]:INF);
			return ;
		}
		pushdown(x);
		if(mid>=L) modify(xl,l,mid,L,R,k);
		if(mid<R) modify(xr,mid+1,r,L,R,k);
		pushup(x);
	}
}T;

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(n);rd(Q);
	for(re i=1;i<n;++i){int x,y,z;rd(x);rd(y);rd(z);add(x,y,z);add(y,x,z);}
	kruscal();dfs(cnt,0);
	for(re s=1;s<=21;++s)
		for(re i=1;i<=cnt;++i) f[i][s]=f[f[i][s-1]][s-1];
	T.build(1,1,cnt);
//	for(re i=1;i<=cnt;++i) cout<<i<<" dfn "<<dfn[i]<<endl;
	for(re i=1;i<=Q;++i){
		int op,l,r;rd(op);
		if(op<=2) rd(l),rd(r),T.modify(1,1,cnt,l,r,(op-1)^1);
		else{
//			puts("test");
			rd(l);int st=T.mn[1],ed=T.mx[1];
//			cout<<"st "<<st<<" ed "<<ed<<endl;
			if(st==dfn[l]&&ed==dfn[l]||ed==0) puts("-1");
			else wr(val[LCA(LCA(rk[st],rk[ed]),l)]),puts("");
		}
	}
	return 0;
}

// ---------- Main ---------- //

/*
10 10
2 1 2
3 2 13
4 3 15
5 2 1
6 5 17
7 1 5
8 5 5
9 3 3
10 1 20
3 7
3 9
2 7 8
1 3 10
2 5 9
1 2 7
3 7
1 1 1
3 10
1 3 6
*/
/*
-1
-1
20
20
*/