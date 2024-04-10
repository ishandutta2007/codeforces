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
const int N = 300300;
int n,q,a[N],ans[N];vector<Pii> que[N];
int b[19*19/2][N],top[19*19/2],bh[19][19],num;
bool dp[19][N];
int main() {
	read(n);read(q);rep(i,1,n)read(a[i]);
	rep(i,1,q){
		int x,y;read(x);read(y);
		que[x].pb(Pii(y,i));
	}
	rep(i,0,18)rep(j,i+1,18)bh[i][j]=bh[j][i]=++num;
	
	per(tt,n,1){
		int x=a[tt];vector<Pii> cur;
		rep(i,0,18)if(x>>i&1)rep(j,i+1,18)if(x>>j&1)while(top[bh[i][j]]){
			int u=b[bh[i][j]][top[bh[i][j]]--];
			if(!dp[i][u])cur.pb(Pii(i,u)),dp[i][u]=1;
			if(!dp[j][u])cur.pb(Pii(j,u)),dp[j][u]=1;
		}
		rep(i,0,18)if(x>>i&1)dp[i][tt]=1,cur.pb(Pii(i,tt));
		for(auto c:cur){
			rep(i,0,18)if(!dp[i][c.se])b[bh[i][c.fi]][++top[bh[i][c.fi]]]=c.se;
		}
		for(auto c:que[tt])rep(i,0,18)if(x>>i&1)ans[c.se]|=dp[i][c.fi];
	}
	rep(i,1,q)printf("%s\n",ans[i]?"Shi":"Fou");
	return 0;
}