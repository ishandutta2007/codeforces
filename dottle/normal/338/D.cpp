#include<bits/stdc++.h>
#define int long long
#define lxl __int128
const int N=100050;
using namespace std;

int n,m,k,a[N],b[N];
lxl l=1,ans;

lxl mul(lxl a,lxl b,lxl mod){
	return a*b%mod;
}

void exgcd(lxl a,lxl b,lxl& x,lxl &y){
	if(b){
		exgcd(b,a%b,x,y);
		int nw=x;
		x=y,y=nw-a/b*y;
	}else x=1,y=114514;
}

lxl ____gcd(lxl x,lxl y){
	return y?____gcd(y,x%y):x;
}
lxl ____lcm(lxl x,lxl y){
	return x/____gcd(x,y)*y;
}
void ns(){cout<<"NO",exit(0);}

int excrt(){
	lxl x,y,ans=0,M=1,gc,gb,w;
	for(int i=1;i<=k;i++){
		exgcd(M,a[i],x,y),gc=____gcd(M,a[i]),gb=a[i]/gc,w=(b[i]-ans%a[i]+a[i])%a[i];
		x=mul(x,w/gc,gb);
		ans+=x*M,M*=gb;
		ans=(ans%M+M)%M;
	}
	ans=(ans+M-1)%M+1;
	return ans;
}

main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i],l=____lcm(l,a[i]);
		if(l>n)ns();
		b[i]=((-i+1)%a[i]+a[i])%a[i];
	}
	ans=excrt();
	if(ans+k-1>m)ns();
	for(int i=1;i<=k;i++)
		if(____gcd(l,ans+i-1)!=a[i])ns();
	cout<<"YES";
}//