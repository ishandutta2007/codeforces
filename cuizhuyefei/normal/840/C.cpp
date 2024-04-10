#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 350, mo = 1e9+7;
int n,f[N][N],len,A[N],fac[N],ifac[N],qz[N];
map<int,int> Map;
inline void exgcd(int a, int b, int &x, int &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
inline int inv(int a) {int x,y; exgcd(a,mo,x,y); return x>=0?x:x+mo;}
inline int C(int n, int m) {
	if (m<0||m>n) return 0;
	return 1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo;
}
inline void add(int &a, int b){a=a+b<mo?a+b:a+b-mo;}
int main() {
	read(n); rep(i,1,n) {
		int x;read(x);
		for (register int j=2; j*j<=x; j++) {
			while (x%(j*j)==0) x/=j*j;
		}
		Map[x]++; //printf("<%d>\n",x);
	}
	while (!Map.empty()) {
		A[++len]=(*Map.begin()).se; qz[len]=qz[len-1]+A[len];
		Map.erase(Map.begin());
	}
	fac[0]=1;rep(i,1,n)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=inv(fac[n]); per(i,n-1,0) ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
	f[0][0]=1;
	rep(i,0,len-1) rep(j,0,n+1) if (f[i][j]) {
		int now=f[i][j]; int red=j,blue=qz[i]-j+1;
	//	printf("%d %d %d %d: %d\n",i,j,red,blue,now);
		rep(a,0,blue) per(b,min(red,A[i+1]-a),0) if (a+b<=A[i+1])
			add(f[i+1][j-b+A[i+1]-a-b],1LL*now*C(blue,a)%mo*C(red,b)%mo*C(A[i+1]-1,a+b-1)%mo*fac[A[i+1]]%mo);
	}
	cout<<f[len][0];
	return 0;
}