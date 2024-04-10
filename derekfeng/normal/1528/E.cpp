#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353,i2=499122177,i6=166374059;
int n,f[1000005],g[1000005],s[1000005],ans;
int main(){
	scanf("%d",&n);
	f[0]=s[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=((ll)f[i-1]*(f[i-1]+1)%M*i2+f[i-1])%M;
		if(i>1)(f[i]+=(ll)f[i-1]*s[i-2]%M)%=M;
		s[i]=(s[i-1]+f[i])%M;
		g[i]=(f[i]-f[i-1]+M)%M;
	}
	ans=((ll)f[n-1]*(f[n-1]+1)%M*(f[n-1]+2)%M*i6+f[n])%M;
	if(n>1){
		(ans+=(ll)s[n-2]*(s[n-2]+1)%M*f[n-1]%M*i2%M)%=M;
		(ans+=(ll)f[n-1]*(f[n-1]+1)%M*s[n-2]%M*i2%M)%=M;
	}
	ans=(ans*2%M+M-1)%M;
	for(int i=0;i<n;i++)
		(ans+=(ll)(f[i]+M-1)*g[n-i-1]%M)%=M;
	printf("%d",ans);
}