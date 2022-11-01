//starusc
//https://www.luogu.com.cn/blog/Caro23333/codeforces-round-641-div1d-slime-and-biscuits-zhong-wen-ti-jie 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long
const int N=3e5+4,mod=998244353;
inline int ksm(int x,int r){
	int ret=1;
	for(int i=0;(1ll<<i)<=r;i++){
		if((r>>i)&1)ret=(ll)ret*x%mod;
		x=(ll)x*x%mod; 
	}
	return ret;
}
int n,m,ans,a[N],pk[N],pb[N],f[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();m+=a[i];
	}
	pk[0]=1;pb[0]=n-1;
	for(int i=1,a,b,c,x,iv=ksm((ll)m*(n-1)%mod,mod-2);i<m;i++){
		a=(ll)i*(n-1)%mod*iv%mod;b=(ll)(m-i)*iv%mod;c=((ll)pb[i-1]*a+1)%mod;
		x=((ll)(m-i)*(n-2)%mod*iv+(ll)pk[i-1]*a)%mod;
		x=(1-x+mod)%mod;///
		x=ksm(x,mod-2);
		pk[i]=(ll)b*x%mod;pb[i]=(ll)c*x%mod;
	}
	for(int i=m-1;i>=0;i--){
		f[i]=((ll)f[i+1]*pk[i]+pb[i])%mod;
	}
//	f[0]=n-1;
//	for(int i=1;i<m;i++){
//		f[i]=((ll)m*(n-1)+(ll)i*(n-1)%mod*f[i-1])%mod*ksm(m-i,mod-2)%mod;
//	}
//	for(int i=m-1;i>=0;i--)f[i]=(f[i+1]+f[i])%mod;
	for(int i=1;i<=n;i++){
		ans=(ans+f[a[i]])%mod;
	}
	ans=(ans-(ll)(n-1)*f[0]%mod+mod)%mod;
	cout<<(ll)ans*ksm(n,mod-2)%mod;
	return (0-0);
}