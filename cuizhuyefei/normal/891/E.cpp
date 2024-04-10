#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline int max(int a, int b) {return a>b ? a : b;}
inline int min(int a, int b) {return a<b ? a : b;}
const int N = 5003, mo = 1e9+7;
int n,k,a[N];
int f[N],g[N],xs[N];
inline void exgcd(int a, int b, int &x, int &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
inline int inv(int a) {int x,y; exgcd(a,mo,x,y); return x>=0?x:x+mo;}
int main() {
	read(n); read(k); rep(i,1,n) read(a[i]);
	f[0]=1;
	rep(i,1,n) {
		memcpy(g,f,sizeof(f));
		rep(j,1,n) f[j]=(g[j]+1LL*g[j-1]*a[i])%mo;
	}
	int val=1; rep(i,0,n) {xs[n-i]=val; val=1LL*val*(k-i)%mo;}
	val=1; rep(i,0,n) {xs[n-i]=1LL*xs[n-i]*inv(val)%mo; val=1LL*val*n%mo;}
	int ans=0; rep(i,0,n) {
		int tmp=1LL*f[i]*xs[i]%mo;
		if ((n-i)&1) ans+=mo-tmp; else ans+=tmp; ans%=mo;
	}
	int sum=1; rep(i,1,n) sum=1LL*sum*a[i]%mo;
	printf("%d",(sum-ans+mo)%mo);
	return 0;
}