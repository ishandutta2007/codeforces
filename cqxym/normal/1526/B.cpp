#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	int n,m;
	cin>>n;
	for(R i=0;i!=11;i++){
		m=i*111;
		if(m<=n&&(n-m)%11==0){
			cout<<"Yes"<<endl;
			return;
		}
	}
	cout<<"No"<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=t;i!=0;i--){
		Solve();
	}
	return 0;
}