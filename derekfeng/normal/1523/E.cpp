#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7,N=100001;
int mypow(int x,int t){
	int ans=1,res=x;
	while(t){
		if(t&1)ans=(ll)ans*res%M;
		res=(ll)res*res%M,t>>=1;
	}
	return ans;
}
int ifac[N],inv[N],Tc,n,K;
int C(int a,int b){return (ll)ifac[a]*inv[b]%M*inv[a-b]%M;}
int rC(int a,int b){return (ll)inv[a]*ifac[b]%M*ifac[a-b]%M;}
void sol(){
	scanf("%d%d",&n,&K);
	int ans=1;
	for(int i=1;i<=n&&i+(i-1)*(K-1)<=n;i++)
		(ans+=(ll)C(n-(i-1)*(K-1),i)*rC(n,i)%M)%=M;
	printf("%d\n",ans);
}
int main(){
	ifac[0]=1;
	for(int i=1;i<N;i++)ifac[i]=(ll)ifac[i-1]*i%M;
	inv[N-1]=mypow(ifac[N-1],M-2);
	for(int i=N-2;~i;i--)inv[i]=(ll)inv[i+1]*(i+1)%M;
	scanf("%d",&Tc);
	while(Tc--)sol();
}