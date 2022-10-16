#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
using namespace std;
int n,k,sa[200005],rk[200005];
int num;
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
	if (n<m||m<0)return 0;
	register int ans=1;
	for (register int i=1;i<=n;i++)ans=ans*i%mod;
	for (register int i=1;i<=m;i++)ans=ans*inv(i)%mod;
	for (register int i=1;i<=n-m;i++)ans=ans*inv(i)%mod;
	return ans;
}
signed main(){
	cin>>n>>k;
	for (register int i=1;i<=n;i++){
		scanf("%d",&sa[i]);
		sa[i]++;
		rk[sa[i]]=i;
	}
	for (register int i=1;i<n;i++)
		if (rk[sa[i]+1]>rk[sa[i+1]+1])k--;
	cout<<C(n+k-1,k-1)<<endl;
	return 0;
}