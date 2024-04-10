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
const int N = 5050;const ll inf=1e18;
int n,s,t,pos[N],a[N],b[N],c[N],d[N];
ll dp[2][N];
int main() {
	read(n);read(s);read(t);
	rep(i,1,n)read(pos[i]);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)read(b[i]);
	rep(i,1,n)read(c[i]);
	rep(i,1,n)read(d[i]);
	rep(i,0,1)rep(j,0,n)dp[i][j]=inf;dp[0][0]=0;
	rep(cur,1,n){
		int p=cur&1,q=p^1;rep(j,0,n)dp[p][j]=inf;
		rep(j,0,n)if(dp[q][j]<inf){
			rep(x,0,1)if(x==0||s!=cur)
				rep(y,0,1)if(y==0||t!=cur)
					if(x<=j-(t<cur)&&y<=j-(s<cur))//&&j-x+(cur!=t)-y>=0&&j-(cur==s)+(cur==t)+(cur!=s)-x>=0)
						umin(dp[p][j-x+1-y],dp[q][j]+(x+y-(cur!=t)+y-(cur!=s)+x)*pos[cur]+x*a[cur]+y*c[cur]+((cur!=t)-y)*d[cur]+((cur!=s)-x)*b[cur]);
		}
		if(cur<n)dp[p][0]=inf;if(cur<n&&cur>=max(s,t))dp[p][1]=inf;
	}
	cout<<dp[n&1][1];
	return 0;
}