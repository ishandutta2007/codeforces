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
const int N = 1020000, mo = 998244353;
int n,fac[N],ifac[N]; ll res;
int power(int a, int n){
	int res=1;
	while (n){
		if(n&1)res=1LL*res*a%mo;
		a=1LL*a*a%mo;
		n>>=1;
	}
	return res;
}
inline int inv(int a){return power(a,mo-2);}
int C(int n, int m){
	return m<0||m>n?0:1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo;
}
int main() { //freopen("1.in","r",stdin);
	read(n);fac[0]=1;rep(i,1,n)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=inv(fac[n]);per(i,n-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
	rep(i,1,n)res+=2LL*C(n,i)*power(3,(i+1LL*n*(n-i))%(mo-1))%mo*(i%2?1:-1);
//	rep(i,0,5)printf("%d: %d %d\n",i,fac[i],ifac[i]);
//	rep(i,0,5)rep(j,0,i)printf("%d %d : %d\n",i,j,C(i,j));
	rep(i,1,n){
		ll x=3LL*C(n,i)*(i%2?1:-1)%mo;
		ll y=power(power(3,n-i)-1,n)-power(3,1LL*n*(n-i)%(mo-1));
	//	ll y=0; 
	//	rep(j,1,n)y+=(j%2?-1:1)*1LL*C(n,j)*power(3,1LL*(n-i)*(n-j)%(mo-1))%mo;
	//	y-=power(3,1LL*n*(n-i)%(mo-1));
		y%=mo;res+=x*y%mo;
	}
	cout<<(res%mo+mo)%mo;
	return 0;
}