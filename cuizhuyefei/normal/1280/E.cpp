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
const int N = 2666666;
int qz[N],r,n,bh[N],lim;char s[N];set<int>Set[N];
Vi e[N];int mrk[N],dp[N];Vi fangan;ll ans[N];
int build(int l, int r){
	if(l==r){return bh[l];}
//	printf("build %d %d\n",l,r);
	assert(s[l]=='('&&s[r]==')');//l++;r--;
	Vi pos;set<int>::iterator it=Set[qz[l]].lower_bound(l),it1;
	while(it!=Set[qz[l]].end()&&(*it)<=r){
		pos.pb(*it);it1=it;it++;Set[qz[l]].erase(it1);
	}
	int u=++lim;e[u].clear();mrk[u]=s[pos[0]]=='P';
	e[u].pb(build(l+1,pos[0]-1));
	rep(i,0,SZ(pos)-2)e[u].pb(build(pos[i]+1,pos[i+1]-1));
	e[u].pb(build(pos.back()+1,r-1));
	return u;
}
void getfangan(int u){
	if(e[u].empty()){fangan.pb(u);return;}
	rep(i,0,SZ(e[u])-1){
		if(mrk[u]==1)getfangan(e[u][i]);
		else if(dp[u]==dp[e[u][i]]){
			getfangan(e[u][i]);return;
		}
	}
}
void dfs(int u){
	if(e[u].empty()){dp[u]=1;return;}
	if(mrk[u]==1)dp[u]=0;else dp[u]=1e9;
	rep(i,0,SZ(e[u])-1){
		dfs(e[u][i]);
		if(mrk[u]==1)dp[u]+=dp[e[u][i]];else umin(dp[u],dp[e[u][i]]);
	}
}
int main() {
	int T;read(T);while(T--){
		read(r);gets(s+1);n=strlen(s+1);
		int m=0;rep(i,1,n)if(s[i]!=' ')s[++m]=s[i];n=m;
		rep(i,1,n)qz[i]=qz[i-1]+(s[i]=='('?1:(s[i]==')'?-1:0));
		
//		rep(i,1,n)printf("%c",s[i]);puts("");
		rep(i,0,n)Set[i].clear(),e[i].clear(),mrk[i]=0;
		rep(i,1,n)if(s[i]=='P'||s[i]=='S')Set[qz[i]].insert(i);
		int tot=0;rep(i,1,n){bh[i]=0;if(s[i]=='*')bh[i]=++tot;}
		lim=tot;
		int rt=build(1,n);dfs(rt);
		rep(i,1,tot)ans[i]=0;fangan.clear();getfangan(rt);
		assert(SZ(fangan)==dp[rt]);
		rep(i,0,SZ(fangan)-1)ans[fangan[i]]=1ll*r*SZ(fangan);
		printf("REVOLTING ");rep(i,1,tot)printf("%lld ",ans[i]);puts("");
	}
	return 0;
}