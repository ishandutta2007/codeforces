#include <iostream>
#include <cstdio>
#define maxn 10000000
#define mod 1000000007
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int isp[10000005],tot,p[2000005],mu[10000005];
int n,a[500005];
int pow_2[500005]; 
int cnt[10000005],val[10000005],f[10000005],ans;
int main(){
	isp[0]=isp[1]=1;
	mu[1]=1;
	for (int i=2;i<=maxn;i++){
		if (isp[i]==0){
			p[++tot]=i;
			mu[i]=-1;
		}
		for (int j=1;j<=tot&&i*p[j]<=maxn;j++){
			isp[i*p[j]]=1;
			if (i%p[j]==0){
				mu[i*p[j]]=0;
				break; 
			}
			mu[i*p[j]]=-mu[i];
		}
	}
	cin>>n;
	pow_2[0]=1;
	for (int i=1;i<=n;i++)pow_2[i]=pow_2[i-1]*2%mod;
	for (int i=1;i<=n;i++)a[i]=read(),cnt[a[i]]++;
	for (int i=1;i<=tot;i++)
		for (int j=maxn/p[i];j>=1;j--)cnt[j]+=cnt[j*p[i]];
	for (int i=1;i<=maxn;i++)val[i]=pow_2[cnt[i]]-1;
	for (int i=1;i<=tot;i++)
		for (int j=1;j<=maxn/p[i];j++)val[j]=(val[j]+mod-val[j*p[i]])%mod;
	for (int i=1;i<=maxn;i++)f[i]=(mod+mu[i]*cnt[i])%mod;
	for (int i=1;i<=tot;i++)
		for (int j=p[i];j<=maxn;j+=p[i])f[j]=(f[j]+f[j/p[i]])%mod;
	for (int i=2;i<=maxn;i++)ans=(ans+1ll*f[i]*val[i])%mod;
	cout<<ans<<endl;	
	return 0;
}