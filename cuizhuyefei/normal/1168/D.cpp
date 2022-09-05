#include<bits/stdc++.h>
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 266666;
int n,q,fa[N],dep[N],tp[N],g[N],top[N],bel[N],mx;Vi e[N];
int dp[N][27],gg,chain[N][27],coef[N];Vi f[N][27];
int Get(){
	char s[6];scanf("%s",s);
	if(s[0]=='?')return 0;
	return s[0]-'a'+1;
}
void GG(){while(q--)puts("Fou");exit(0);}
void dfs1(int u){
	for(int v:e[u])dfs1(v);
	g[u]=SZ(e[u])>1;
	if(e[u].empty()){g[u]=1;if(dep[u]!=mx)GG();}
}
void dfs2(int u, int Top){
	if(g[u])top[u]=Top,Top=u;
	if(g[u])bel[u]=u;
	else assert(SZ(e[u])==1);
	for(int v:e[u]){
		dfs2(v,Top);
		if(!g[u]&&bel[v])bel[u]=bel[v];
	}
}
void ini(int u){
	for(int v:e[u])ini(v);
	for(int v:e[u])rep(i,1,26)f[u][i].pb(dp[v][i]);
	rep(i,1,26){sort(ALL(f[u][i]));if(SZ(f[u][i]))dp[u][i]+=f[u][i].back();}
	int tot=0;rep(i,1,26)tot+=dp[u][i]-chain[u][i];
	gg+=tot>mx-dep[u];coef[u]=tot;
}
inline void mdy(int u, int c, int xs){
	u=bel[u];chain[u][c]+=xs;dp[u][c]+=xs;
	for(;u>1;u=top[u]){
		int rec=dp[top[u]][c];dp[top[u]][c]-=f[top[u]][c].back();
		if(xs<0){
			(*lower_bound(ALL(f[top[u]][c]),dp[u][c]-xs))--;
		}
		else{
			(*(upper_bound(ALL(f[top[u]][c]),dp[u][c]-xs)-1))++;
		}
		dp[top[u]][c]+=f[top[u]][c].back();
		if(rec==dp[top[u]][c])break;
		gg-=coef[top[u]]>mx-dep[top[u]];
		coef[top[u]]+=dp[top[u]][c]-rec;
		gg+=coef[top[u]]>mx-dep[top[u]];
	}
}
int main() {
	read(n);read(q);
	rep(i,2,n){
		read(fa[i]);tp[i]=Get();dep[i]=dep[fa[i]]+1;
		e[fa[i]].pb(i);
	}
	mx=dep[n];
	dfs1(1);g[1]=1;dfs2(1,0);
	rep(i,1,n)e[i].clear();
	rep(i,1,n)if(g[i])e[top[i]].pb(i);//,printf("%d: %d\n",i,top[i]);
	rep(i,2,n)if(tp[i])dp[bel[i]][tp[i]]++,chain[bel[i]][tp[i]]++;
	ini(1);
	while(q--){
		int u,t;read(u);t=Get();
		if(tp[u])mdy(u,tp[u],-1);
		tp[u]=t;if(tp[u])mdy(u,tp[u],1);
		if(gg)puts("Fou");
		else{
			int spare=mx;
			rep(i,1,26)spare-=dp[1][i];
			assert(spare>=0);
			ll res=0;
			rep(i,1,26)res=(res+1ll*i*(spare+dp[1][i]));
			printf("Shi %lld\n",res);
		}
	}
	return 0;
}