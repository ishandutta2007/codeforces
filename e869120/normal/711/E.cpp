#include <iostream>
using namespace std;
long long modpow(long long a,long long b,long long m){
	long long p=1,q=a;
	for(int i=0;i<62;i++){
		if((b/(1LL<<i))%2==1){p*=q;p%=m;}
		q*=q;q%=m;
	}
	return p;
}
long long Div(long long a,long long b,long long m){
	return (a*modpow(b,m-2,m))%m;
}
long long factm(long long p){
	long long s=0;
	while(p>=1){p/=2;s+=p;}
	return s;
}
long long n,k,mod=1000003;
int main() {
	cin>>n>>k;if(n<=60 && (1LL<<n)<k){cout<<"1 1"<<endl;return 0;}
	long long B=0;
	if(n<=60){B+=factm((1LL<<n));B-=factm((1LL<<n)-k);}
	else{B+=factm((1LL<<60));B-=factm((1LL<<60)-k);B+=(n-60);}
	
	long long V=modpow(2,n,mod),W=(V-k+1)%mod,ret=1;
	for(int i=0;i<mod;i++){
		long long F=((k-1)-(i-W+mod)%mod+mod)/mod;
		ret*=modpow(i,F,mod);ret%=mod;
	}
	ret=Div(ret,modpow(2,B,mod),mod);
	long long P=(n%(mod-1))*(k%(mod-1));
	long long U=(P-B+(mod-1)*(mod-1)*(mod-1)*4LL)%(mod-1);//cout<<P<<' '<<B<<' '<<U<<endl;
	long long T=modpow(2,U,mod);
	cout<<(T-ret+mod)%mod<<" "<<T<<endl;
	return 0;
}