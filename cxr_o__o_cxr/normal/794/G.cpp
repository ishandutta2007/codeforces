//starusc
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+4,mod=1e9+7;//*2
inline int ksm(int x,int r){
	int ret=1;
	for(int i=0;(1ll<<i)<=r;i++){
		if((1ll<<i)&r)ret=ret*x%mod;
		x=x*x%mod;
	}
	return ret;
}
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
} 
char c[N],d[N];
int n,m,L,ans=0,p2[N],jie[N],inv[N],p[N],h[N]; 
inline void init(){
	int r=max(n+m,L+1);
	p2[0]=jie[0]=inv[0]=1;
	for(int i=1;i<=r;i++){
		p2[i]=(p2[i-1]<<1)%mod;
		jie[i]=jie[i-1]*i%mod;
	}
	inv[r]=ksm(jie[r],mod-2);
	for(int i=r-1;i>0;i--)
		inv[i]=inv[i+1]*(i+1)%mod;
}
signed main(){
	scanf("%s%s",c+1,d+1);
	n=strlen(c+1);m=strlen(d+1);
	scanf("%lld",&L);
	init();
	int wen=0;
	if(n==m){
		int fl=1,sum=0;
		for(int i=1;i<=L;i++)
			ans=(ans+p2[i])%mod;//01->+ 
		for(int i=1;i<=n;i++){
			if(c[i]!='?'&&d[i]!='?'&&c[i]!=d[i]){fl=0;break;}
			if(c[i]=='?'&&d[i]=='?')sum++;
		}
		if(fl){ans=ans*ans%mod*p2[sum]%mod;wen=p2[sum];}
		else ans=0;// 
	}
	int c1=0,c2=0,a1=0,a2=0,b1=0,b2=0;
	for(int i=1;i<=n;i++){
		if(c[i]=='?')c1++;
		if(c[i]=='A')a1++;
		if(c[i]=='B')b1++;
	}
	for(int i=1;i<=m;i++){
		if(d[i]=='?')c2++;
		if(d[i]=='A')a2++;
		if(d[i]=='B')b2++;
	}
	for(int i=0,v1,v2,e,u,nx,ny;i<=c1+c2;i++){//c1-c2()
		v1=i-c2+a1-a2;v2=i-c1+b2-b1;
		//v1->up(A)-down(A)  v2->down(B)-up(B)  v1*A=v2*B 
		if(!v1&&!v2){// 
			e=(jie[c1+c2]*inv[i]%mod*inv[c1+c2-i]%mod-wen+mod)%mod;//C(c1+c2,i)
			for(int j=1;j<=L;j++)p[j]=(L/j)*(L/j)%mod;
			for(int j=L;j;j--){
				for(int k=(j<<1);k<=L;k+=j)
					p[j]=(p[j]-p[k]+mod)%mod;//
				ans=(ans+p[j]*p2[j]%mod*e)%mod;
			}
			continue;
		} 
		if(v1*v2<=0)continue;
		if(v1<=0){v1=-v1;v2=-v2;}
		e=jie[c1+c2]*inv[i]%mod*inv[c1+c2-i]%mod;
		u=v1*v2/gcd(v1,v2);
		nx=u/v1;ny=u/v2;
		(h[min(L/nx,L/ny)]+=e)%=mod;
	}
	for(int i=1;i<=L;i++)
		ans=(ans+h[i]*(p2[i+1]-2+mod))%mod;
	cout<<ans;
	return (0-0);
}