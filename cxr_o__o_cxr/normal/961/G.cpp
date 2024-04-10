#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long 
const int N=2e5+4,mod=1e9+7;
inline int ksm(int x,int r){
	int ret=1;
	for(int i=0;(1<<i)<=r;i++){
		if((1<<i)&r)ret=(ll)ret*x%mod;
		x=(ll)x*x%mod;
	}
	return ret;
} 
int n,k,w=0,fac[N],inv[N];
inline int S(int n,int k){
	int ret=0;
	for(int i=0;i<=k;i++)
		ret=((ll)(i&1?mod-1:1)*inv[i]%mod*ksm(k-i,n)%mod*inv[k-i]%mod+ret)%mod;
	return ret; 
}
int main(){
	n=read();k=read();
	for(int i=1;i<=n;i++)w=(w+read())%mod;
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>1;i--)inv[i]=(ll)inv[i+1]*(i+1)%mod;
	cout<<(ll)w*(((ll)(n-1)*S(n-1,k)+S(n,k))%mod)%mod;
	return (0-0);
}