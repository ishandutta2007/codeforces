#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void outputno(){puts("NO");exit(0);}
ll n,m,K,a[10004],Row=1,Col,ai[10004],bi[10004];
ll gcd(ll A,ll B){
	if(B==0)return A;
	return gcd(B,A%B);
}
ll extgcd(ll a,ll b,ll &x,ll &y){
	ll d=a;
	if (b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else x=1,y=0;
	return d;
}
ll mymul(ll a,ll b,ll MOD){
	ll ret=0,ans=a;
	while(b>0){
		if(b&1)b--,ret=(ret+ans)%MOD;
		ans=(ans+ans)%MOD,b>>=1;
	}
	return ret;
}
ll excrt(){
	ll M,ans,X,Y;
	M=bi[0],ans=ai[0];
	for(int i=1;i<K;i++){
		ll A=M,B=bi[i],C=(ai[i]-ans%B+B)%B;
		ll gcd=extgcd(A,B,X,Y);
		X=mymul(X,C/gcd,B/gcd);
		ans+=X*M;
		M*=B/gcd;
		ans=(ans%M+M)%M;
	}
	return ans;
}
int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&K);
	for(int i=0;i<K;i++){
		scanf("%I64d",&a[i]);
		ll Gcd=gcd(Row,a[i]),bg=a[i]/Gcd;
		if(n/bg<Row)outputno();
		Row*=bg;
	}
	for(int i=0;i<K;i++)ai[i]=((-i)%a[i]+a[i])%a[i],bi[i]=a[i];
	Col=excrt();
	if(Col==0)Col=bi[0];
	if(Col+K-1>m)outputno();
	for(int i=0;i<K;i++)if(gcd(Row,Col+i)!=a[i])outputno(); 
	puts("YES");
}