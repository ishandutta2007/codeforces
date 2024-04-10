#include<bits/stdc++.h>
using namespace std;
long long ans1,ans2,ans3;
long long input,k;
int main(){
	cin>>input>>k;
	long long	temp = (input/2)/(k+1)*(k+1);
//	cout<<temp<<endl;
	while ((temp*2)<=input){
		temp+=k+1;
	//	cout<<"+"<<temp<<endl;
	}
	while ((temp*2)>input){
		temp-=(k+1);
	//	cout<<"-"<<temp<<endl;
	}
	cout<<temp/(k+1)<<" "<<temp/(k+1)*k<<" "<<input-temp<<endl;
	return 0;
}