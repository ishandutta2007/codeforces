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
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 266666,mo=1e9+7;
int dep[N],val[N],n,m,edge1[N],res=1;vector<Pii>e[N];
bool calc[N],gg[N],mrk[N];Vi cir[N],cur;
void dfs(int u, int Fa, int Dep, int Val){
	dep[u]=Dep;val[u]=Val;//fa[u]=Fa;
//	printf("dfs %d %d %d\n",u,Fa,Dep);
	for(auto v:e[u])if(v.fi!=Fa&&(!mrk[v.fi]||!mrk[u])){
		if(!dep[v.fi])dfs(v.fi,u,Dep+1,Val^v.se);
		else if(v.fi!=Fa&&dep[v.fi]<dep[u])cur.pb(v.se^val[u]^val[v.fi]);
	}
}
void ins(Vi&a, int x, bool &gg){
	per(i,5,0)if(x>>i&1)
		if(!a[i]){a[i]=x;return;}
		else x^=a[i];
	if(!x)gg=1;
}
set<Vi>Set;
map<Vi,int>Map;int tot,trs[444][444];Vi zt[444];
int getid(Vi q){per(i,5,0)per(j,i-1,0)if(q[j]&&(q[i]>>j&1))q[i]^=q[j];return Map[q];}
int dp[444];
int main() {
	rep(a,0,31)rep(b,a+1,31)rep(c,b+1,31)rep(d,c+1,31)rep(e,d+1,31){
		Vi q(6,0);bool f=0;
		ins(q,a,f);ins(q,b,f);ins(q,c,f);ins(q,d,f);ins(q,e,f);
		if(f)continue;
		per(i,5,0)per(j,i-1,0)if(q[j]&&(q[i]>>j&1))q[i]^=q[j];
		Set.insert(q);
	}
	rep(a,0,31)rep(b,a+1,31)rep(c,b+1,31)rep(d,c+1,31){
		Vi q(6,0);bool f=0;
		ins(q,a,f);ins(q,b,f);ins(q,c,f);ins(q,d,f);
		if(f)continue;
		per(i,5,0)per(j,i-1,0)if(q[j]&&(q[i]>>j&1))q[i]^=q[j];
		Set.insert(q);
	}
	rep(a,0,31)rep(b,a+1,31)rep(c,b+1,31){
		Vi q(6,0);bool f=0;
		ins(q,a,f);ins(q,b,f);ins(q,c,f);
		if(f)continue;
		per(i,5,0)per(j,i-1,0)if(q[j]&&(q[i]>>j&1))q[i]^=q[j];
		Set.insert(q);
	}
	rep(a,0,31)rep(b,a+1,31){
		Vi q(6,0);bool f=0;
		ins(q,a,f);ins(q,b,f);
		if(f)continue;
		per(i,5,0)per(j,i-1,0)if(q[j]&&(q[i]>>j&1))q[i]^=q[j];
		Set.insert(q);
	}
	rep(a,0,31){
		Vi q(6,0);bool f=0;
		ins(q,a,f);
		if(f)continue;
		per(i,5,0)per(j,i-1,0)if(q[j]&&(q[i]>>j&1))q[i]^=q[j];
		Set.insert(q);
	}
	Vi qq(6,0);
	Set.insert(qq);
	for(auto x:Set)zt[++tot]=x,Map[x]=tot;
	rep(a,1,tot)rep(b,1,tot){
		Vi c=zt[a];bool gg=0;
		rep(i,0,5)if(!gg&&zt[b][i])ins(c,zt[b][i],gg);
		per(i,5,0)per(j,i-1,0)if(c[j]&&(c[i]>>j&1))c[i]^=c[j];
		if(!gg)trs[a][b]=Map[c];
	}
	cerr<<tot<<endl;
//	for(int x:zt[1])printf("%d ",x);puts("");
	
	
	
	
	read(n);read(m);
	rep(i,1,m){int u,v,w;read(u);read(v);read(w);e[u].pb(Pii(v,w));e[v].pb(Pii(u,w));}
	for(auto v:e[1])mrk[v.fi]=1,edge1[v.fi]=v.se;
	dep[1]=1e9;
	for(auto v:e[1]){
		cur.clear();dfs(v.fi,1,1,v.se);
		cir[v.fi].resize(6);for(int x:cur)ins(cir[v.fi],x,gg[v.fi]);
	//	for(int x:cur)printf("%d:%d\n",v.fi,x);
	}
	dp[1]=1;
	rep(u,1,n)for(auto v:e[u])if(mrk[u]&&mrk[v.fi]&&u<v.fi){
		assert(!calc[u]&&!calc[v.fi]);
		gg[u]|=gg[v.fi];gg[v.fi]|=gg[u];
		calc[u]=calc[v.fi]=1;
		Vi zy={1};
		int cur=1;//+(!gg[u])+(!gg[v.fi]);
		if(!gg[u]&&!gg[v.fi]){
			rep(i,0,5)if(cir[v.fi][i])ins(cir[u],cir[v.fi][i],gg[u]);
			if(!gg[u])zy.pb(getid(cir[u])),zy.pb(getid(cir[u]));
			ins(cir[u],edge1[u]^edge1[v.fi]^v.se,gg[u]);
		//	rep(i,0,5)if(cir[u][i])printf("qwq %d %d\n",cir[u][i],getid(cir[u]));
			if(!gg[u])zy.pb(getid(cir[u]));
		}
		static int dp1[444];memset(dp1,0,sizeof(dp1));
		rep(i,1,tot)if(dp[i])for(int j:zy)
			dp1[trs[i][j]]=(dp1[trs[i][j]]+dp[i])%mo;
		memcpy(dp,dp1,sizeof(dp1));
	}
	rep(u,1,n)if(mrk[u]&&!calc[u]&&!gg[u]){
		Vi zy={1,getid(cir[u])};
		static int dp1[444];memset(dp1,0,sizeof(dp1));
		rep(i,1,tot)if(dp[i])for(int j:zy)
			dp1[trs[i][j]]=(dp1[trs[i][j]]+dp[i])%mo;
		memcpy(dp,dp1,sizeof(dp1));
	}
	res=0;rep(i,1,tot)res=(res+dp[i])%mo;
	cout<<res;
	return 0;
}