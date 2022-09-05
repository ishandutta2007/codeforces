#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lc(k) (k<<1)
#define rc(k) (k<<1|1)
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 444000, M = 1222222;const double eps = 1e-9;
int n,m;int head[N],to[N],nxt[N],A[N],B[N],edgenum;
void addedge(int u, int v, int a, int b){
	to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
	A[edgenum]=a;B[edgenum]=b;
}
int size[N],top[N],son[N],fa[N];ll qzA[N],qzB[N];
void dfs1(int u, int Fa){
	size[u]=1;fa[u]=Fa;
	L(i,u)if(to[i]!=Fa){
		qzA[to[i]]=qzA[u]+A[i];qzB[to[i]]=qzB[u]+B[i];
		dfs1(to[i],u),size[u]+=size[to[i]];
	}
}
void dfs2(int u, int Top){
	top[u]=Top;
	int mx=0;L(i,u)if(to[i]!=fa[u]&&(!mx||size[to[i]]>size[mx]))mx=to[i];
	if(mx)dfs2(mx,Top),son[u]=mx;
	L(i,u)if(to[i]!=fa[u]&&to[i]!=mx)dfs2(to[i],to[i]);
}

struct dot{
	ll x,y;
	dot(ll X=0,ll Y=0){x=X;y=Y;}
}a[N],b[N],c[N];vector<dot>d[N];
inline int dcmp(double x){if(x>eps)return 1;if(x<-eps)return -1;return 0;}
inline double getlen(dot a){return sqrt(1.0*a.x*a.x+1.0*a.y*a.y);}
bool cmp(const dot &a, const dot &b){
	int t=dcmp(1.0*a.x*b.y-1.0*a.y*b.x);return t!=0?t>0:getlen(a)<getlen(b);
}
dot operator + (const dot &a, const dot &b){return dot(a.x+b.x,a.y+b.y);}
dot operator - (const dot &a, const dot &b){return dot(a.x-b.x,a.y-b.y);}
double cross(dot a, dot b){return 1.0*a.x*b.y-1.0*a.y*b.x;}
inline void graham(dot *a, int &n){
	if(n==1)return;sort(a+1,a+n+1,cmp);static dot sta[N];int top=0;
	sta[++top]=a[1];sta[++top]=a[2];
	rep(i,3,n){
		while(top>1&&dcmp(cross(a[i]-sta[top-1],sta[top]-sta[top-1]))>=0)top--;
		sta[++top]=a[i];
	}
	n=top;rep(i,1,n)a[i]=sta[i];
}
inline void merge(int n, int m, int &len){
	len=0;int p1=1,p2=1;
	while(p1<=n&&p2<=m){
		if(p2==m){c[++len]=a[p1]+b[p2];p1++;}
		else if(p1==n){c[++len]=a[p1]+b[p2];p2++;}
		else{
			c[++len]=a[p1]+b[p2];
			if(dcmp(cross(a[p1+1]-a[p1],b[p2+1]-b[p2]))>=0)p1++;else p2++;
		}
	}
}
struct node{
	ll k,b;int l,r;
}tree[M<<2];
void build(int k, int l, int r){
	tree[k].l=l;tree[k].r=r;if(l==r)return;
	int mid=(l+r)>>1;build(lc(k),l,mid);build(rc(k),mid+1,r);
}
inline void modify(int k, ll K, ll B){
	ll l=tree[k].l,r=tree[k].r;bool bl=K*l+B>=tree[k].k*l+tree[k].b,br=K*r+B>=tree[k].k*r+tree[k].b;
	if(bl&&br){tree[k].k=K;tree[k].b=B;return;}
	if(!bl&&!br){return;}double bmid=K*tree[lc(k)].r+B>=tree[k].k*tree[lc(k)].r+tree[k].b;
	if(bl){
		if(bmid){modify(rc(k),tree[k].k,tree[k].b);tree[k].k=K;tree[k].b=B;}
		else modify(lc(k),K,B);
	}
	else{
		if(bmid){modify(lc(k),tree[k].k,tree[k].b);tree[k].k=K;tree[k].b=B;}
		else modify(rc(k),K,B);
	}
}
inline ll query(int k, int p){
	ll now=1LL*p*tree[k].k+tree[k].b;
	if(tree[k].l==tree[k].r)return now;
	return max(now,p<=tree[lc(k)].r?query(lc(k),p):query(rc(k),p));
}
inline void add(ll a, ll b){modify(1,a,b);}
multiset<Pll>Set[N];int s[N];//WA1
inline void solve(int l,int r){
	if(l>=r)return;int mid=(l+r)>>1;//[l,mid] & [mid+1,r]
	int n=0,m=0;ll offA=qzA[s[mid]],offB=qzB[s[mid]];//WA2
	rep(i,l,mid)for(multiset<Pll>::iterator it=Set[s[i]].begin();it!=Set[s[i]].end();it++){
		Pll t=*it;a[++n]=dot(t.fi-qzA[s[i]]+offA,t.se-qzB[s[i]]+offB);
	}
	rep(i,mid+1,r)for(multiset<Pll>::iterator it=Set[s[i]].begin();it!=Set[s[i]].end();it++){
		Pll t=*it;b[++m]=dot(t.fi+qzA[s[i]]-offA,t.se+qzB[s[i]]-offB);
	}
	a[++n]=dot(0,0);b[++m]=dot(0,0);graham(a,n);graham(b,m);
	/*if(r==4&&l==1){
		rep(i,1,n)printf("(%lld,%lld) ",a[i].x,a[i].y);puts("");
		rep(i,1,m)printf("(%lld,%lld) ",b[i].x,b[i].y);puts("");
	}*/
	int len=0;merge(n,m,len);rep(i,1,len)add(c[i].x,c[i].y);
	/*ll besta=0,bestb=0,bestc=0;
	rep(i,1,n)besta=max(besta,a[i].y);
	rep(i,1,m)bestb=max(bestb,b[i].y);
	rep(i,1,len)bestc=max(bestc,c[i].y);
	assert(besta+bestb==bestc);*/
	solve(l,mid);solve(mid+1,r);
}
inline void SOLVE(int l, int r){
	if(l>=r)return;int mid=(l+r)>>1;int n=0,m=0;
	rep(i,l,mid)per(j,SZ(d[i])-1,0)a[++n]=d[i][j];rep(i,mid+1,r)per(j,SZ(d[i])-1,0)b[++m]=d[i][j];
	a[++n]=dot(0,0);b[++m]=dot(0,0);graham(a,n);graham(b,m);
	int len=0;merge(n,m,len);rep(i,1,len)add(c[i].x,c[i].y);
	SOLVE(l,mid);SOLVE(mid+1,r);
}
void dfs(int u){
	L(i,u)if(to[i]!=fa[u])dfs(to[i]);
	if(top[u]==u){
		int len=0;for(int v=u;v;v=son[v]){
			s[++len]=v;
			for(multiset<Pll>::iterator it=Set[v].begin();it!=Set[v].end();it++){
				Set[fa[u]].insert(Pll((*it).fi+qzA[v]-qzA[fa[u]],(*it).se+qzB[v]-qzB[fa[u]]));
			}
		}
	//	printf("len = %d\n",len);
		solve(1,len);
	}
}
int cnt;
inline void DFS(int u, ll x, ll y){
	int num=0;L(i,u)if(to[i]!=fa[u])DFS(to[i],x+A[i],y+B[i]),num++;if(!num)d[cnt].pb(dot(x,y));
}
int main() { //freopen("data.in","r",stdin);
	read(n);read(m);
	rep(i,1,n-1){
		int u,v,a,b;read(u);read(v);read(a);read(b);
		addedge(u,v,a,b);addedge(v,u,a,b);
	}
	dfs1(1,0);dfs2(1,1);rep(i,1,n)Set[i].insert(Pll(0,0));build(1,0,m-1);
//	rep(i,1,n)printf("%d:%d %d %lld %lld\n",i,top[i],son[i],qzA[i],qzB[i]);
	dfs(1);rep(u,1,n){
		cnt=0;
		L(i,u)if(to[i]!=fa[u]&&to[i]!=son[u]){cnt++;d[cnt].clear();DFS(to[i],A[i],B[i]);}
		SOLVE(1,cnt);
	}
	rep(i,0,m-1)printf("%lld ",query(1,i));
	return 0;
}