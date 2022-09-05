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
typedef pair<ll,ll> Pll;
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
const int N = 7777;
int q[N],f,r,n;ll res;Pll s[N];bool vis[N];
int main() {
	read(n);
	rep(i,1,n)read(s[i].fi);
	rep(i,1,n)read(s[i].se);
	sort(s+1,s+n+1);
	rep(i,1,n){
		int j=i;for(;j<=n;j++)if(s[j].fi!=s[i].fi)break;
		if(j-i>1){rep(k,i,j-1)vis[k]=1,q[r++]=k;}i=j-1;
	}
	while(f!=r){
		int u=q[f++];
		rep(i,1,n)if(!vis[i]&&(s[i].fi&s[u].fi)==s[i].fi)
			q[r++]=i,vis[i]=1;
	}
	rep(i,1,n)if(vis[i])res+=s[i].se;cout<<res;
	return 0;
}