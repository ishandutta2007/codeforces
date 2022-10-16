#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
using namespace std;
int n,s,a[25],invfac[105];
inline int Qpow(register int a,register int p){
	if (p==0)return 1;
	register int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
inline int inv(register int x){
	return Qpow(x,mod-2);
} 
inline int C(register int n,register int m){
	register int ans=invfac[m];
	for (register int i=n-m+1;i<=n;i++)ans=i%mod*ans%mod;
	return ans;
}
inline int dfs(register int now,register int fg,register int nows){
	if (nows<0)return 0;
	if (now==n+1)return (fg*C(nows+n-1,n-1)%mod+mod)%mod;
	return (dfs(now+1,fg,nows)+dfs(now+1,-fg,nows-a[now]-1))%mod;
}
signed main(){
	cin>>n>>s;
	for (register int i=1;i<=n;i++)cin>>a[i];
	invfac[0]=1;
	for (register int i=1;i<=100;i++)invfac[i]=invfac[i-1]*inv(i)%mod;
	cout<<dfs(1,1,s)<<endl;
	return 0;
}