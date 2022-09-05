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
const int N = 1202000;const ll inf = 1e17;
int n,all,id[N],e[N],vis[1<<11|3];ll k,a[N],p[N],m,dp[12][1<<11|3],lst[12][1<<11|3],cnt[1<<11|3];
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
bool cmp(int a, int b){return e[a]<e[b];}
map<ll,int>Map;
inline void solve(int s, int cost){
	rep(i,0,m-1)for(int j=all^s;;j=(j-1)&(all^s)){
		umin(dp[i+1][j|s],lst[i][j]+cost);if(!j)break;
	}
	//rep(j,0,all)umin(dp[i+1][j|s],lst[i][j]+cost);
}
int main() {
	read(n);read(k);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)read(e[i]);
	ll g=0;rep(i,1,n)g=gcd(g,a[i]);
	for(int i=2;1LL*i*i<=g;i++)if(g%i==0){
		p[++m]=i;while(g%i==0)g/=i;
	}
	if(g>1)p[++m]=g;all=(1<<m)-1;
	rep(i,1,all)cnt[i]=cnt[i>>1]+(i&1);
	if(!m){puts("0");return 0;}
	rep(i,1,n){
		ll x=1;
		rep(j,1,m)while(a[i]%p[j]==0)a[i]/=p[j],x*=p[j];
		a[i]=x;
	}
	rep(i,1,n)id[i]=i;
	sort(id+1,id+n+1,cmp);
	rep(i,0,m)rep(j,0,all)dp[i][j]=inf;dp[0][0]=0;
	rep(t,1,n){
		int cost=e[id[t]];if(Map[a[id[t]]]>=m)continue;
		Map[a[id[t]]]++;ll b[13],c[1<<11|3];c[0]=1;
		rep(i,1,m){
			b[i]=1;while(a[id[t]]%p[i]==0)a[id[t]]/=p[i],b[i]*=p[i];
			c[1<<i-1]=b[i];
		}
		bool trans=0;
		rep(i,1,all){
			if((i&-i)^i)c[i]=c[i&-i]*c[i^(i&-i)];
			if(c[i]<=k&&vis[i]<m-cnt[i]+1){
			//	printf("%d %d %d\n",cost,i,m);
				vis[i]++;if(!trans)memcpy(lst,dp,sizeof(dp)),trans=1;
				solve(i,cost);
			}
		}
	}
	ll res=inf;rep(i,1,m)umin(res,dp[i][all]*i);
	cout<<(res<inf?res:-1);
	return 0;
}