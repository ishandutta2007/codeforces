#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	long long n,m,k;
	cin>>n>>m>>k;
	if(k<n){
		cout<<1+k<<" 1"<<endl;
	}else{
		k-=n;
		cout<<n-k/(m-1)<<" "<<((k/(m-1))&1?m-(k%(m-1)):2+(k%(m-1)))<<endl;
	}
	return 0;
}