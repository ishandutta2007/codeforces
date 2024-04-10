#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef unsigned int u32;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

u32 tr[376][32],st[376],mer[376][376],cnt;
map<u32,int> id;

void dfs(int k,int OR,u32 now){
	if(k==-1){
		st[++cnt]=now;
		id[now]=cnt;
		return;
	}
	dfs(k-1,OR,now);
	if(OR>>k&1) return;
	REP(i,1<<k) dfs(k-1,OR|i,now|(u32(1)<<((1<<k)|i)));
}

void Print(u32 now){
	//cerr<<now<<endl;
	per(k,31,0)if(now>>k&1){
		per(j,4,0) if(k>>j&1) putchar('1'); else putchar('0');
		puts("");
	}
}

void init(){
	dfs(4,0,0);
	static u32 a[5];
	rep(i,1,cnt) rep(j,1,31){
		fill(a,a+5,0);
		REP(k,5){
			rep(p,1<<k,(1<<(k+1))-1)
				if(st[i]>>p&1) a[k]=p;
		}
		int now=j;
		per(k,4,0) if(now>>k&1){
			if(!a[k]){
				per(t,k-1,0) if(now>>t&1) now^=a[t];
				per(t,4,k+1) if(a[t]>>k&1) a[t]^=now;
				a[k]=now,now=-1;
				break;
			}
			now^=a[k];
		}
		if(now==-1){
			u32 res=0;
			REP(k,5) if(a[k]) res|=u32(1)<<a[k];
			tr[i][j]=id[res];
			/*
			puts("-------");
			Print(st[i]);
			printf("->  %d\n",j);
			Print(res);
			*/
		}
	}
	rep(i,1,cnt) rep(j,1,cnt){
		int now=i;
		REP(k,32) if(st[j]>>k&1)
			now=tr[now][k];
		mer[i][j]=now;
	}
}

const int N=200005,mod=1e9+7;
int pa[N],f[N],mark[N],anc[N],state[N];
int dp[376],ndp[376],u[N],v[N],w[N],n,m;
vector<pii> e[N];

void add(int &a,int b){
	a=(a+b>=mod?a+b-mod:a+b);
}

int vis[N];
void dfs(int u,int fa,int top){
	anc[u]=top,pa[u]=fa,vis[u]=1;
	//printf("## %d %d %d\n",u,fa,top);
	for(auto v:e[u]){
		if(!mark[v.fi]&&v.fi!=fa&&!vis[v.fi]){
			f[v.fi]=f[u]^v.se;
			dfs(v.fi,u,top);
		}
	}
}

int main(){
	init();	
	read(n),read(m);
	rep(i,1,n) pa[i]=i;
	rep(i,1,m){
		read(u[i]),read(v[i]),read(w[i]);
		if(v[i]==1) swap(u[i],v[i]);
		if(u[i]==1) mark[v[i]]=1,f[v[i]]=w[i],state[v[i]]=1;
		e[u[i]].pb(mp(v[i],w[i]));
		e[v[i]].pb(mp(u[i],w[i]));
	}
	rep(i,1,n) if(mark[i]) dfs(i,1,i);
	rep(i,1,m){
		if(mark[u[i]]&&mark[v[i]]){
			mark[u[i]]=mark[v[i]]=2;
			continue;
		}
		if(pa[u[i]]==v[i]||pa[v[i]]==u[i]) continue;
		int nw=f[u[i]]^f[v[i]]^w[i],top=anc[u[i]];
		state[top]=tr[state[top]][nw];
	}
	dp[1]=1;
	int tot=1;
	rep(i,1,n){
		if(mark[i]!=1) continue;
		memcpy(ndp,dp,sizeof ndp);
		rep(j,0,cnt) if(dp[j])
			add(ndp[mer[j][state[i]]],dp[j]);
		memcpy(dp,ndp,sizeof dp);
		add(tot,tot);
	}
	rep(i,1,m){
		if(!mark[u[i]]||!mark[v[i]]) continue;
		memcpy(ndp,dp,sizeof ndp);
		int A=mer[state[u[i]]][state[v[i]]];
		int B=tr[A][f[u[i]]^f[v[i]]^w[i]];
		rep(j,0,cnt) if(dp[j]){
			add(ndp[mer[j][A]],dp[j]);
			add(ndp[mer[j][A]],dp[j]);
			add(ndp[mer[j][B]],dp[j]);
		}
		memcpy(dp,ndp,sizeof dp);
		add(tot,tot),add(tot,tot);
	}
	int ans=(tot+mod-dp[0])%mod;
	cout<<ans<<endl;
	return 0;
}