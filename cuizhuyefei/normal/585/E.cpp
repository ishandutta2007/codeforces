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
const int N = 10020000,mo=1e9+7;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
int n,mi[505000],cnt[N],mu[N],prime[N>>2],len;ll res;bool mrk[N];
void getp(int n){
	mu[1]=1;
	rep(i,2,n){
		if(!mrk[i])prime[++len]=i,mu[i]=-1;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=1;
			if(i%prime[j]==0)break;mu[i*prime[j]]=-mu[i];
		}
	}
}
int main() {
	int mx=0;read(n);rep(i,1,n){int x;read(x);cnt[x]++;umax(mx,x);if(x>1)res++;}int sum=n;
	mi[0]=1;rep(i,1,sum)mi[i]=2*mi[i-1]%mo;n=mx;getp(n);
	rep(j,1,len)per(i,n/prime[j],1)cnt[i]+=cnt[i*prime[j]];
	rep(i,2,n)if(mu[i])res=(res+(1LL*mi[cnt[i]]*(sum-cnt[i])-sum)*(-mu[i]))%mo;
	cout<<(res%mo+mo)%mo<<endl;
	return 0;
}