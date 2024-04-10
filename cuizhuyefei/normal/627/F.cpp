#include<bits/stdc++.h>
#define fi first
#define se second
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
void GG(){puts("-1");exit(0);}
const int N = 266666;
int n,a[N],b[N],ori[N],fa[N],dep[N],A,B,now;Vi e[N];
void dfs1(int u, int Fa, int Dep){
	dep[u]=Dep;fa[u]=Fa;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=Fa)
		dfs1(e[u][i],u,Dep+1);
}
namespace CHECK{
	int rt,fa[N],dep[N],cnt,cnte,s[N],len;
	void dfs1(int u, int Fa, int Dep){
		dep[u]=Dep;fa[u]=Fa;
		cnt+=a[u]!=b[u];if(Fa)cnte+=a[u]!=b[u]&&a[Fa]!=b[Fa];
		if(a[u]!=b[u])s[++len]=u;
		rep(i,0,SZ(e[u])-1)if(e[u][i]!=Fa)
			dfs1(e[u][i],u,Dep+1);
	}
	bool cmp(int x, int y){return dep[x]<dep[y];}
	void solve(){
		rep(i,1,n)if(!a[i])rt=i;assert(!b[rt]);
		dfs1(rt,0,0);
		if(cnt==0){printf("0 %d\n",now);exit(0);}
		if(cnt-cnte>2)GG();
		sort(s+1,s+len+1,cmp);
		if(cnt-cnte==1){
			A=fa[s[1]];B=s[len];
		}
		else{
			A=s[len];static bool vis[N];
			for(int u=A;u;u=fa[u])vis[u]=1;
			per(i,len,1)if(!vis[s[i]]){B=s[i];break;}
		}
	}
}
int main() {
	read(n);rep(i,1,n)read(a[i]);rep(i,1,n)read(b[i]);
	rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	rep(i,1,n)ori[i]=a[i];
	int rt=0;rep(i,1,n)if(!a[i])rt=i;
	dfs1(rt,0,0);int des=0;rep(i,1,n)if(!b[i])des=i;
	Vi ss;for(int u=des;u!=rt;u=fa[u])ss.pb(u);
	per(i,SZ(ss)-1,0)swap(a[ss[i]],a[fa[ss[i]]]),now++;
	CHECK::solve();
	if(A>B)swap(A,B);cerr<<A<<' '<<B<<endl;
	rep(i,1,n)a[i]=ori[i];
	dfs1(A,0,0);now=0;
	static bool incir[N];for(int u=B;u;u=fa[u])incir[u]=1;
	int p=0;rep(i,1,n)if(!a[i])p=i;
	while(!incir[p])swap(a[p],a[fa[p]]),p=fa[p],now++;int start=p;
	p=0;rep(i,1,n)if(!b[i])p=i;
	while(!incir[p])swap(b[p],b[fa[p]]),p=fa[p],now++;
	static int pos[N],s[N];int len=0;
	for(int u=start;u;u=fa[u])pos[a[u]]=len++;
	for(int u=B;u!=start;u=fa[u])pos[a[u]]=len++;
	len=0;for(int u=start;u;u=fa[u])s[++len]=pos[b[u]];
	for(int u=B;u!=start;u=fa[u])s[++len]=pos[b[u]];
	assert(len==dep[B]-dep[A]+1);p=0;rep(i,1,len)if(!s[i])p=i;
	static int t[N];int sz=0;rep(i,1,len)if(s[i])t[++sz]=s[i];
	rep(i,1,sz)if((t[i]+1-t[i+1<=sz?i+1:1])%sz)GG();
	ll ans=!s[1]?1LL*(s[2]-1)*len:1LL*(s[1]-1)*len+p-1;
	/*for(int u=B;u;u=fa[u])cerr<<u<<' ';cerr<<endl;
	rep(i,1,n)cerr<<a[i]<<' ';cerr<<endl;
	rep(i,1,n)cerr<<b[i]<<' ';cerr<<endl;*/
	rep(i,1,n)if(!incir[i]&&a[i]!=b[i])GG();
//	rep(i,1,len)cerr<<s[i]<<' ';cerr<<endl;
	printf("%d %d %lld\n",A,B,now+min(ans,1LL*len*(len-1)-ans));
	return 0;
}