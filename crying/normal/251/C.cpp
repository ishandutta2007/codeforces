#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+10;
long long a,b,ans;
int k,lcm=1;
long long f[MAXN];
long long gcd(long long a,long long b){
	if(!b)return a;
	return gcd(b,a%b);
} 
long long work(int a,int b){
	//ba
	memset(f,0,sizeof f);
	for(int i=a+1;i<=b;i++){
		f[i]=1+f[i-1];
		for(int j=2;j<=k;j++){
			if(i-i%j >= a){
				f[i]=min(f[i],1+f[i-i%j]);
			}
		}
	}
	return f[b];
}
int main(){
	scanf("%lld%lld%d",&b,&a,&k);
	for(int i=2;i<=k;i++){
		lcm=lcm/gcd(lcm,i)*i;
	}
	if(a/lcm==b/lcm){
		printf("%lld\n",work(a%lcm,b%lcm));
		return 0;
	}
	ans+=work(0,b%lcm);
	b-=b%lcm;
	ans+=(b/lcm-a/lcm-1)*work(0,lcm);
	b-=(b/lcm-a/lcm-1)*lcm;
	ans+=work(a%lcm,lcm);
	printf("%lld",ans);
	return 0;
}