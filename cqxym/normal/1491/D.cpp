#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	int a,b,s1=0,s2=0;
	cin>>a>>b;
	if(a>b){
		cout<<"NO"<<endl;
		return;
	} 
	for(R i=0;i!=30;i++){
		s1+=a&1;
		a>>=1;
		s2+=b&1;
		b>>=1;
		if(s1<s2){
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}