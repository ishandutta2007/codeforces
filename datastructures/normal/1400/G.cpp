#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define inf 1000000000
#define mod 998244353
using namespace std;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p&1)t=t*a%mod;
	return t;
}
int n,m,l[300005],r[300005],a[300005],b[300005];
int ch[300005];
int fac[300005],invfac[300005];
int sum[45][300005],ans;
int C(int n,int m){
	if (m>n||m<0)return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int book[25],qwq[300005];;
void dfs(int now,int fg){
	if (now>m){
		int ml=1,mr=n;
		int cnt=0;
		for (int i=1;i<=m;i++)
			if (book[i]==1){
				ml=max(ml,max(l[a[i]],l[b[i]])),mr=min(mr,min(r[a[i]],r[b[i]]));
				if (qwq[a[i]]==0)cnt++,qwq[a[i]]=1;
				if (qwq[b[i]]==0)cnt++,qwq[b[i]]=1;
			}
		for (int i=1;i<=m;i++)
			if (book[i]==1)qwq[a[i]]=qwq[b[i]]=0;
		if (ml>mr)return;
		ans=((ans+fg*(sum[cnt][mr]-sum[cnt][ml-1]))%mod+mod)%mod;
		return;
	}
	book[now]=1;
	dfs(now+1,-fg);
	book[now]=0;
	dfs(now+1,fg);
	return;
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%lld%lld",&l[i],&r[i]),ch[l[i]]++,ch[r[i]+1]--;
	for (int i=1;i<=m;i++)scanf("%lld%lld",&a[i],&b[i]);
	fac[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	invfac[n]=Qpow(fac[n],mod-2);
	for (int i=n-1;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	for (int i=1;i<=n;i++)ch[i]+=ch[i-1];
	for (int i=0;i<=2*m;i++){
		for (int j=1;j<=n;j++)
			sum[i][j]=(sum[i][j-1]+C(ch[j]-i,j-i))%mod;
	}
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}