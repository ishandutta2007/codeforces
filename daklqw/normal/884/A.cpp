#include <iostream>
using namespace std;
int main(){
	int n,t,tt;
	cin>>n>>t;
	if(t<=0){cout<<0<<endl;return 0;}
	for(int i=1;i<=n;++i){
		cin>>tt;t-=86400-tt;
		if(t<=0){cout<<i<<endl;return 0;}
	}
	
	return 0;
}