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
int n,a[N],s[N],dfn[N];
int main() {
	int T;read(T);while(T--){
		read(n);
		rep(i,1,n){read(a[i]);a[i]=i-a[i];}
		rep(i,1,n)s[i]=dfn[i]=0;int len=0;
		for(int u=1;;){
			s[++len]=u;dfn[u]=len;
			if(!dfn[a[u]])u=a[u];
			else{
				printf("%d\n",dfn[u]-dfn[a[u]]+1);
				rep(i,dfn[a[u]],dfn[u])printf("%d ",s[i]);puts("");
				break;
			}
		}
	}
	return 0;
}