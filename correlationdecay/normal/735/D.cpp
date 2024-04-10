#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#define maxn 100009
#define PS system("pause");
using namespace std;
bool prime(int n){
	for(long long i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main(){
	int n;
	cin>>n;
	if(prime(n)){
		cout<<1<<endl;
	}
	else if(n%2==0){
		cout<<2<<endl;
	}
	else {
		if(prime(n-2))
			cout<<2<<endl;
		else
			cout<<3<<endl;
	}
	//PS;
	return 0;
}