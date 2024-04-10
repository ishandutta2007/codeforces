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
int n,m,res=-1;Vi e[N];bool vis[N];
int s[N],len,dfn[N],t[N],newsz;
int main() {
	read(n);read(m);
	rep(i,1,m){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	rep(i,2,n)s[++len]=i;
	rep(S,1,n)if(!vis[S]){
		res++;
		static int q[N];int f=0,r=1;q[f]=S;vis[S]=1;
		while(f!=r){
			int u=q[f++];
			rep(i,0,SZ(e[u])-1)dfn[e[u][i]]=u;newsz=0;
			rep(i,1,len)if(!vis[s[i]]&&dfn[s[i]]==u)t[++newsz]=s[i];
			else if(!vis[s[i]])q[r++]=s[i],vis[s[i]]=1;
			len=newsz;rep(i,1,len)s[i]=t[i];
		}
	}
	cout<<res;
	return 0;
}