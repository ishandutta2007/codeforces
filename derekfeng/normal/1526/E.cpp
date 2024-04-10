#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int inv[200004],ifac[200004],n,K;
int mypow(int x,int t){
	int ans=1,res=x;
	while(t){
		if(t&1)ans=(ll)ans*res%M;
		res=(ll)res*res%M,t>>=1;
	}
	return ans;
}
void init(){
	int N=max(n,K);
	ifac[0]=1;
	for(int i=1;i<=N;i++)ifac[i]=(ll)ifac[i-1]*i%M;
	inv[N]=mypow(ifac[N],M-2);
	for(int i=N-1;~i;i--)inv[i]=(ll)inv[i+1]*(i+1)%M;
}
int C(int n,int m){
	return (ll)ifac[m]*inv[n]%M*inv[m-n]%M;
}
int sa[200004],pos[200004],cnt=0,ans;
int main(){
	scanf("%d%d",&n,&K);
	init();
	for(int i=0;i<n;i++)scanf("%d",&sa[i]),pos[sa[i]]=i;
	pos[n]=-1;
	for(int i=0;i<n-1;i++)if(pos[sa[i]+1]>pos[sa[i+1]+1])cnt++;
	for(int i=cnt+1;i<=min(n,K);i++){
		int res=(ll)C(i-cnt-1,n-1-cnt)*C(i,K)%M;
		(ans+=res)%=M;
	}
	printf("%d",ans);
}