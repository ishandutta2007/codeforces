#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	int n,x,y;
	cin>>n>>x;
	bool tag=true;
	for(R i=1;i!=n;i++){
		cin>>y;
		if(x>y){
			tag=false;
		}
		x=y;
	}
	if(tag==true){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}