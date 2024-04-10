#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
int gcd(int a,int b){
	if (b==0)return a;
	return gcd(b,a%b);
}
int main(){
	cin>>n>>m;
	if (n==1&&m==1){
		puts("0");
		return 0;
	}
	if (n==1){
		for (int i=1;i<=m;i++)cout<<i+1<<' ';
		cout<<endl;
		return 0;
	}
	if (m==1){
		for (int i=1;i<=n;i++)cout<<i+1<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)cout<<i*(j+n)<<' ';
		cout<<endl;
	}
	return 0;
}