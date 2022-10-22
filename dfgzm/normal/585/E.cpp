#include<bits/stdc++.h>
#define MOD(x) ((x)=(x)>=mod?(x)-mod:(x))
#define ADD(x) ((x)=(x)<0?(x)+mod:(x))
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=500010,maxs=1e7+5,mod=1e9+7;
int i,j,k,n,m,T,a[maxn];
int prime[maxs],is_prime[maxs],cnt,mu[maxs];
int d[maxs],sum[maxs];
void init(){
	mu[1]=1;
	for(int i=2;i<maxs;i++)is_prime[i]=1;
	for(int i=2;i<maxs;i++){
		if(is_prime[i])prime[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt && prime[j]*i<maxs;j++){
			int w=prime[j]*i;
			is_prime[w]=0;
			if(i%prime[j]==0)break;
			mu[w]=-mu[i];
		}
	}
}
ll ksm(ll sum,int num){
	ll ans=1;
	while(num){
		if(num&1)ans=ans*sum%mod;
		sum=sum*sum%mod;
		num>>=1;
	}
	//cout<<"ans="<<ans<<endl;
	return ans;
}
int main(){
	cin>>n;
	init();
	for(i=1;i<=n;i++)a[i]=read(),d[a[i]]++;
	for(i=1;i<=cnt;i++)
		for(int s=maxs/prime[i],j=s*prime[i];j>=1;j-=prime[i],--s)
			d[s]+=d[j],MOD(d[s]);
	for(i=1;i<maxs;i++)sum[i]=ksm(2,d[i])-1,d[i]=(mod+d[i]*mu[i])%mod;
	//for(i=1;i<=1000;i++)if(d[i])cout<<i<<' '<<d[i]<<' '<<sum[i]<<endl;cout<<endl;
	for(i=1;i<=cnt;i++)
		for(int s=1,j=prime[i];j<maxs;j+=prime[i],++s)
			sum[s]-=sum[j],ADD(sum[s]);
	for(i=1;i<=cnt;i++)
		for(int s=1,j=prime[i];j<maxs;j+=prime[i],++s)
			d[j]+=d[s],MOD(d[j]);
	ll ans=0;
	for(i=2;i<maxs;i++){
	//	if(sum[i])cout<<i<<' '<<sum[i]<<' '<<h[i]<<endl;
		ans+=1ll*sum[i]*d[i]%mod;
		MOD(ans);
	}
	cout<<(ans%mod+mod)%mod<<endl;
	return 0;
}