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
const int N = 102000;
ll T;int mo;map<ll,int>Map;
ll a[N];int sz,n,S[N],m;
struct mtr{
	int a[2][2];
	mtr(){memset(a,0,sizeof(a));}
}mi[63][50500];
inline mtr mul(const mtr &a, const mtr &b){
	mtr c;
	rep(i,0,1)rep(j,0,1)rep(k,0,1)c.a[i][k]=(c.a[i][k]+1LL*a.a[i][j]*b.a[j][k])%mo;
	return c;
}
inline void updans(int *ans, ll s, ll T){
	if(T<=0)return;
//	printf("qwq %lld %lld\n",s,s+T-1);
	s%=n;
	for(int i=0;i<=60&&T;i++)if(T>>i&1){
		int x=(1LL*mi[i][s].a[0][0]*ans[0]+1LL*mi[i][s].a[0][1]*ans[1])%mo;
		int y=(1LL*mi[i][s].a[1][0]*ans[0]+1LL*mi[i][s].a[1][1]*ans[1])%mo;
		ans[0]=x;ans[1]=y;
		T-=1ll<<i;s=(s+(1ll<<i))%n;
	}
}
inline int qrys(ll x){return Map.count(x)?Map[x]:S[x%n];}
int main() {
	read(T);read(mo);
	if(!T){puts("0");return 0;}
	read(n);rep(i,0,n-1)read(S[i]);
	read(m);rep(i,1,m){ll x,y;read(x);read(y);Map[x]=y;a[++sz]=x+1;a[++sz]=x+2;}
	sort(a+1,a+sz+1);sz=unique(a+1,a+sz+1)-a-1;
	while(sz&&a[sz]>T)sz--;a[++sz]=T+1;
	rep(j,0,n-1){
		mtr s;s.a[1][0]=1;s.a[1][1]=0;s.a[0][0]=S[(j-1+n)%n];s.a[0][1]=S[(j-2+n+n)%n];
		mi[0][j]=s;
	}
	rep(i,1,60)rep(j,0,n-1)mi[i][j]=mul(mi[i-1][(j+(1ll<<i-1))%n],mi[i-1][j]);
	int ans[2]={0};ans[0]=1;updans(ans,2,a[1]-2);
	rep(i,1,sz-1){
	//	printf("QAQ %lld\n",a[i]);
		mtr s;s.a[1][0]=1;s.a[1][1]=0;s.a[0][0]=qrys(a[i]-1);s.a[0][1]=qrys(a[i]-2);
		ll x=(1LL*s.a[0][0]*ans[0]+1LL*s.a[0][1]*ans[1])%mo;
		ll y=(1LL*s.a[1][0]*ans[0]+1LL*s.a[1][1]*ans[1])%mo;
		ans[0]=x;ans[1]=y;
		updans(ans,a[i]+1,a[i+1]-a[i]-1);
	}
	cout<<ans[0]%mo<<endl;
	return 0;
}