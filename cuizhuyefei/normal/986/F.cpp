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
typedef pair<ll,int> Pli;
typedef vector<ll> Vl;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 102000;const ll inf = 3e18;
int prime[4000000],len;ll dis[N];map<ll,int>Map;int num;ll rec[75][N];
bool isprime(int x){
	for(int i=2;i*i<=x;i++)if(x%i==0)return 0;return 1;
}
void getp(int n){
	static int small[10000];static bool vis[10000];
	int sz=0,S=sqrt(n)+0.5;
	rep(i,2,S)if(isprime(i))small[++sz]=i,prime[++len]=i;
	for(int l=S+1;l<=n;l+=S){
		memset(vis,0,sizeof(vis));int r=min(n,l+S-1);
		rep(i,1,sz)for(register int j=r/small[i]*small[i];j>=l;j-=small[i])vis[j-l]=1;
		rep(i,0,S-1)if(!vis[i])prime[++len]=l+i;
	}
}
inline Vl getfac(ll n){
	static map<ll,Vl>Map;ll rec=n;
	if(Map.count(n))return Map[n];
	Vl res;
	for(register int i=1;i<=len&&1LL*prime[i]*prime[i]<=n;i++)if(n%prime[i]==0){
		res.pb(prime[i]);while(n%prime[i]==0)n/=prime[i];
	}
	if(n>1)res.pb(n);return Map[rec]=res;//WA
}
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
inline void exgcd(ll a, ll b, ll &x, ll &y){
	if(!b){x=1;y=0;return;}
	exgcd(b,a%b,y,x);y-=a/b*x;
}
inline ll mul(ll a, ll b, ll mo){
	ll res=0;
	while(b){
		if(b&1)res=(res+a)%mo;a=(a+a)%mo;b>>=1;
	}
	return res;
}
inline bool ckeq(ll c, ll a, ll b){
	ll g=gcd(a,b);if(c%g)return 0;a/=g;b/=g;c/=g;
	ll x,y;exgcd(a,b,x,y);x=mul(x,c,b);x=(x+b)%b;return c-a*x>=0;//WA
}
int main(){
	getp(35000000);int T;read(T);
	while(T--){
		ll nn,k;scanf("%lld%lld",&nn,&k);
		Vl s=getfac(k);
		if(k==1)puts("NO");
		else if(SZ(s)==1)printf("%s\n",nn%s[0]==0?"YES":"NO");
		else if(SZ(s)==2)printf("%s\n",ckeq(nn,s[0],s[1])?"YES":"NO");
		else {
		if(!Map.count(k)){
			priority_queue<Pli,vector<Pli>,greater<Pli> >heap;int n=s[0];
			rep(i,0,n-1)dis[i]=inf;dis[0]=0;heap.push(Pli(dis[0],0));
			while(!heap.empty()){
				int u=heap.top().se;if(heap.top().fi!=dis[u]){heap.pop();continue;}heap.pop();
				rep(i,1,SZ(s)-1){
					int v=(u+s[i])%n;ll d=dis[u]+s[i];
					if(d<dis[v]){dis[v]=d;heap.push(Pli(d,v));}
				}
			}
			Map[k]=++num;rep(i,0,s[0]-1)rec[num][i]=dis[i];
		}
		assert(num<=50);
			printf("%s\n",rec[Map[k]][nn%s[0]]<=nn?"YES":"NO");
		}
	}
	return 0;
}