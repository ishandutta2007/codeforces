#include<iostream>
using namespace std;
int main(){
	int a;
	cin>>a;
	while(a>9){
		int b=0;
		while(a!=0){
			b+=a%10;
			a/=10;
		}
		a=b;
	}
	cout<<a;
	return 0;
}