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
const int N = 633333;
int tot,ch[N][26],fail[N],endpos[N],val[N];Vi e[N];
inline int merge(int x, int y){
	if(!x||!y)return x+y;endpos[x]+=endpos[y];
	rep(i,0,25)ch[x][i]=merge(ch[x][i],ch[y][i]);
	return x;
}
inline void dfs(int u, int jc){
	val[u]=jc+endpos[u];rep(i,0,SZ(e[u])-1)dfs(e[u][i],val[u]);
}
inline void init(int rt){
	static int q[N];int f=0,r=0;fail[rt]=rt;
	rep(i,0,25)if(ch[rt][i]){int u=ch[rt][i];fail[u]=rt;q[r++]=u;}
	while(f!=r){
		int u=q[f++];
		rep(i,0,25)if(ch[u][i]){
			int v=ch[u][i],x=fail[u];
			while(x!=rt&&!ch[x][i])x=fail[x];
			fail[v]=ch[x][i]?ch[x][i]:x;q[r++]=v;
		}
	}
	rep(i,0,r)e[q[i]].clear();rep(i,0,r-1)e[fail[q[i]]].pb(q[i]);
	dfs(rt,0);
	//printf("rt=%d\n",rt);
	//rep(i,0,r-1)printf("%d->%d\n",q[i],val[q[i]]);
}
struct yzr{
	int rt[33];
	void ins(char *s, int n){
		int rec=++tot,x=rec;rep(i,1,n){ch[x][s[i]-'a']=tot+1;x=++tot;}endpos[x]=1;x=rec;
		for(int i=0;i<30;i++)
			if(rt[i])x=merge(x,rt[i]),rt[i]=0;
			else {rt[i]=x;init(rt[i]);break;}
	}
	ll query(char *s, int n){
		ll res=0;rep(i,0,30)if(rt[i]){//res+=query(rt[i]);
			int now=rt[i];rep(j,1,n){
				int c=s[j]-'a';while(now!=rt[i]&&!ch[now][c])now=fail[now];
				now=ch[now][c]?ch[now][c]:now;res+=val[now];
			}
		}
		return res;
	}
}a,b;
int main() {
	int t;read(t);
	while(t--){
		int op;read(op);static char s[N];
		scanf("%s",s+1);int n=strlen(s+1);
		if(op==1)a.ins(s,n);
		if(op==2)b.ins(s,n);
		if(op==3){printf("%lld\n",a.query(s,n)-b.query(s,n));fflush(stdout);}
	}
	return 0;
}