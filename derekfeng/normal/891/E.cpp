#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int myp(int x,int t){
	int ans=1;
	for(;t;t>>=1,x=(ll)x*x%M)if(t&1)ans=(ll)ans*x%M;
	return ans;
}
int n,K,ans;
int f[5003],nf[5003];
int main(){
	scanf("%d%d",&n,&K);
	f[0]=1;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		memset(nf,0,sizeof(nf));
		for(int j=0;j<i;j++){
			(nf[j+1]+=M-f[j])%=M;
			(nf[j]+=(ll)f[j]*x%M)%=M;
		}
		memcpy(f,nf,sizeof(nf));
	}
	for(int i=0,j=K,mul=1;i<=min(n,K);i++,mul=(ll)mul*j%M,j--)
		(ans+=(ll)f[i]*mul%M*myp(n,j)%M)%=M;
	printf("%d",(f[0]+M-(ll)ans*myp(myp(n,M-2),K)%M)%M);
}