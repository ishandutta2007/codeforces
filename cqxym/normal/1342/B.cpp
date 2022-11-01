#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	string s;
	cin>>s;
	int l=s.length();
	bool tag=false;
	for(R i=1;i!=l;i++){
		if(s[i]!=s[i-1]){
			tag=true;
			break;
		}
	}
	if(tag==false){
		cout<<s<<endl;
	}else{
		for(R i=0;i!=l;i++){
			cout<<"01";
		}
		cout<<endl;
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