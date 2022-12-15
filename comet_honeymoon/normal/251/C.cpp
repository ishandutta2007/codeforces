#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll A,B,K;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}
ll L;
ll F[400000];
ll Solve(ll a,ll b){
	memset(F,63,sizeof(F));
	F[a]=0;
	for(ll i=a;i>b;i--){
		F[i-1]=min(F[i-1],F[i]+1);
		for(ll x=2;x<=K;x++)
			F[i-i%x]=min(F[i-i%x],F[i]+1);
	}
	return F[b];
}

int main(){
	scanf("%lld%lld%lld",&A,&B,&K);
	L=1;
	for(ll i=1;i<=K;i++) L=lcm(L,i);
	if(A/L==B/L) printf("%lld\n",Solve(A%L,B%L));
	else printf("%lld\n",Solve(A%L,0)+Solve(L,0)*(A/L-B/L-1)+Solve(L,B%L));
}