#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p&1)t=t*a%mod;
	return t;
}
int gcd(int a,int b){
	if (b==0)return a;
	return gcd(b,a%b);
}
int t,n,a[1000005],cnt[1000005];
int fac[1000005],invfac[1000005];
int isp[1000005],tot,p[1000005],phi[1000005];
int pos[1000005],len;
int c[1000005];
int work1(int d){
	for (int i=1;i<=len;i++){
		int now=pos[i];
		c[now]=cnt[now]*d/n;
	}
	int ovo=1;
	for (int i=1;i<=len;i++){
		int now=pos[i];
		if (c[now]>1)ovo=ovo*invfac[c[now]]%mod;
	}
	int qwq=fac[d-1]*ovo%mod,awa=fac[d-2]*ovo%mod;
	int ans=0;
	for (int i=1;i<=len;i++){
		int now=pos[i];
		if (c[now]>1){
			ans=(ans+(c[now]-1)*qwq%mod*c[now])%mod;
			ans=(ans+awa*c[now]%mod*(c[now]-1))%mod;
		}
	}
	ans=ans*n/d%mod;
	return ans;
}
int work2(int d){
	for (int i=1;i<=len;i++){
		int now=pos[i];
		c[now]=cnt[now]*d/n;
	}
	int ans=fac[d];
	for (int i=1;i<=len;i++){
		int now=pos[i];
		if (c[now]>0)ans=ans*invfac[c[now]]%mod;
	}
	return ans;
}
signed main(){
	fac[0]=1;
	for (int i=1;i<=1000000;i++)fac[i]=fac[i-1]*i%mod;
	invfac[1000000]=Qpow(fac[1000000],mod-2);
	for (int i=999999;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	isp[0]=isp[1]=1;
	phi[1]=1;
	for (int i=2;i<=1000000;i++){
		if (isp[i]==0){
			p[++tot]=i;
			phi[i]=i-1;
		}
		for (int j=1;j<=tot&&i*p[j]<=1000000;j++){
			isp[i*p[j]]=1;
			if (i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
	cin>>t;
	while(t--){
		n=read();
		for (int i=1;i<=n;i++)a[i]=read(),cnt[a[i]]++;
		len=0;
		for (int i=1;i<=n;i++)
			if (cnt[i]>0)pos[++len]=i;
		int g=0;
		for (int i=1;i<=n;i++)g=gcd(g,cnt[i]);
		if (cnt[a[1]]==n){
			cout<<1<<endl;
			cnt[a[1]]=0;
			continue;
		}
		int sum=0,num=0;
		for (int i=1;i<=n;i++)
			if (n%i==0&&g%(n/i)==0)sum=(sum+work1(i)*phi[n/i])%mod,num=(num+work2(i)*phi[n/i])%mod;
		sum=sum*Qpow(n,mod-2)%mod;
		num=num*Qpow(n,mod-2)%mod;
		cout<<(n+mod-sum*Qpow(num,mod-2)%mod)%mod<<endl;
		for (int i=1;i<=n;i++)cnt[a[i]]=0;
	}
	return 0;
}