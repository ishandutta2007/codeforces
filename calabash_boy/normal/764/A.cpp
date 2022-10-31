#include<iostream>
using namespace std;
long long gcd(long long m,long long n){
	if (m==0) return n;
	return gcd(n%m,m);
}
int main(){
	long long m,n,k;
	cin>>m>>n>>k;
	long long temp=gcd(m,n);
	temp=n*m/temp;
	temp=k/temp;
	cout<<temp;
	return 0;
}