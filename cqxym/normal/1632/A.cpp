#include<iostream>
using namespace std;
#define R register int
int main(){
	int t,n;
	cin>>t;
	for(R i=0;i!=t;i++){
		cin>>n;
		string s;
		cin>>s;
		if(n==1||n==2&&(s=="01"||s=="10")){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	return 0;
}