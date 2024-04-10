#include<iostream>
using namespace std;
int n;
bool prime(int p){
	for(int i=2;i*i<=p;i++){
		if(p%i==0)return true;
	}
	return false;
}
int main(){
	cin>>n;
	for(int i=1;i<=100000;i++){
		if(prime(n*i+1)==true){cout<<i<<endl;break;}
	}
	return 0;
}