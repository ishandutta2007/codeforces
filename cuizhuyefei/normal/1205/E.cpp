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
const int N = 266666,mo=1e9+7;
int phi[N],prime[N],len,mrk[N],n,k,f[N],qz[N],res,dp[N],dy[1<<16|3];Vi fac[N];
Vi pr[N];
int gcd(int a, int b){return !b?a:gcd(b,a%b);}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
void getp(int n){
	phi[1]=1;
	rep(i,2,n){
		if(!mrk[i])prime[++len]=i,phi[i]=i-1;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=prime[j];
			if(i%prime[j]==0){phi[i*prime[j]]=phi[i]*prime[j];break;}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
inline int calc(int s, int n){
//	cerr<<s<<' '<<n<<' '<<SZ(pr[s])<<endl;
	int res=0,all=(1<<SZ(pr[s]))-1;
	static int val[1<<16|3],cnt[1<<16|3];
	rep(i,0,SZ(pr[s])-1)dy[1<<i]=i;
	val[0]=1;
	rep(i,1,all){
		val[i]=val[i^(i&-i)]*pr[s][dy[i&-i]];
		cnt[i]=cnt[i>>1]+(i&1);
	}
	rep(s,0,all)res+=(cnt[s]&1?-1:1)*(n/val[s]);
	return res;
}
int calc(int s, int l, int r){
	if(l>r)return 0;
//	cerr<<s<<' '<<l<<' '<<r<<':'<<calc(s,r)-calc(s,l-1)<<endl;
	return (calc(s,r)-calc(s,l-1));
}
int main() {
	read(n);read(k);getp(n*2);
	rep(i,1,n)f[i]=power(k,i),qz[i]=(qz[i-1]+f[i])%mo;
	rep(i,1,len)for(int j=prime[i];j<=n*2;j+=prime[i])pr[j].pb(prime[i]);
//	rep(i,1,n)for(int j=i;j<=n;j+=i)fac[j].pb(i);
//	rep(i,2,n)dp[i]=phi[i]/2;dp[2]=1;
//	rep(i,1,10)cerr<<i<<' '<<phi[i]<<' '<<dp[i]<<endl;
	rep(g,1,n-1){
		/*res=(res+1LL*qz[d]-qz[d-n%d]+mo)%mo;
		int tmp=0;
		rep(i,0,SZ(fac[d])-1)tmp=(tmp+1LL*f[fac[d][i]]*phi[d/fac[d][i]])%mo;
		res=(res+1LL*tmp*(n/d-1))%mo;*/
	//	rep(i,0,d-1)res=(res+1LL*(n/d-1)*f[gcd(i,d)])%mo;
	//	rep(i,0,n%d-1)res=(res+f[d-i])%mo;
		/*rep(i,1,d)
			if(n-i>=d-gcd(d,i))res=(res+f[gcd(d,i)])%mo;
			else res=(res+f[d-(n-i)])%mo;*/
		per(s,n/g*2,1)
			res=(res+1LL*(calc(s,(s+1)/2,min((n-1)/g,s-1)))*f[max(g,g*s-n)])%mo;
	}
	res=2LL*res%mo;rep(d,1,n-1)res=(res-f[d]+mo)%mo;
	res=1LL*res*power(k,mo-1-n)%mo;cout<<res;
	return 0;
}