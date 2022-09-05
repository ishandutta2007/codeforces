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
const int N = 233333;
int n,k,mo,s[N],len;ll res;
void solve(int l, int r, int h){
	if(l>r)return;
	if(h<=1||l==r){s[++len]=r-l+1;return;}
	int mid=(l+r)>>1;
	solve(l,mid,h-1);solve(mid+1,r,h-1);
}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
ll solve(int n, int m){
	ll res=1LL*n*m%mo*power(2,mo-2)%mo;
	rep(c,1,n+m){
		int l=max(1,c-m),r=min(n,c-1);
		if(r-l+1>=1)res=(res-1LL*(r-l+1)*power(c,mo-2))%mo;
	}
	//rep(i,1,n)rep(j,1,m)res=(res+power(2,mo-2)-power(i+j,mo-2))%mo;
	return res;
}
int main() {
	read(n);read(k);read(mo);
	solve(1,n,k);
	sort(s+1,s+len+1);
	rep(i,1,len)res+=1LL*s[i]*(s[i]-1)%mo*power(4,mo-2)%mo;
	static Pii a[N];int tot=0;
	rep(i,1,len)
		if(a[tot].fi==s[i])a[tot].se++;
		else a[++tot]=Pii(s[i],1);
	assert(tot<=2);
	rep(i,1,tot)res+=1LL*a[i].se*(a[i].se-1)/2%mo*solve(a[i].fi,a[i].fi)%mo;
	if(tot==2)res+=1LL*a[1].se*a[2].se%mo*solve(a[1].fi,a[2].fi)%mo;
	//rep(i,1,len)rep(j,i+1,len)res+=solve(s[i],s[j]);
	printf("%lld",(res%mo+mo)%mo);
	return 0;
}