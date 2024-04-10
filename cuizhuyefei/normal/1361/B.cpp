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

const int N = 1e6+111,inf=2e6,mo=1e9+7;
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
int n,p,a[N],mi[N];
int qry(int i){return power(p,a[i]);}
int main() {
	int T;read(T);while(T--){
		read(n);read(p);rep(i,1,n)read(a[i]);
		if(p==1){printf("%d\n",n&1);continue;}
		sort(a+1,a+n+1);int pos=n,res=0,cur=0;
		mi[0]=1;rep(i,1,40)mi[i]=min(1ll*mi[i-1]*p,1ll*inf);
		per(i,n,1){
			int j=i;while(j-1>=1&&a[j-1]==a[i])j--;
			if(i<n)cur=min(1ll*cur*(a[i+1]-a[i]<=40?mi[a[i+1]-a[i]]:inf),1ll*inf);
			int a=0;
			while(a+cur<i-j+1-a)a++;
		//	cerr<<"qwq "<<a<<endl;
			cur=a+cur-(i-j+1-a);
			res=(res+1ll*a*qry(i)-1ll*(i-j+1-a)*qry(i))%mo;
			i=j;
		}
		res=(res+mo)%mo;
		printf("%d\n",res);
	}
	return 0;
}