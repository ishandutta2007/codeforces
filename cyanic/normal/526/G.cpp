#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=200005;
int d[N],rt,rt2,n,Q,a,b,c,x,y,ans;
vector<pii> e[N];

void getrt(int u,int fa){
	for(auto v:e[u])
		if(v.fi!=fa){
			d[v.fi]=d[u]+v.se;
			getrt(v.fi,u);
		}
}

struct T{
	int d[N],sn[N],fa[N],anc[N],f[N],g[N],h[N],res[N];
	int cnt;
	void dp(int u){
		for(auto v:e[u])
			if(v.fi!=fa[u]){
				fa[v.fi]=u;
				d[v.fi]=d[u]+v.se;
				dp(v.fi);
				f[v.fi]+=v.se;
				if(f[v.fi]>f[u]){
					f[u]=f[v.fi];
					sn[u]=v.fi;
				}
			}
		for(auto v:e[u])
			if(v.fi!=fa[u]&&v.fi!=sn[u])
				h[++cnt]=v.fi;
	}
	void dfs(int u,int top){
		anc[u]=top;
		if(!g[u]) g[u]=g[fa[u]];
		if(sn[u]) dfs(sn[u],top);
		for(auto v:e[u])
			if(v.fi!=fa[u]&&v.fi!=sn[u])
				dfs(v.fi,v.fi);
	}
	int solve(int x,int y){
		int tot=2*y-1;
		if(g[x]<=tot)return res[min(cnt,tot)];
		int ans1=res[tot-1]+f[sn[x]]+d[x];
		int ans2=res[tot]+f[sn[x]]+d[x],t=x;
		while(g[x]>=tot)x=fa[anc[x]];
		ans1-=d[x];
		while(g[t]>tot)t=fa[anc[t]];
		ans2=ans2-d[t]-f[sn[t]];
		return max(ans1,ans2);
	}
	void rmain(int rt){
		d[rt]=0,dp(rt),h[++cnt]=rt;
		sort(h+1,h+cnt+1,[&](int a,int b){
			return f[a]>f[b];
		});
		rep(i,1,cnt){
			g[h[i]]=i;
			res[i]=res[i-1]+f[h[i]];
		}
		dfs(rt,rt);
	}
}A,B;

int main(){
	read(n),read(Q);
	rep(i,1,n-1){
		read(a),read(b),read(c);
		e[a].pb(mp(b,c));
		e[b].pb(mp(a,c));
	}
	getrt(1,0),rt=1;
	rep(i,2,n)
		if(d[i]>d[rt]) rt=i;
	getrt(rt,0),rt2=1;
	rep(i,2,n)
		if(d[i]>d[rt2]) rt2=i;
	A.rmain(rt),B.rmain(rt2);
	//cerr<<"#"<<rt<<"  "<<rt2<<endl;
	while(Q--){
		read(x),read(y);
		x=(x+ans-1)%n+1;
		y=(y+ans-1)%n+1;
		ans=max(A.solve(x,y),B.solve(x,y));
		printf("%d\n",ans);
	}
	return 0;
}