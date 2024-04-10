#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
template<class T>inl bool ylmin(T &a,T b){return a<b?0:(a=b,1);}
template<class T>inl bool ylmax(T &a,T b){return a>b?0:(a=b,1);}
template<class T>inl T abs(T x){return x<0?-x:x;}
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
using namespace std;
const int N=1e6,inf=1e18,mod=1000000007;
int a[N],fa[N],n,m,u[N],v[N],ans[N],F[N],dep[N];
vector<pair<int,int> > e[N];
int ff(int x){
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
void mer(int x,int y) {
	fa[ff(x)]=ff(y);
}
void Clear(){
	for(int i=1;i<=n;i++) {
		e[i].clear(),ans[i]=2;
	}
}
void dfs(int u,int f){
	for(auto v:e[u]) {
		if(v.first!=f) {
			dep[v.first]=dep[u]+1;
			F[v.first]=v.second,dfs(v.first,u);
		}
	}
}
void solve(){
	cin >> n >> m;
	vector<pair<int,int> > s;
	vector<int> id;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		cin >> u[i] >> v[i];
		if(ff(u[i])!=ff(v[i])) {
			mer(u[i],v[i]),ans[i]=1;
			e[u[i]].push_back({v[i],i});
			e[v[i]].push_back({u[i],i});
		}
		else
		{
			s.push_back({u[i],v[i]}),ans[i]=0,id.push_back(i);
		}
	}
	dfs(1,0);
	if(s.size()==3) {
		set<int> S;
		S.insert(s[0].fi);
		S.insert(s[1].fi);
		S.insert(s[2].fi);
		S.insert(s[0].se);
		S.insert(s[1].se);
		S.insert(s[2].se);
		if(S.size()==3) {
			if(dep[s[0].fi]<dep[s[0].se]) swap(s[0].fi,s[0].se);
			ans[id[0]]^=1,ans[F[s[0].fi]]^=1;
		}
	}
	for(int i=1;i<=m;i++)
		cout << ans[i];
	cout << "\n"; 
	return ;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	cin >> T;
	while(T--){
		solve();
		Clear();
	}
	return 0;
}