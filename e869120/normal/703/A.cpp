#include<iostream>
using namespace std;
int n,a,b,c,d;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;if(a>b)c++;if(a<b)d++;
	}
	if(c>d)cout<<"Mishka"<<endl;
	if(c<d)cout<<"Chris"<<endl;
	if(c==d)cout<<"Friendship is magic!^^"<<endl;
	return 0;
}