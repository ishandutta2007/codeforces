#include<iostream>
using namespace std;
int main(){
	int n;cin>>n;long long U=48,V=30,W=16;
	for(int i=1;i<=n;i++){
		if(i==1)cout<<"2"<<endl;
		if(i==2)cout<<"17"<<endl;
		if(i>=3){
			cout<<U-(i-1)<<endl;
			W+=6;V+=W;U+=V;
		}
	}
	return 0;
}