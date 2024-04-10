#include<bits/stdc++.h>
#define int long long
const int N=100050; 
using namespace std;

int mx[N],n,ans,s=1,sum;

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

main(){
	scanf("%lld",&n);
	for(int i=1;i<n;i++)
		if(gcd(i,n)==1)
			s=s*i%n,sum++;
	printf("%lld\n",sum-(s!=1));
	for(int i=1;i<n;i++)
		if(gcd(i,n)==1&&(i==1||i!=s))
			printf("%lld ",i);
}