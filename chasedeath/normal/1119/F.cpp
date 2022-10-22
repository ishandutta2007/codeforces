#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2.5e5+10,U=1e6,M=N*40;

int n,m;
int A[N],C,D[N];
vector <Pii> E[N],G[N];
int I[N],V[N];

int rt[N],ls[M],rs[M],c[M],cnt; ll s[M];
void Upd(int &p,int l,int r,int x,int y) {
	if(!p) p=++cnt;
	s[p]+=x*y,c[p]+=y;
	if(l==r) return;
	int mid=(l+r)>>1;
	x<=mid?Upd(ls[p],l,mid,x,y):Upd(rs[p],mid+1,r,x,y);
}
ll Que(int p,int l,int r,int k){
	if(c[p]<k) return 1e18;
	if(!k || l==r) return l*k;
	int mid=(l+r)>>1;
	if(c[ls[p]]>=k) return Que(ls[p],l,mid,k);
	return s[ls[p]]+Que(rs[p],mid+1,r,k-c[ls[p]]);
}

ll dp[N][2];
int vis[N];
void dfs(int u) {
	vis[u]=1;
	dp[u][0]=dp[u][1]=0;
	vector <ll> val;
	int c=0; ll s=0;
	for(Pii t:G[u]) {
		int v=t.first,w=t.second;
		if(vis[v]) continue;
		dfs(v);
		dp[v][1]+=w,s+=dp[v][0];
		if(dp[v][1]<=dp[v][0]) c++,s+=dp[v][1]-dp[v][0];
		else val.pb(dp[v][1]-dp[v][0]);
	}
	sort(val.begin(),val.end());
	// Get the sum of first k elements
	auto F=[&](int k) {
		ll ans=Que(rt[u],1,U,k),s=0;
		for(ll i:val) {
			if(--k<0) break;
			cmin(ans,(s+=i)+Que(rt[u],1,U,k));
		}
		return ans;
	};
	dp[u][0]=s+F(max(0,D[u]-c-m));
	dp[u][1]=s+F(max(0,D[u]-c-1-m));
	//cout<<"Dfs "<<u<<' '<<dp[u][0]<<' '<<dp[u][1]<<endl;
}

ll ans[N];
int main() {
	n=rd();
	rep(i,2,n) {
		int u=rd(),v=rd(),w=rd();
		ans[0]+=w;
		E[u].pb(mp(v,w)),E[v].pb(mp(u,w));
		Upd(rt[u],1,U,w,1),Upd(rt[v],1,U,w,1);
		D[u]++,D[v]++;
	}
	rep(i,1,n) I[i]=i;
	sort(I+1,I+n+1,[&](int x,int y){ return D[x]>D[y]; });
	int p=1;
	for(m=n-1;m;m--) {
		//printf("Solving %d \n",m);
		while(p && D[I[p]]>m) {
			int u=I[p++];
			V[A[++C]=u]=1;
			for(Pii v:E[u]) if(V[v.first]) {
				Upd(rt[u],1,U,v.second,-1),Upd(rt[v.first],1,U,v.second,-1);
				G[u].pb(v),G[v.first].pb(mp(u,v.second));
			}
		}
		rep(i,1,C) vis[A[i]]=0;
		rep(i,1,C) if(!vis[A[i]]) dfs(A[i]),ans[m]+=dp[A[i]][0];
	}
	rep(i,0,n-1) printf("%lld ",ans[i]);
}