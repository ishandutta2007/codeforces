#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 266666;
int w,h,n;vector<char>s[N];
Vi a[N],e[N];bool vis[N];int dl[N],dr[N],num,ind[N];ll res;
int bh(int x, int y){return (x-1)*h+y;}
void dfs(int u, int fa){
	dl[u]=++num;vis[u]=1;//printf("fa %d = %d\n",u,fa);
	for(int v:e[u])if(v!=fa){
		if(vis[v])printf("e %d %d\n",u,v);
		else dfs(v,u);
	}
	dr[u]=num;
}
void doit(int x, int y){
	if(dl[x]>dl[y])swap(x,y);
	a[dl[x]].pb(y);a[dr[x]+1].pb(-y);
}

int val[N<<2],cov[N<<2];
void upd(int k, int l, int r){val[k]=cov[k]?r-l+1:val[k<<1]+val[k<<1|1];}
void mdy(int k, int l, int r, int x, int L, int R){
	if(l==L&&r==R){cov[k]+=x;upd(k,L,R);return;}
	int mid=(L+R)>>1;
	if(r<=mid)mdy(k<<1,l,r,x,L,mid);
	else if(l>mid)mdy(k<<1|1,l,r,x,mid+1,R);
	else mdy(k<<1,l,mid,x,L,mid),mdy(k<<1|1,mid+1,r,x,mid+1,R);
	upd(k,L,R);
}
int main() {
	read(w);read(h);char S[N];
	rep(i,0,w+1)s[i].resize(h+2);
	rep(i,1,w){
		scanf("%s",S+1);
		rep(j,1,h)s[i][j]=S[j];
	}
	rep(i,1,w)rep(j,1,h){
		if(i-2>=1&&s[i-2][j]=='U'&&s[i-1][j]=='D')e[bh(i,j)].pb(bh(i-2,j));
		if(i+2<=w&&s[i+1][j]=='U'&&s[i+2][j]=='D')e[bh(i,j)].pb(bh(i+2,j));
		if(j-2>=1&&s[i][j-2]=='L'&&s[i][j-1]=='R')e[bh(i,j)].pb(bh(i,j-2));
		if(j+2<=h&&s[i][j+1]=='L'&&s[i][j+2]=='R')e[bh(i,j)].pb(bh(i,j+2));
	}
	rep(i,1,w*h){
		for(int j:e[i])ind[j]++;
	}
	/*rep(i,1,w*h){
		for(int j:e[i])printf("%d-->%d\n",i,j);
	}*/
	rep(i,1,w)rep(j,1,h)if((i+j&1)&&!vis[bh(i,j)]&&!ind[bh(i,j)])dfs(bh(i,j),0);
	rep(i,1,w)rep(j,1,h)if((~(i+j)&1)&&!vis[bh(i,j)]&&!ind[bh(i,j)])dfs(bh(i,j),0);
	rep(i,1,w*h)assert(vis[i]);
	rep(i,1,w)rep(j,1,h){
		if(s[i][j]=='L'){doit(bh(i,j),bh(i,j+1));}
		if(s[i][j]=='U'){doit(bh(i,j),bh(i+1,j));}
	}
	rep(i,1,w*h/2){
		for(int j:a[i]){int xs=1;if(j<0)j=-j,xs=-1;mdy(1,dl[j],dr[j],xs,1,w*h);}
		res+=val[1];
	}
	cout<<res;
	return 0;
}