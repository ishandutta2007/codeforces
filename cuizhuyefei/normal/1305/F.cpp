#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
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
mt19937 R(chrono::system_clock().now().time_since_epoch().count());
const int N = 1e6+11;
int n,prime[N],len,mrk[N];ll a[N],res;
void getp(int n){
	rep(i,2,n){
		if(!mrk[i])prime[++len]=i;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
void solve(ll x){
	ll ans=0;for(int i=1;i<=n&&ans<res;i++){ll y=a[i]%x;ans+=a[i]<x?x-a[i]:min(y,x-y);}
	umin(res,ans);
}
void test(ll x){
	rep(i,1,len)if(x%prime[i]==0){
		solve(prime[i]);while(x%prime[i]==0)x/=prime[i];
	}
	if(x>1)solve(x);
}
int main() {
	auto stt=clock();
	getp(N-1);cerr<<len<<endl;
	read(n);rep(i,1,n)read(a[i]),res+=a[i]%2;
	while(1.0*(clock()-stt)/CLOCKS_PER_SEC<0.5){
		int x=R()%n+1,y=R()%n+1;
		while(x==y)y=R()%n+1;
		rep(i,-1,1)rep(j,-1,1)if(a[x]+i>0&&a[y]+j>0)test(gcd(a[x]+i,a[y]+j));
	}
	
	cout<<res;
	return 0;
}