#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
const int N=2e5+5;
int n,K;
int tot,pri[N],mu[N];
bool flg[N];
void init_mu(){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!flg[i])pri[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&pri[j]*i<=n;j++){
			flg[pri[j]*i]=1;
			if(i%pri[j]==0){mu[pri[j]*i]=0;break;}
			mu[pri[j]*i]=-mu[i];
		}
	}
}
int inv[N];
void init_inv(){
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=(ll)(M-M/i)*inv[M%i]%M;
	for(int i=2;i<=n;i++)inv[i]=(ll)inv[i]*inv[i-1]%M;
}
int myp(int x,int t){
	int ans=1;
	for(;t;x=(ll)x*x%M,t>>=1)if(t&1)ans=(ll)ans*x%M;
	return ans;
}
int s[N],lst,ret;
int ite[N],hwt[N];
int stirling(int t){
	if(lst==t)return ret;
	for(int i=0;i<=t&&i<=K;i++){
		s[i]=i>0?s[i-1]:0;
		ite[i]=(ll)ite[i]*myp(i,t-hwt[i])%M;
		hwt[i]=t;
		(s[i]+=(ll)ite[i]*inv[i]%M)%=M;
	}
	lst=t,ret=0;
	for(int i=0;i<=t&&i<=K;i++){
		int L=max(2-i,0),R=min(K,t)-i;
		int mul=(ll)((i&1)?M-1:1)*inv[i]%M;
		if(L<=R){
			int dt=L==0?s[R]:(s[R]+M-s[L-1])%M;
			(ret+=(ll)dt*mul%M)%=M;
		}
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&K);
	if(min(n,K)<2){puts("1");return 0;}
	init_mu();
	init_inv();
	int ans=0;
	for(int i=1;i<=n;i++)ite[i]=1,hwt[i]=0;
	for(int i=n;i;i--)
		(ans+=(M+mu[i]*stirling((n+i-1)/i))%M)%=M;
	printf("%d",ans);
}