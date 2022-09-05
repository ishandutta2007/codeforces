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
const int N = 303000;
int n,cnt[N],a[N],mu[N],prime[N],len,mrk[N];
void getp(int n){
	mu[1]=1;
	rep(i,2,n){
		if(!mrk[i])prime[++len]=i,mu[i]=-1;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;mu[i*prime[j]]=-mu[i];
		}
	}
}
int gcd(int a, int b){return !b?a:gcd(b,a%b);}
int main() {
	int g=0;getp(N-1);read(n);rep(i,1,n){
		int x;read(x);a[x]++;g=gcd(g,x);
	}
	if(g>1){puts("-1");return 0;}
	int mx=300000;rep(i,1,300000)for(int j=i;j<=300000;j+=i)cnt[i]+=a[j];
	static int f[N];const int mo=1e9+9;
	rep(i,1,mx)f[i]=cnt[i];
	for(int k=1;;k++){
		int res=0;rep(d,1,mx)if(mu[d])res=(res+1LL*mu[d]*f[d])%mo;
		if(res){printf("%d",k);return 0;}
		rep(i,1,mx)f[i]=1LL*f[i]*cnt[i]%mo;
	}
	return 0;
}