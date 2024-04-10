#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	for(R i=0;i!=n;i++){
		if(s[i]=='1'&&t[i]=='1'){
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}