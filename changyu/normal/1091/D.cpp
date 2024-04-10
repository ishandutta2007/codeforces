#include<cstdio>
const int M=998244353,N=1e6+1;
int n,s,t,r,inv[N],ans;
int main(){
	scanf("%d",&n);
	inv[1]=1;for(int i=2;i<=n;i++)inv[i]=1ll*inv[M%i]*(M-M/i)%M;
	s=1;for(int i=n;i;i--)s=1ll*s*i%M;t=ans=s;
	for(int i=2;i<n;i++)
	  t=1ll*(s-r+M)*inv[i]%M*(i-1)%M,r=(r+t)%M,ans=(ans+1ll*t*(n-i))%M;
	printf("%d",ans);
	return 0; 
}