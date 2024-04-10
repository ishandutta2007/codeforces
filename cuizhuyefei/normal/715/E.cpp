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
const int N = 633,mo=998244353;
int n,ind[N],s1[N][N],C[N][N],nxt[N],pre[N],pos[2][N],a[2][N],dp[N],fac[N];
Vi e[N];bool vis[N];
int qry(int i){return i<=n?a[1][i]:a[2][i-n];}
int main() {
	read(n);
	fac[0]=1;rep(i,1,n)fac[i]=1LL*i*fac[i-1]%mo;
	rep(i,0,n){
		C[i][0]=C[i][i]=1;
		rep(j,1,i-1)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	s1[0][0]=s1[1][1]=1;
	rep(i,2,n)rep(j,1,i)s1[i][j]=(s1[i-1][j-1]+1LL*s1[i-1][j]*(i-1))%mo;
	/*rep(i,1,n){
		rep(j,1,i)printf("%d ",s1[i][j]);puts("");
	}*/
	int __=0,_b=0,a_=0,aa=0;
	rep(i,1,2)rep(j,1,n)read(a[i][j]),pos[i][a[i][j]]=j;
	rep(i,1,n)e[i].pb(n+i);
	rep(j,1,n)if(pos[1][j]&&pos[2][j])e[n+pos[2][j]].pb(pos[1][j]);
	rep(u,1,2*n)rep(i,0,SZ(e[u])-1)ind[e[u][i]]++;
	rep(i,1,2*n)if(!vis[i]&&!ind[i]){
		int x=qry(i),y=qry(i);
		for(int j=i;!vis[j];){
			vis[j]=1;y=qry(j);if(SZ(e[j]))j=e[j][0];else break;
		}
		if(!x&&!y)__++;
		else if(!x&&y)_b++;
		else if(x&&!y)a_++;
	}
	rep(i,1,2*n)if(!vis[i]){
		aa++;
		for(int j=i;!vis[j];){
			vis[j]=1;if(SZ(e[j]))j=e[j][0];else break;
		}
	}
	/*rep(j,1,n)nxt[j]=j,pre[j]=j;
	rep(j,1,n)if(pos[1][j]&&pos[2][j]){
		int x=pos[1][j],y=pos[2][j];
		if(nxt[x]==y&&pre[y]==x){
			aa++;nxt[x]=pre[y]=0;continue;
		}
		nxt[y]=x;pre[x]=y;pre[y]=nxt[x]=0;
	}
	rep(i,1,n)if(nxt[i]){
		if(!a[1][i]&&!a[2][nxt[i]])__++;
		if(!a[1][i]&&a[2][nxt[i]])_b++;
		if(a[1][i]&&!a[2][nxt[i]])a_++;
		if(a[1][i]&&a[2][nxt[i]]&&a[1][i]==a[2][nxt[i]])aa++;
	}*/
//	printf("%d %d %d %d\n",__,_b,a_,aa);
	rep(k,0,min(_b,a_)){
		int c=__+k,a=a_-k,b=_b-k;
		int xs=1LL*(k&1?mo-fac[k]:fac[k])*C[_b][k]%mo*C[a_][k]%mo*fac[__]%mo;
		rep(i,0,a+b+c){
			dp[i]=(dp[i]+1LL*xs*s1[a+b+c][i])%mo;
		//	printf("%d:%d %d\n",k,xs,s1[a+b+c][i]);
		}
	}
	
	rep(i,0,n-1)printf("%d ",n-i-aa>=0?dp[n-i-aa]:0);
	return 0;
}