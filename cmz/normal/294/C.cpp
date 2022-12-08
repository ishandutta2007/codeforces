#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10,mod=1e9+7;
int n,m,cnt;
int a[maxn],top;
int num[maxn],last;
int fac[maxn],ifac[maxn],Two[maxn];
bool judge[maxn];
inline int power(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) res=1ll*res*a%mod;
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i) scanf("%d",&a[i]);
	sort(a+1,a+1+m);
	for (int i=1;i<=m;++i){
		if (a[i]==1){
			last=1;
			continue;
		}
		num[++top]=a[i]-last-1;
		if (last==0) judge[top]=1;
		last=a[i];
	}
	if (a[m]!=n) num[++top]=n-a[m],judge[top]=1;
	Two[0]=1;
	for (int i=1;i<=n;++i) Two[i]=Two[i-1]*2ll%mod;
	fac[0]=fac[1]=1;
	for (int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=power(fac[n],mod-2);
	for (int i=n-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	int ans=fac[n-m];
	for (int i=1;i<=top;++i) ans=1ll*ans*ifac[num[i]]%mod;
	for (int i=1;i<=top;++i) if (num[i]!=0&&!judge[i]) ans=1ll*ans*Two[num[i]-1]%mod;
	printf("%d",ans);
	return 0;
}