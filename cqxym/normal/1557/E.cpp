#include<iostream>
using namespace std;
inline void Solve(){
	cout<<"1 8"<<endl;
	string opt;
	cin>>opt;
	if(opt=="Done"){
		return;
	}
	cout<<"1 1"<<endl;
	int x=1,y=1;
	bool tag=true;
	while(true){
		cin>>opt;
		if(opt=="Done"){
			return;
		}
		if(opt.find("Down")!=string::npos){
			x++;
			tag=false;
		}else if(tag==false){
			y=1;
		}else if(opt.find("Up")!=string::npos){
			if(y==1){
				y=2;
				tag=false;
			}else{
				y=1;
			}
		}else if(y==8){
			x++;
			tag=false;
		}else{
			y++;
		}
		if(y==1){
			tag=true;
		}
		cout<<x<<' '<<y<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	for(register int i=0;i!=t;i++){
		Solve();
	}
	return 0;
}