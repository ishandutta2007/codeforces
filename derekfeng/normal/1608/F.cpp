#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
typedef long long ll;
const int M=998244353;
int n,K,b[2003];
int f[105][2003],nf[105][2003],s[105][2003];
int L[2003],R[2003],fc[2003],inv[2003];
int myp(int x,int t){
	int ans=1;
	for(;t;t>>=1,x=(ll)x*x%M)if(t&1)ans=(ll)ans*x%M;
	return ans;
}
int main(){
	fc[0]=inv[0]=1;
	for(int i=1;i<2003;i++)fc[i]=(ll)fc[i-1]*i%M,inv[i]=myp(fc[i],M-2);
	scanf("%d%d",&n,&K);
	b[0]=-K;for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=0;i<=n;i++)L[i]=max(b[i]-K,0),R[i]=b[i]+K;
	f[0][0]=1;
	for(int i=0;i<n;i++){
		memset(nf,0,sizeof(nf));
		memset(s,0,sizeof(s));
		for(int j=L[i];j<=R[i];j++){
			for(int l=0;l<=i;l++)if(f[j-L[i]][l]){
				if(abs(j-b[i])<=K){
					(nf[j-L[i+1]][l+1]+=f[j-L[i]][l])%=M;
					(nf[j-L[i+1]][l]+=(ll)f[j-L[i]][l]*(j+l)%M)%=M;
				}
				if(j+1<=R[i+1])
					(s[max(j+1,L[i+1])-L[i+1]][j+l]+=(ll)fc[l]*f[j-L[i]][l]%M)%=M;
			}
		}
		for(int T=L[i];T<=i;T++)
			for(int j=L[i+1];j<=R[i+1];j++){
				if(j>L[i+1])(s[j-L[i+1]][T]+=s[j-1-L[i+1]][T])%=M;
				(nf[j-L[i+1]][T+1-j]+=(ll)s[j-L[i+1]][T]*inv[T+1-j]%M)%=M;
			}
		memcpy(f,nf,sizeof(nf));
	}
	int ans=0;
	for(int i=L[n];i<=R[n];i++)
		for(int j=0;j<=n;j++)if(j<=n-i)
			(ans+=(ll)f[i-L[n]][j]*fc[n-i]%M*inv[n-i-j]%M)%=M;
	printf("%d",ans);
}