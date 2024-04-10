#include<bits/stdc++.h>
using namespace std;
long long n;int q;
long long solve(long long n,long long x){
	if(x&1) return (x+1)/2;
	if(n%2==0) return n/2+solve(n/2,x/2);
	else{
		if(x/2==1) return (n+1)/2+solve(n/2,n/2);
		return (n+1)/2+solve(n/2,x/2-1);
	}
}
int main(){
	scanf("%lld %d",&n,&q);
	long long x;
	while(q--){
		scanf("%lld",&x);
		printf("%lld\n",solve(n,x));
	}
	return 0;
}
//142635
//12 8 11 9 13 10
//5 1 4 2 6 3