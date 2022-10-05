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

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}
void GG(){ puts("0"),exit(0); }

const int N=500005,mod=1e9+7;
struct node{
	int fir,las,sz;
	vi l,r,vis;
	void init(int m){
		sz=m,l.resize(m+1),r.resize(m+1);
	}
	void First(int x){
		if(fir&&fir!=x) GG();
		fir=x;
	}
	void Last(int x){
		if(las&&las!=x) GG();
		las=x;
	}
	void Link(int x,int y){
		if(r[x]&&r[x]!=y) GG();
		if(l[y]&&l[y]!=x) GG();
		r[x]=y,l[y]=x;
	}
	int solve(){
		if(l[fir]||r[las]) GG();
		vis.resize(sz+1);
		int cnt=0,flag=0;
		rep(i,1,sz) if(!vis[i]&&!l[i]){
			int x=i;
			vis[x]=1;
			while(r[x]){
				x=r[x];
				if(vis[x]) GG();
				vis[x]=1;
			}
			if(i==fir&&x==las) flag=1;
			++cnt;
		}
		rep(i,1,sz) if(!vis[i]) GG();
		if(flag){
			if(cnt>=2) GG();
			return 0;
		}
		return cnt-(fir>0)-(las>0);
	}
} p[N];
int fa[N],d[N],a[N],id[N],fac[N];
int n,tot;
vi e[N];

void dfs(int u){
	p[u].init(e[u].size());
	int num=(fa[u]>0);
	REP(i,e[u].size()){
		int v=e[u][i];
		if(v==fa[u]) continue;
		d[v]=d[u]+1;
		id[v]=++num;
		fa[v]=u,dfs(v);
	}
}

void doit(int a,int b){
	int na=0,nb=0;
	while(a!=b){
		if(d[a]>=d[b]){
			if(!na) p[a].First(1);
			else p[a].Link(na,1);
			na=id[a],a=fa[a];
		}
		else{
			if(!nb) p[b].Last(1);
			else p[b].Link(1,nb);
			nb=id[b],b=fa[b];
		}
		if(++tot>n*2) GG();
	}
	if(na&&nb) p[a].Link(na,nb);
	else if(na) p[b].Last(na);
	else if(nb) p[a].First(nb);
	else GG();
}

int main(){
	read(n);
	rep(i,1,n-1){
		int u,v;
		read(u),read(v);
		e[u].pb(v),e[v].pb(u);
	}
	d[1]=1,dfs(1);
	rep(i,1,n){
		read(a[i]);
		if(a[i]) doit(a[i],i);
	}
	fac[0]=1;
	rep(i,1,n) fac[i]=(ll)fac[i-1]*i%mod;
	int ans=1;
	rep(i,1,n) ans=(ll)ans*fac[p[i].solve()]%mod;
	cout<<ans<<endl;
	return 0;
}