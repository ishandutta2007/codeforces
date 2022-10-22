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
int n,ans;
int ifac[1000004],inv[1000004];
int C(int a,int b){
	return a>b?0:(ll)ifac[b]*inv[a]%M*inv[b-a]%M;
}
int main(){
	scanf("%d",&n);
	ifac[0]=1;
	for(int i=1;i<=n;i++)ifac[i]=(ll)ifac[i-1]*i%M;
	inv[n]=mypow(ifac[n],M-2);
	for(int i=n-1;~i;i--)inv[i]=(ll)inv[i+1]*(i+1)%M;
	for(int i=2;i<=n;i+=2)(ans+=(ll)ifac[i]*(C(n-i,i)+C(n-i-1,i-1))%M)%=M;
	printf("%d",(ans+ans)%M);
}