#include<iostream>
using namespace std;
long long n,k;
int main(){
	cin>>n>>k;
	for(int i=1;i<=100;i++){
		if(k%(1LL<<i)!=0){cout<<i<<endl;return 0;}
	}
}