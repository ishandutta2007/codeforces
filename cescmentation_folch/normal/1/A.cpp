#include<iostream>

using namespace std;

int main(){
	long long int n,m,a,resx,resy;
	cin>>n>>m>>a;
	resx = (n+a-1)/a;
	resy = (m+a-1)/a;
	cout<<resx*resy<<endl;
}