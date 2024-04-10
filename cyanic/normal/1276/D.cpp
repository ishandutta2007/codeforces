#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
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
const int mod=998244353;
namespace{
	void add(int &x,int y){
		x=(x+y>=mod?x+y-mod:x+y);
	}
	int fix(int x){
		return x>=mod?x-mod:x;
	}
	int mul(int x,int y){
		return (ll)x*y%mod;
	}
}
int f[N],g[N],h[N],n,a,b;
vector<pii> e[N];

void dfs(int u,int fa,int x){
	vector<pii> sn;
	sn.pb(mp(0,0));
	for(auto v:e[u]){
		if(v.fi==fa) continue;
		dfs(v.fi,u,v.se);
		sn.pb(v);
	}
	int m=(int)sn.size()-1;
	vi pre,suf;
	pre.resize(m+2);
	suf.resize(m+2);
	pre[0]=1;
	rep(i,1,m){
		int x=sn[i].fi;
		pre[i]=mul(pre[i-1],fix(f[x]+g[x]));
	}
	suf[m+1]=1;
	per(i,m,1){
		int x=sn[i].fi;
		suf[i]=mul(suf[i+1],fix(f[x]+h[x]));
	}
	g[u]=1;
	rep(i,1,m){
		int p=sn[i].fi,y=sn[i].se;
		if(y<x){
			g[u]=mul(g[u],fix(f[p]+g[p]));
			add(f[u],mul(h[p],mul(pre[i-1],suf[i+1])));
		}
		else{
			g[u]=mul(g[u],fix(f[p]+h[p]));
			add(h[u],mul(h[p],mul(pre[i-1],suf[i+1])));
		}
	}
	add(h[u],pre[m]);
//	printf("@ %d %d %d %d\n",u,f[u],g[u],h[u]);
}

int main(){
	read(n);
	rep(i,1,n-1){
		read(a),read(b);
		e[a].pb(mp(b,i));
		e[b].pb(mp(a,i));
	}
	dfs(1,0,n);
	cout<<fix(f[1]+g[1])<<endl;
	return 0;
}