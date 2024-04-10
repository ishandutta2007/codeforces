#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
template<class T> inline T Abs(const T &x){return x>0?x:-x;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1e5+11,mo=998244353;
int sg[N],n,m,sta[N],cnt[N],deg[N],top,s[N],len,val[N];Vi e[N];bool vis[N];

int b[1<<9|3],a[1<<9|3][1<<9|3];
void add(int &x,int y){x=(x+y)%mo;}
int power(int a, int n){
	int res=1;
	while(n){
		if(n&1)res=1ll*res*a%mo;
		a=1ll*a*a%mo;n>>=1;
	}
	return res;
}
void gauss(int n){//a[0..n][0..n],b[0..n]
	rep(i,0,n){
		if(!a[i][i])rep(j,i+1,n)if(a[j][i]){
			rep(k,0,n)swap(a[i][k],a[j][k]);swap(b[i],b[j]);
			break;
		}
		int ni=power(a[i][i],mo-2);
		rep(j,0,n)a[i][j]=1ll*a[i][j]*ni%mo;b[i]=1ll*b[i]*ni%mo;
		rep(j,0,n)if(a[j][i]&&j!=i){
			int xs=a[j][i];
			rep(k,0,n)a[j][k]=(a[j][k]+1ll*a[i][k]*(mo-xs))%mo;
			b[j]=(b[j]+1ll*b[i]*(mo-xs))%mo;
		}
	}
}
int main() {
	read(n);read(m);
	while(m--){
		int u,v;read(u);read(v);e[u].pb(v);deg[v]++;
	}
	rep(i,1,n)if(!deg[i])sta[++top]=i;
	while(top){
		int u=sta[top--];s[++len]=u;
		for(int v:e[u])if(!--deg[v])
			sta[++top]=v;
	}
	per(t,len,1){
		int u=s[t];
		for(int v:e[u])vis[sg[v]]=1;
		for(;vis[sg[u]];sg[u]++);
		for(int v:e[u])vis[sg[v]]=0;
	}
	m=0;per(i,n,1)umax(m,sg[i]),cnt[sg[i]]++;
	rep(i,0,n)val[i]=1ll*cnt[i]*power(n+1,mo-2)%mo;
	rep(i,0,30)if((1<<i)>m){m=i;break;}
	b[0]=mo-1;
	rep(i,0,(1<<m)-1)rep(j,0,(1<<m)-1)add(a[i][j],val[i^j]);
	rep(i,0,(1<<m)-1)add(a[i][i],mo-1);
	gauss((1<<m)-1);
	cout<<(1+mo-1ll*b[0]*power(n+1,mo-2)%mo)%mo;
	return 0;
}