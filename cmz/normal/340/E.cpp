#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=2e3+10;
int n,sgn,Ans;
int a[maxn],cnt,nq[maxn],tag[maxn],sum;
int fac[maxn],ifac[maxn];
inline int power(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) res=1ll*res*a%mod;
	return res;
}
inline int C(int n,int m){
	if (n<0||m<0||m>n) return 0;
	return 1ll*fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}
inline int A(int n,int m){
	return 1ll*fac[n]*ifac[n-m]%mod;
}
inline void init(){
	fac[0]=1;
	for (int i=1;i<maxn;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[maxn-1]=power(fac[maxn-1],mod-2);
	for (int i=maxn-2;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
}
int main(){
	//freopen(".in","r",stdin);
	init(); scanf("%d",&n); sum=n;
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	fill(nq+1,nq+1+n,1);
	for (int i=1;i<=n;++i) if (a[i]!=-1) nq[a[i]]=0,tag[i]=1,--sum;
	for (int i=1;i<=n;++i)
	if (nq[i]==1&&tag[i]==0) ++cnt;
//	printf("%d %d\n",sum,cnt);
	for (int i=0;i<=cnt;++i){
		sgn=(i%2==0?1:mod-1);
//		printf("sum:%d I:%d sum-i:%d sum-i:%d\n",sum,i,sum-i,sum-i);
		Ans=(Ans+1ll*sgn*C(cnt,i)%mod*A(sum-i,sum-i)%mod)%mod;
//		printf("i:%d Ans:%d\n",i,Ans);
	}
	printf("%d",Ans);
	return 0;
}