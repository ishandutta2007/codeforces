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
const int N = 266666;
int n,fa[N],dep[N],pos[N],dfn[N],idfn[N],num;Vi e[N],ans;
bool cmp(int x, int y){return dep[pos[x]]<dep[pos[y]];}
void dfs1(int u){
	dfn[u]=++num;idfn[num]=u;
	if(u)for(int x=idfn[num-1];x!=fa[u];x=fa[x])ans.pb(u);
	sort(e[u].begin(),e[u].end(),cmp);
	rep(i,0,SZ(e[u])-1){
		dfs1(e[u][i]);
	}
}
int main() {
	read(n);rep(i,1,n-1)read(fa[i]),e[fa[i]].pb(i);
	rep(i,1,n-1)dep[i]=dep[fa[i]]+1;
	rep(i,0,n-1)pos[i]=i;
	per(i,n-1,0)if(dep[pos[i]]>dep[pos[fa[i]]])pos[fa[i]]=pos[i];
	dfs1(0);
	rep(i,1,n)printf("%d ",idfn[i]);puts("");
	printf("%d\n",SZ(ans));rep(i,0,SZ(ans)-1)printf("%d ",ans[i]);
	return 0;
}