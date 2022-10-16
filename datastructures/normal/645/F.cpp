#include <iostream>
#include <cstdio>
#include <vector>
#define mod 1000000007
using namespace std;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=1ll*t*t%mod;
	if (p&1)t=1ll*t*a%mod;
	return t;
}
int n,k,q,a[100005],x;
int isp[1000005],tot,p[1000005],phi[1000005];
vector<int> factor[1000005];
int fac[1000005],invfac[1000005];
int cnt[1000005],ans;
int C(int n,int m){
	if (m>n||m<0)return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
void prework(int maxn){
	isp[0]=isp[1]=1;
	phi[1]=1;
	for (int i=2;i<=maxn;i++){
		if (isp[i]==0){
			p[++tot]=i;
			phi[i]=i-1;
		}
		for (int j=1;j<=tot&&i*p[j]<=maxn;j++){
			isp[i*p[j]]=1;
			if (i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
	for (int i=1;i<=maxn;i++)
		for (int j=i;j<=maxn;j+=i)
			factor[j].push_back(i);
	fac[0]=1;
	for (int i=1;i<=maxn;i++)fac[i]=1ll*fac[i-1]*i%mod;
	invfac[maxn]=Qpow(fac[maxn],mod-2);
	for (int i=maxn-1;i>=0;i--)invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	return;
}
void ins(int x){
	for (int i=0;i<(int)factor[x].size();i++){
		int now=factor[x][i];
		ans-=1ll*phi[now]*C(cnt[now],k)%mod;
		cnt[now]++;
		ans+=1ll*phi[now]*C(cnt[now],k)%mod;
		ans=(ans%mod+mod)%mod;
	}
	return;
}
int main(){
	cin>>n>>k>>q;
	prework(1000000);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ins(a[i]);
	}
	while(q--){
		scanf("%d",&x);
		ins(x);
		printf("%d\n",ans);
	}
	return 0;
}