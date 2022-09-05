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
const int N = 266666;
ll n,res,a[N],k,buc[N];Vi fac[N];
void ini(int n){
	int c=0;
	rep(i,2,n)if(!SZ(fac[i])){
		c++;
		for(int j=i;j<=n;j+=i)fac[j].pb(i);
	}
	cerr<<c<<endl;
//	rep(i,1,20)cerr<<i<<' '<<SZ(fac[i])<<endl;
}
int solve(ll x){
	ll y=1;ll ori=x;
	rep(i,0,SZ(fac[x])-1){
		int c=0;ll tmp=x;
		while(tmp%fac[x][i]==0)tmp/=fac[x][i],c++;
		while(c>=k){c-=k;rep(j,1,k)ori/=fac[x][i];}if(!c)continue;
		for(int j=1;j<=k-c&&y<=1e5;j++)y*=fac[x][i];
	}
//	cerr<<ori<<' '<<y<<endl;
	if(y<=1e5)res+=buc[y];
	return ori;
}
int main() {
	read(n);read(k);rep(i,1,n)read(a[i]);
	ini(1e5);
	rep(i,1,n){
		a[i]=solve(a[i]);
		buc[a[i]]++;
	}
	cout<<res;
	return 0;
}