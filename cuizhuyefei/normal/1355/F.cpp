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
typedef pair<ll,ll> Pll;
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

const int N = 1e5+11;
int n,prime[N],len,mrk[N];
void getp(int n){
	rep(i,2,n){
		if(!mrk[i])prime[++len]=i;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
}
int deb;
ll qry(ll x){
	deb++;
	printf("? %lld\n",x);fflush(stdout);
	ll y;read(y);return y;
}
ll power(ll a, int n){ll res=1;while(n--)res*=a;return res;}
int main() {
	static int q[N];
	getp(1e3);
	int t;read(t);while(t--){
		deb=0;int lim=1e9;map<int,int>Map;
		rep(i,1,len)q[i]=prime[i];
		int f=1,r=len;ll ans=1;
		while(f<=r&&deb<22){
		//	if(lim==1e9&&1ll*q[f]*q[f]*q[f]*q[f]>lim)break;
		//	if(f==r&&)
		//	if(1ll*q[f]*q[f]*q[f]>lim)break;
		//	if(r-f+1>=3&&1ll*q[f]*q[f+1]*q[f+2]>lim)break;
			ld cur=1;
			ll zs=1;
			int j=f-1;while(j+1<=r&&cur*(Map.count(q[j+1])?power(q[j+1],Map[q[j+1]]+1):q[j+1])<=1e18)
				cur*=(Map.count(q[j+1])?power(q[j+1],Map[q[j+1]]+1):q[j+1]),zs*=(Map.count(q[j+1])?power(q[j+1],Map[q[j+1]]):1),j++;
			ll x=qry(cur+0.5)/zs;
			int i=f;f=j+1;Vi a;
			rep(k,i,j)if(x%q[k]==0)a.pb(q[k]),Map[q[k]]++;
			for(int x:a)q[--f]=x,lim/=x;
		}
		ll res=2;for(auto i:Map)res*=i.se+1;
		printf("! %lld\n",res);fflush(stdout);
	}
	/*getp(1e3);cerr<<len<<endl;
	rep(i,1,len)q[i]=prime[i];
	ll cnt=0;
	rep(i,1,len){
		ld cur=1;
		int j=i-1;while(j+1<=len&&cur*q[j+1]<=1e18)
			cur*=q[j+1],j++;
		i=j;cnt++;cerr<<cur<<endl;
	}
	cerr<<cnt<<endl;*/
	return 0;
}