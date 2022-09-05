#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 1000500, mo = 1e9+7;
int n,k,y[N],fac[N],ifac[N],qz[N],hz[N];
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo;
		n>>=1;
	}
	return res;
}
inline int inv(int a) {return power(a,mo-2);}
int main() {
	read(n); read(k);
	rep(i,1,k+2) y[i]=(y[i-1]+power(i,k))%mo;
	fac[0]=1; rep(i,1,k+2) fac[i]=1LL*fac[i-1]*i%mo;
	ifac[0]=1; rep(i,1,k+2) {ifac[i]=-1LL*ifac[i-1]*i%mo; ifac[i]+=ifac[i]<0?mo:0;}
	qz[0]=1; rep(i,1,k+2) {qz[i]=1LL*qz[i-1]*(n-i)%mo; qz[i]+=qz[i]<0?mo:0;}
	hz[k+3]=1; per(i,k+2,1) {hz[i]=1LL*hz[i+1]*(n-i)%mo; hz[i]+=hz[i]<0?mo:0;}
	ll res=0;
	rep(i,1,k+2) res+=1LL*y[i]*qz[i-1]%mo*hz[i+1]%mo*inv(1LL*fac[i-1]*ifac[k+2-i]%mo)%mo;
	cout<<res%mo;
	return 0;
}