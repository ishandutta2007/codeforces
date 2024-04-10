#include<iostream>
using namespace std;
int main(){
	int p,a,b;cin>>p>>a>>b;if(a<b)swap(a,b);
	if((a/p==0 && b/p==0) || (a%p!=0 && b/p==0)){cout<<"-1"<<endl;return 0;}
	cout<<a/p+b/p<<endl;
	return 0;
}