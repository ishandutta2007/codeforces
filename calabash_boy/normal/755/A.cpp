#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int m,n;
	cin>>n;
	if (n==1){
		cout<<3;
		return 0;
	}
	if (n&1==1){
		cout<<"1";
		return 0;
	}else{
		for (int i=2;i<=1000;i++){
			int temp=n*i+1;
			bool pre=1;
			for (int j=2;j<temp;j++){
				if (temp%j==0){
					cout<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}