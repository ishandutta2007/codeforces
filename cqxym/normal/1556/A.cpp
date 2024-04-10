#include<iostream>
using namespace std;
int main(){
	int t,a,b;
	cin>>t;
	for(register int i=0;i!=t;i++){
		cin>>a>>b;
		if(a==b){
			if(a==0){
				cout<<0<<endl;
			}else{
				cout<<1<<endl;
			}
		}else if(((a^b)&1)==0){
			cout<<2<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}