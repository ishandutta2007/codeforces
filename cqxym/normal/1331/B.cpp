#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=sqrt(n);i!=0;i--){
		if(n%i==0){
			cout<<i<<n/i;
			return 0;
		}
	}
}