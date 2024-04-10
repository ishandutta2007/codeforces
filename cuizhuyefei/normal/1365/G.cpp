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
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1<<13|3;
int n,cnt[N],a[N],tot;ll ans[N];
int main() {
	read(n);rep(i,1,1<<13)cnt[i]=cnt[i>>1]+(i&1);
	rep(s,0,1<<13)if(cnt[s]==6&&tot<n)a[++tot]=s;
//	rep(i,1,tot)cerr<<a[i]<<' ';cerr<<endl;
	rep(i,0,12)if(a[tot]>=(1<<i)){
		Vi b;rep(j,1,n)if(a[j]>>i&1)b.pb(j);
		printf("? %d ",SZ(b));for(int x:b)printf("%d ",x);puts("");
		fflush(stdout);read(ans[i]);
	}
	printf("! ");
	rep(i,1,n){
		ll res=0;rep(j,0,12)if(~a[i]>>j&1)res|=ans[j];
		printf("%lld ",res);
	}
	fflush(stdout);
	return 0;
}