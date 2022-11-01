#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long
const int N=5004,mod=1e9+7;
inline int ksm(int x,int r){
	int ret=1;
	for(int i=0;(1ll<<i)<=r;i++){
		if((r>>i)&1)ret=(ll)ret*x%mod;
		x=(ll)x*x%mod;
	}
	return ret;
}
int n,k,ans,a[N];
int main(){
	n=read();k=read();
	a[0]=1;
	for(int i=1,c;i<=n;i++){
		c=read();
		for(int u=i;u;u--)
			a[u]=((ll)a[u]*c-a[u-1])%mod;//
		a[0]=(ll)a[0]*c%mod;
	}
	ans=a[0];
	for(int i=0,fack=1,pwn=1,invn=ksm(n,mod-2);i<=k&&i<=n;i++){
		ans=(ans-(ll)a[i]*fack%mod*pwn)%mod;
		fack=(ll)fack*(k-i)%mod;
		pwn=(ll)pwn*invn%mod;
	}
	cout<<(ans+mod)%mod;
	return (0-0);
}