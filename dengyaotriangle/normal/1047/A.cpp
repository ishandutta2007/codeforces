#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    if(n%3!=2){
    	cout<<"1 1 "<<n-2;
	}else{
		cout<<"1 2 "<<n-3;
	}
    return 0; 
}