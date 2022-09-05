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
const int N = 166666;
int n,a[N],fa[N],ch[N][2],sz[N],tot,rt;ll lzy[N],val[N],s[N],len;
inline bool getid(int k){return ch[fa[k]][1]==k;}
inline void upd(int k){sz[k]=sz[ch[k][0]]+sz[ch[k][1]]+1;}
inline void pushadd(int k, ll x){val[k]+=x;lzy[k]+=x;}
inline void pushdown(int k){
	if(lzy[k])pushadd(ch[k][0],lzy[k]),pushadd(ch[k][1],lzy[k]),lzy[k]=0;
}
inline void rotate(int x){
	int y=fa[x],z=fa[y],k=getid(x),c=ch[x][k^1];
	if(rt==y)rt=x;
	fa[x]=z;ch[z][getid(y)]=x;
	fa[c]=y;ch[y][k]=c;
	fa[y]=x;ch[x][k^1]=y;
	upd(y);upd(x);
}
inline void splay(int x){
	static int sta[N];int top=0;
	for(int u=x;u;u=fa[u])sta[++top]=u;
	while(top)pushdown(sta[top--]);
	while(x!=rt){
		int y=fa[x];
		if(y==rt){rotate(x);break;}
		if(getid(x)==getid(y))rotate(y);else rotate(x);
		rotate(x);
	}
}
void print(int u){
	pushdown(u);if(ch[u][0])print(ch[u][0]);
	s[++len]=val[u];if(ch[u][1])print(ch[u][1]);
}
int main() {
	read(n);rep(i,1,n)read(a[i]);
	tot++;rt=tot;
	rep(t,1,n){
		int u=rt,zuo=0,A=a[t],pos=0,lst=u,p=0;
		while(u){
			pushdown(u);lst=u;
			if(val[u]<1LL*(zuo+sz[ch[u][0]])*A)pos=u,p=zuo+sz[ch[u][0]],u=ch[u][0];
			else zuo+=sz[ch[u][0]]+1,u=ch[u][1];
		}
		if(!pos){//end
			ch[lst][1]=++tot;fa[tot]=lst;val[tot]=1LL*zuo*A;splay(tot);
		}
		else{
			int x=ch[pos][0];ch[pos][0]=++tot;val[tot]=1LL*p*A;fa[tot]=pos;
			ch[tot][0]=x;fa[x]=tot;splay(tot);pushadd(ch[tot][1],A);
		}
	}
	print(rt);
	ll res=0,qz=0;rep(i,1,len)qz+=s[i],umax(res,qz);cout<<res;
	return 0;
}