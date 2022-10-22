#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int mypow(int x,int t){
	int ans=1,res=x;
	while(t){
		if(t&1)ans=(ll)ans*res%M;
		res=(ll)res*res%M,t>>=1;
	}
	return ans;
}
int ifac[200004],inv[200004];
int n,K,x;
void init(){
	ifac[0]=1;
	for(int i=1;i<=n;i++)ifac[i]=(ll)ifac[i-1]*i%M;
	inv[n]=mypow(ifac[n],M-2);
	for(int i=n;i;i--)inv[i-1]=(ll)inv[i]*i%M;
}
int stirling2(int n,int K){
	ll res=0;
	for(int i=0;i<=K;i++)res+=((i&1)?-1ll:1ll)*inv[i]%M*inv[K-i]%M*mypow(K-i,n)%M; 
	return (ll)(res%M+M)%M;
}
int main(){
	scanf("%d%d",&n,&K);
	init();
	int sum=0,val=((ll)(n-1)*stirling2(n-1,K)+stirling2(n,K))%M;
	while(n--)scanf("%d",&x),sum=(sum+x)%M;
	printf("%d",(ll)sum*val%M);
}