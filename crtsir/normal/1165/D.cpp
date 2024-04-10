#include<bits/stdc++.h>
using namespace std;
long long n,d[303];
long long gcd(long long x,long long y){
	if(y==0)return x;
	return gcd(y,x%y);
}
bool find(long long x){
	for(int i=0;i<n;i++)
		if(x==d[i])
			return 1;
	return 0;
}
bool check(long long x){
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			if(!find(i)||!find(x/i))
				return 0;
	return 1;
}
bool isprime(int x){
	if(x==1)return 0;if(x==0)return 0;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}
bool strange(){
	if(!isprime(d[0]))return 0;
	for(int i=1;i<n;i++)
		if(d[i]!=d[i-1]*d[0])
			return 0;
	return 1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>d[i];
		sort(d,d+n);
		if(strange()){cout<<1ll*d[n-1]*d[0]<<endl;continue;}
		long long x=1;
		bool can=1;
		for(int i=0;i<n;i++){
			x=x*d[i]/gcd(max(x,d[i]),min(d[i],x));
			if(x>1000000000000){
				cout<<-1<<endl;can=0;
				break;
			}
		}
		if(!can)continue;
		if(check(x)&&x!=d[n-1])
			cout<<x<<endl;
		else
			cout<<-1<<endl;
	}
}