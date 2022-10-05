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
typedef double ld;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=5005,M=100005;
struct node{
	int l,r; ld p;
	friend bool operator < (node a,node b){
		return a.r-a.l>b.r-b.l;
	}
} x[N];
int a[M],mx[N],val[N],sz[N],n,m;
ld f[N][N],g[N],ans;
set<int> s;
vi e[N];

void dfs(int u){
	mx[u]=val[u],f[u][0]=1;
	for(auto v:e[u]){
		dfs(v);
		rep(k,0,sz[u]+sz[v]) g[k]=0;
		int nw=max(mx[u],mx[v]);
		rep(i,0,sz[u]) if(f[u][i])
			rep(j,0,sz[v]) if(f[v][j]){
				int ex=max(mx[u]+i,mx[v]+j)-nw;
				g[ex]+=f[u][i]*f[v][j];
			}
		sz[u]+=sz[v],mx[u]=nw;
		rep(k,0,sz[u]) f[u][k]=g[k];
	}
	rep(k,0,sz[u]+1) g[k]=0;
	rep(i,0,sz[u]) if(f[u][i]){
		g[i]+=f[u][i]*(1-x[u].p);
		g[i+1]+=f[u][i]*x[u].p;
	}
	sz[u]+=1;
	rep(k,0,sz[u]) f[u][k]=g[k];
}

int main(){
	read(n),read(m);
	rep(i,1,n){
		read(a[i]);
		s.insert(i);
	}
	rep(i,1,m){
		read(x[i].l),read(x[i].r);
		scanf("%lf",&x[i].p);
	}
	x[0].l=1,x[0].r=n;
	sort(x+1,x+m+1);
	rep(i,1,m){
		int k=i-1;
		while(k&&!(x[k].l<=x[i].l&&x[i].r<=x[k].r)) k--;
		e[k].pb(i);
	}
	per(i,m,0){
		auto it=s.lower_bound(x[i].l);
		while(it!=s.end()&&*it<=x[i].r){
			val[i]=max(val[i],a[*it]);
			s.erase(it);
			it=s.lower_bound(x[i].l);
		}
	}
	dfs(0);
	rep(i,0,sz[0]){
		ans+=f[0][i]*(mx[0]+i);
	}
	printf("%.8lf\n",ans);
	return 0;
}